#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QVector>
#include "college.h"

//! The DatabaseManager
/*!
  The SQL Manager class should have functions that are passed
  vectors of data, convert the vectors to SQLite queries,
  and then execute those queries on the SQLite database,
  which is a private, static, data member of this class.
*/

class DatabaseManager
{
private:
    DatabaseManager();                                     //!< Private constructor
    static DatabaseManager* managerInstance;               //!< The database manager
    QSqlDatabase DBInstance;                          //!< The database itself

public:
    //! Initializes the database
    void initDB();

    //! To get a pointer to the database manager
    /*!
     * \brief getInstance Used whenever we want to
     * get a pointer to the database manager class
     * (this class), we call this function.
     * \return A pointer to the database
     */
    static DatabaseManager* getInstance();

    //! A function to get every college in database
    /*!
     * \brief getAllColleges Will traverse through database.
     * \return A vector of all colleges and their menu items
     */
    QVector<College> getAllColleges();

    //! To find a college's menu by ID
    /*!
     * \brief getMenuItemsByCollegeID Will take in the college's
     * ID and search for its menu.
     * \param collegeID An integer argument
     * \return MenuItem vector for the specified restuarantID
     */
    QVector<souvenirItem> getMenuItemsByCollegeID(int collegeID);

    //! To get a college by ID
    /*!
     * \brief getCollegeByID The function will search for the college
     * with the ID of the argument that is passed in.
     * \param college_ID
     * \return The college associated with the specified college_ID
     */
    College getCollegeByID(int college_ID);

    //! A function to verify login request of admin
    /*!
     * \brief authenticateAdminLoginRequest Will take the username and
     * password entered and compare it to the key stored to verify access.
     * \param username A qstring argument
     * \param passsword A qstring argument
     * \return A boolean that is true if the entered information is identical
     */
    bool authenticateAdminLoginRequest(QString username, QString passsword);

    //! To get the colleges to other colleges
    /*!
     * \brief getDistancesFrom Will take in the colleges ID
     * and match it with is corresponding distances list and return
     * it for use.
     * \param sourceCollege_ID An integer argument
     * \return A qvector of the distances of that college
     */
    QVector<Distance> getDistancesFrom(int sourceCollege_ID);

    //! Get the number of colleges in database
    /*!
     * \brief getNumberOfColleges Will count the number of colleges
     * \return An integer of the size of database/colleges in list
     */
    int getNumberOfColleges();

    //! To get a college's menu item's details
    /*!
     * \brief getMenuItemByID Will take the menu item's ID
     * and find its other corresponding details.
     * \param menuItem_ID An integer argument
     * \return A struct of the menu items information
     */
    souvenirItem getMenuItemByID(int menuItem_ID);

    //! To be able to add a new college to the database
    /*!
     * \brief addCollege Will need the college information and
     * distances to others to add it to the database.
     * \param college A struct argument
     * \param distances A qvector argument
     */
    void addCollege(College college, QVector<Distance> distances);

    //! To modify a menu item
    /*!
     * \brief modifyMenuItem Will allow to change a menu items
     * price.
     * \param newMenuItem A struct argument
     */
    void modifyMenuItem(souvenirItem newMenuItem);

    //! To add a menu item to college
    /*!
     * \brief addMenuItem Will take in the new menu item and the
     * college to add to and place it at the bottom of items.
     * \param newMenuItem A struct argument
     * \param toAddTo A struct argument
     */
    void addMenuItem(souvenirItem newMenuItem, College toAddTo);

    //! To delete a menu item from college
    /*!
     * \brief deleteMenuItem Will take in the menu item to delete
     * and remove it from the list.
     * \param newMenuItem A struct argument.
     */
    void deleteMenuItem(souvenirItem newMenuItem);
};
#endif // DATABASEMANAGER_H
