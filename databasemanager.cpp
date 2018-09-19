#include "databasemanager.h"
#include <fstream>
/**********************************************************
 *
 * The SQL Manager class should have functions that will
 * either pass data in vectors, or return data in vectors,
 * including converting passed vectors into SQLite queries,
 * and vice versa.
 *
**********************************************************/

// Sets the static data member to NULL.
DatabaseManager* DatabaseManager::managerInstance = nullptr;

DatabaseManager* DatabaseManager::getInstance()
{
    if (managerInstance == nullptr)
    {
        // Should only be executed once per runtime
        managerInstance = new DatabaseManager();
    }
    return managerInstance;
}


DatabaseManager::DatabaseManager()
{
    DBInstance = QSqlDatabase::addDatabase("QSQLITE");
    DBInstance.setDatabaseName("colleges.db");

    // Check if the database is opened, log to console the result
    if (!DBInstance.open())
    {
        qDebug() << "ERROR: Connection to database failed.";
    }
    else
    {
        qDebug() << "Connection to database successful.";
        initDB();
    }
}
// Called once on program start,
void DatabaseManager::initDB()
{
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS colleges   (ID INTEGER PRIMARY KEY, Name VARCHAR(35), DistanceToSaddleback REAL)");
    query.exec("CREATE TABLE IF NOT EXISTS menu_items (ID INTEGER PRIMARY KEY, College_ID integer, Name VARCHAR(35), Price REAL)");
    query.exec("CREATE TABLE IF NOT EXISTS distances (CollegeA_ID integer, CollegeB_ID integer, DistanceBetween REAL)");
    query.exec("CREATE TABLE IF NOT EXISTS admins ( name VARCHAR(12), password VARCHAR(12) )");
}

int DatabaseManager::getNumberOfColleges() {
    // simply returns an integer representing the total number of the colleges in the db
    QSqlQuery query;
    query.exec("SELECT Name FROM colleges");
    int numOfColleges = 0;
    if (query.exec())
    {
        if(query.first())
        {
            while (query.isValid())
            {
                numOfColleges++;
                query.next();
            }
        }
    }
    return numOfColleges;
}

QVector<College> DatabaseManager::getAllColleges()
{
    QSqlQuery query;
    query.prepare("SELECT ID, Name, DistanceToSaddleback FROM colleges");
    QVector<College> colleges;

    // Collects college and menuItem data into one single colleges vector
    if (query.exec())
    {
        if(query.first())
        {
            while (query.isValid())
            {
                College newCollege;
                newCollege.id = query.value(0).toInt();
                newCollege.name = query.value(1).toString();
                newCollege.distanceToSaddleback = query.value(2).toDouble();

                QVector<MenuItem> menuItems = this->getMenuItemsByCollegeID(newCollege.id);

                // Set the current college's menuItems vector
                newCollege.menuItems = menuItems;

                colleges.push_back(newCollege);
                query.next();
            }
        }
    }
    return colleges;
}

// Helper function for InitializeCollegesWithMenus() function above
QVector<MenuItem> DatabaseManager::getMenuItemsByCollegeID(int collegeID)
{
    QVector<MenuItem> menuItems;
    QSqlQuery query;

    query.prepare("SELECT Name, Price, id FROM Menu_Items WHERE College_ID=:college_ID");
    query.bindValue(":college_ID", collegeID);

    if (query.exec())
    {
        if (query.first())
        {
            while(query.isValid())
            {
                MenuItem tempMenuItem;
                tempMenuItem.name = query.value(0).toString();
                tempMenuItem.price = query.value(1).toDouble();
                tempMenuItem.id = query.value(2).toInt();
                menuItems.push_back(tempMenuItem);
                query.next();
            }
        }
    }
    return menuItems;
}

College DatabaseManager::getCollegeByID(int college_ID) {
    QSqlQuery query;
    query.prepare("SELECT id, Name, DistanceToSaddleback FROM colleges WHERE id=:college_ID");
    query.bindValue(":college_ID", college_ID);

    if(query.exec()) {
        if (query.first()) {
            College returnCollege;
            returnCollege.id = query.value(0).toInt();
            returnCollege.name = query.value(1).toString();
            returnCollege.menuItems = getMenuItemsByCollegeID(returnCollege.id);
            returnCollege.distanceToSaddleback = query.value(2).toDouble();

            return returnCollege;
        }
    }

}

MenuItem DatabaseManager::getMenuItemByID(int menuItem_ID) {
    QSqlQuery query;
    query.prepare("SELECT id, Name, Price FROM menu_items WHERE id=:menuItem_ID");
    query.bindValue(":menuItem_ID", menuItem_ID);

    if(query.exec()) {
        if (query.first()) {
            MenuItem returnItem;
            returnItem.id = query.value(0).toInt();
            returnItem.name = query.value(1).toString();
            returnItem.price = query.value(2).toDouble();

            return returnItem;
        }
    }

}


bool DatabaseManager::authenticateAdminLoginRequest(QString name, QString password)
{
    bool isAdmin = false;
    QSqlQuery query;
    query.prepare("SELECT name, password FROM admins WHERE lower(name)=lower(:name)");
    query.bindValue(":name", name);
    query.bindValue(":password", password);

    if (query.exec())
    {
        if (query.first())
        {
            if (query.value(1).toString().toLower() == password.toLower())
            {
                // the username and password inputted is an admin account
                isAdmin = true;
            }
        }
    } else {
        isAdmin = false;
    }

    return isAdmin;
}

void DatabaseManager::addCollege(College college, QVector<Distance> distances)
{
    QSqlQuery query;
    QSqlQuery menuItemsQuery;
    for (int index=0; index < distances.size(); index++)
    {
        //qDebug() << "Distance from: " << distances[index].destinationCollege_ID << " to: " << college.id;
    }
    // Adds the college name, ID, and distanceToSaddleback to colleges table in database
    query.prepare("INSERT INTO colleges (id, name, distanceToSaddleback) VALUES(:id, :name, :distanceToSaddleback)");
    query.bindValue(":id", college.id);
    query.bindValue(":distanceToSaddleback", college.distanceToSaddleback);
    query.bindValue(":name", college.name);
    if (query.exec())
    {

    }

    // Adds all the colleges menu items to the menu_items table
    for (int index=0; index < college.menuItems.size(); index++)
    {
        menuItemsQuery.prepare("INSERT INTO menu_items (Name, Price, College_ID) VALUES(:name, :price, :college_ID)");
        menuItemsQuery.bindValue(":name", college.menuItems[index].name);
        menuItemsQuery.bindValue(":price", college.menuItems[index].price);
        menuItemsQuery.bindValue(":college_ID", college.id);
        menuItemsQuery.exec();
    }

    // Add distances for the college being added
    for (int index=0; index < distances.size(); index++)
    {

        query.prepare("INSERT INTO distances (CollegeA_ID, CollegeB_ID, DistanceBetween) VALUES(:CollegeA_ID, :CollegeB_ID, :DistanceBetween)");
        query.bindValue(":CollegeA_ID", college.id);
        //query.bindValue(":CollegeB_ID", distances[index].destinationCollege_ID);
        query.bindValue(":DistanceBetween", distances[index].distanceTo);
        //qDebug() << "Inserting distance from " << college.id << " to: " << distances[index].destinationCollege_ID;
        query.exec();

        query.prepare("INSERT INTO distances (CollegeA_ID, CollegeB_ID, DistanceBetween) VALUES(:CollegeA_ID, :CollegeB_ID, :DistanceBetween)");
        //query.bindValue(":CollegeA_ID", distances[index].destinationCollege_ID);
        query.bindValue(":CollegeB_ID", college.id);
        //query.bindValue(":DistanceBetween", distances[index].distanceTo);
        //qDebug() << "Inserting distance from " << distances[index].destinationCollege_ID<< " to: " << college.id;
        query.exec();
    }

}
void DatabaseManager::addMenuItem(MenuItem newMenuItem, College toAddTo)
{
    QSqlQuery menuItemsQuery;
    menuItemsQuery.prepare("INSERT INTO menu_items (Name, Price, College_ID) VALUES(:name, :price, :college_ID)");
    menuItemsQuery.bindValue(":name", newMenuItem.name);
    menuItemsQuery.bindValue(":price", newMenuItem.price);
    menuItemsQuery.bindValue(":college_ID", toAddTo.id);
    if (menuItemsQuery.exec())
    {
    }
}
void DatabaseManager::modifyMenuItem(MenuItem newMenuItem)
{
    // newMenuItem still has the same id as our old menu item :)
    QSqlQuery query;
    query.prepare("UPDATE menu_items SET name=:name, price=:price WHERE id=:oldID");
    query.bindValue(":name", newMenuItem.name);
    query.bindValue(":price", newMenuItem.price);
    query.bindValue(":oldID", newMenuItem.id);
    if (query.exec())
    {

    }
}
void DatabaseManager::deleteMenuItem(MenuItem newMenuItem)
{
    // newMenuItem still has the same id as our old menu item :)
    QSqlQuery query;
    query.prepare("DELETE FROM menu_items WHERE id=:ID");
    query.bindValue(":ID", newMenuItem.id);
    if (query.exec())
    {
        qDebug() << "Im #1!!";
    }
}
QVector<Distance> DatabaseManager::getDistancesFrom(int sourceCollege_ID)
{
    QSqlQuery query;
    QVector<Distance> distances;
    query.prepare("SELECT CollegeB_ID, DistanceBetween FROM distances WHERE CollegeA_ID=:sourceCollege_ID ORDER BY DistanceBetween ASC");
    query.bindValue(":sourceCollege_ID", sourceCollege_ID);

    if (query.exec())
    {
        if (query.first())
        {
            while (query.isValid())
            {
                Distance tempDistance;
                tempDistance.destinationCollege_ID = query.value(0).toInt();
                tempDistance.distanceTo = query.value(1).toDouble();

                distances.push_back(tempDistance);
                query.next();
            }
        }
    }
    return distances;
}
