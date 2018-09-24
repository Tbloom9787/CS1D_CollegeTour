#include "collegemodel.h"
#include "ui_collegemodel.h"
#include "QInputDialog"
#include <QMessageBox>

CollegeModel::CollegeModel(College collegeClicked, bool startingFromSaddleback, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CollegeModel)
{
    ui->setupUi(this);
    if (startingFromSaddleback)
    {
        ui->totalTripDistanceLabel->setText("Total Trip Distance: " + QString::number(collegeClicked.distanceToSaddleback, 'f', 2) + " miles");
        totalDistance = collegeClicked.distanceToSaddleback;
    } else {

        totalDistance = 0;
    }

    // Display the name of the next closest college in the text of the UI button.
    QVector<Distance> distances = DatabaseManager::getInstance()->getDistancesFrom(collegeClicked.id);
    College nextClosest = DatabaseManager::getInstance()->getCollegeByID(distances[0].destinationCollege_ID);
    ui->nextClosestCollegeButton->setText("Next Closest College\n(" + nextClosest.name + ")");

    qDebug() << "College Clicked: " << collegeClicked.name;
    // All the data affiliated with the college that was clicked.
    this->collegeClicked = collegeClicked;
    populateMenuItemDisplay(collegeClicked.id);
    QListWidgetItem* newLabel = new QListWidgetItem(collegeClicked.name);
    newLabel->setBackgroundColor(Qt::red);
    newLabel->setFlags(newLabel->flags() & ~Qt::ItemIsSelectable);
    ui->cartListWidget->addItem(newLabel);
}

CollegeModel::~CollegeModel()
{
    delete ui;
}

void CollegeModel::updateShoppingCart(souvenirItem item)
{
    QListWidgetItem* newItem = new QListWidgetItem;
    newItem->setData(Qt::UserRole, item.id);
    newItem->setData(128, collegeClicked.id);
    newItem->setText(" °  " + item.name + " - $" + QString::number(item.price));
    qDebug() << newItem->data(Qt::UserRole).toInt();
    ui->cartListWidget->addItem(newItem);
}

void CollegeModel::populateMenuItemDisplay(int collegeID)
{
    clearWidgets(ui->menuGridLayout);
    College currentCollege = DatabaseManager::getInstance()->getCollegeByID(collegeID);
    QVector<souvenirItem> menuItems = currentCollege.souvenirItems;

    // Set up labels
    QString distanceLabel = QString::number(currentCollege.distanceToSaddleback);
    ui->collegeNameLabel->setText(currentCollege.name);
    this->setWindowTitle("Viewing College: " + currentCollege.name);
    ui->totalTripDistanceLabel->setText("Distance to saddleback: " + distanceLabel + " miles");

    qDebug() << "menu items: " << menuItems.size();
    // Populates the menu item buttons on menuGridLayout
    if (menuItems.size() > 0)
    {
        int row = 0;
        int col = 0;
        for (int menuItemIndex=0; menuItemIndex < menuItems.size(); menuItemIndex++)
        {
            if (col == 5)
            {
                row++;
                col = 0;
            }
            QPushButton* menuItemButton = new QPushButton(menuItems[menuItemIndex].name + "\n$ " + QString::number(menuItems[menuItemIndex].price));
            menuItemButton->setMaximumHeight(200);

            menuItemButton->setObjectName(QString::number(menuItems[menuItemIndex].id));

            connect(menuItemButton, SIGNAL(clicked()), this, SLOT(menuItemButtonPressed()));

            menuItemButton->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
            ui->menuGridLayout->addWidget(menuItemButton, row, col);
            col++;
        }
    }
    this->collegeClicked = currentCollege;
}

void CollegeModel::menuItemButtonPressed()
{
    // Get the QPushButton object that was clicked
    QPushButton *clickedMenuItemButton = qobject_cast<QPushButton*>(sender());
    // get the ID of menuItem clicked
    int clickedMenuItemID = clickedMenuItemButton->objectName().toInt();

    // Get menu item data from database using the ID
    souvenirItem clickedMenuItem = DatabaseManager::getInstance()->getMenuItemByID(clickedMenuItemID);

    // Prompt the user to confirm their purchase
    confirmPurchase(clickedMenuItem);
}

void CollegeModel::confirmPurchase(souvenirItem item)
{
    QMessageBox::StandardButton confirm;
    confirm = QMessageBox::question(this, "Confirm Purchase", "Are you sure you want to purchase this item?",
                                    QMessageBox::Yes|QMessageBox::No);
    if (confirm == QMessageBox::Yes) {
        // Add the menu item to the shopping cart, and update the UI!
        shoppingCart.addTransaction(collegeClicked, item);
        updateShoppingCart(item);
    } else {
        // Do nothing
    }

}
void CollegeModel::clearWidgets(QLayout * layout) {
    if (! layout)
        return;
    while (auto item = layout->takeAt(0)) {
        delete item->widget();
        clearWidgets(item->layout());
    }
}

void CollegeModel::getTripLengthFromUser()
{
    bool ok;
    // get user input as soon as the CollegeModel is instantiated from mainmenu.cpp button click event
    int numOfCollegesInput = QInputDialog::getInt(this, tr("Number of College Campus Stops"),
                                                     tr("Please enter the total number of colleges you wish to visit:"), 1, 0, DatabaseManager::getInstance()->getNumberOfColleges(), 1, &ok);
    if (ok) // save the user's input for later use
    {
        this->numberOfCollegesToVisit = numOfCollegesInput;
        if (this->numberOfCollegesToVisit == 1)
        {
            ui->nextClosestCollegeButton->setText("End Trip (Checkout)");
        }
    } else {
        // The user did not specify a number of colleges to visit, so close the restuarant view window.
        this->close();
    }
}

void CollegeModel::recursivePathPlanner(College currentCollege, QVector<College>& mostEffecientList)
{
    qDebug() << currentCollege.name;
    mostEffecientList.push_back(currentCollege);
    // cut off the algorithm once we have calculated only the number of restuarants the user wants to visit, nothing more
    if (mostEffecientList.size() == this->numberOfCollegesToVisit)
    {
        return;
    } else {
        QVector<Distance> distances = DatabaseManager::getInstance()->getDistancesFrom(currentCollege.id);

        College nextClosest = DatabaseManager::getInstance()->getCollegeByID(distances.at(0).destinationCollege_ID);
        qDebug() << "Next closest: " << nextClosest.name;
        int index = 1;
        if (vectorContains(mostEffecientList, nextClosest))
        {
            while(vectorContains(mostEffecientList, nextClosest))
            {
                nextClosest = DatabaseManager::getInstance()->getCollegeByID(distances.at(index).destinationCollege_ID);
                index++;
            }
            totalDistance += distances.at(index-1).distanceTo;
            qDebug() << "Adding distance from " << currentCollege.name << " to: " << DatabaseManager::getInstance()->getCollegeByID(distances.at(index).destinationCollege_ID).name;
        } else {
            totalDistance += distances.at(0).distanceTo;
            qDebug() << "Adding distance 0 from " << currentCollege.name << " to: " << DatabaseManager::getInstance()->getCollegeByID(distances.at(0).destinationCollege_ID).name;
        }
        totalDistancesIndexed.push_back(totalDistance);

        recursivePathPlanner(nextClosest, mostEffecientList);
    }
}

void CollegeModel::on_nextClosestCollegeButton_clicked()
{
    if (numberOfCollegesToVisit == 1)
    {
        this->close();
    } else if (numberOfCollegesToVisit != 1)
    {
        if (mostEffecientTrip.size() == 0)
        {
            QVector<Distance> distances = DatabaseManager::getInstance()->getDistancesFrom(collegeClicked.id);
            College nextClosest = DatabaseManager::getInstance()->getCollegeByID(distances.at(0).destinationCollege_ID);

            qDebug() << "Distances: " << distances.size();
            if (numberOfCollegesToVisit == 2)
            {
                // Handles the case when the user only wants to visit the initial college and one college after!
                populateMenuItemDisplay(distances.at(0).destinationCollege_ID);
                qDebug() << "Total distance: " << totalDistance;
                qDebug() << "Distance between: " << distances.at(0).distanceTo;
                totalDistance += distances.at(0).distanceTo;
                this->mostEffecientTrip.push_back(collegeClicked);
                this->mostEffecientTrip.push_back(nextClosest);
                ui->totalTripDistanceLabel->setText("Total Trip Distance: " + QString::number((totalDistance), 'f', 2) + " miles");
                ui->nextClosestCollegeButton->setText("End Trip (Checkout)");
                tripIterator = (mostEffecientTrip.end() - 1);
                QListWidgetItem* newLabel = new QListWidgetItem(nextClosest.name);
                newLabel->setBackgroundColor(Qt::red);
                newLabel->setFlags(newLabel->flags() & ~Qt::ItemIsSelectable);
                ui->cartListWidget->addItem(newLabel);
                return;
            }

            // Add the starting college to the front of the mostEffecientTrip vector
            this->mostEffecientTrip.push_back(collegeClicked);

            totalDistance += distances.at(0).distanceTo;
            totalDistancesIndexed.push_back(totalDistance);
            recursivePathPlanner(nextClosest, this->mostEffecientTrip);

            this->tripIterator = this->mostEffecientTrip.begin() + 1;

            populateMenuItemDisplay(tripIterator->id);
            ui->totalTripDistanceLabel->setText("Total Trip Distance: " + QString::number((totalDistancesIndexed.front())) + " miles");

            // Display the name of the next closest college in UI button
            ui->nextClosestCollegeButton->setText("Next Closest College:\n(" + (tripIterator + 1)->name + ")");
            totalDistancesIndexed.pop_front();
            collegeClicked = *tripIterator;
            QListWidgetItem* newLabel = new QListWidgetItem(collegeClicked.name);
            newLabel->setBackgroundColor(Qt::red);
            newLabel->setFlags(newLabel->flags() & ~Qt::ItemIsSelectable);
            ui->cartListWidget->addItem(newLabel);
        }
        // The user has already started their trip, and is traversing through the most effecient trip list vector (mostEffecientTrip)
        else if (tripIterator != mostEffecientTrip.end()-1)
        {
            tripIterator++;
            populateMenuItemDisplay(tripIterator->id);

            // update total distance
            ui->totalTripDistanceLabel->setText("Total Trip Distance: " + QString::number((totalDistancesIndexed.front())) + " miles");
            totalDistancesIndexed.pop_front();
            collegeClicked = *tripIterator;
            QListWidgetItem* newLabel = new QListWidgetItem(collegeClicked.name);
            newLabel->setBackgroundColor(Qt::red);
            newLabel->setFlags(newLabel->flags() & ~Qt::ItemIsSelectable);
            ui->cartListWidget->addItem(newLabel);

            if (tripIterator == mostEffecientTrip.end() -1)
            {
                ui->nextClosestCollegeButton->setText("End Trip (Checkout)");
            } else {
                // Display the name of the next closest college in UI button
                ui->nextClosestCollegeButton->setText("Next Closest College:\n(" + (tripIterator + 1)->name + ")");
            }
        }
        else if (tripIterator == mostEffecientTrip.end()-1)
        {
            // Handle the end of the trip
            shoppingCart.printCart();
            this->close();
        }
    }
}

// Helper function for recursive path finder
bool CollegeModel::vectorContains(QVector<College> colleges, College searchRest)
{
    for (int index=0; index < colleges.size(); index++)
    {
        if (colleges.at(index).id == searchRest.id)
        {
            return true;
        }
    }
    // if it doesn't hit return true statement, the vector does not contain the given college.
    return false;
}




void CollegeModel::on_cartListWidget_clicked(const QModelIndex &index)
{
    this->selectedRow = index.row();
    qDebug() << selectedRow;
    qDebug() << ui->cartListWidget->item(selectedRow)->data(Qt::UserRole).toInt();
}

void CollegeModel::on_removeCartItemButton_clicked()
{
    if (this->shoppingCart.size() > 0 && selectedRow != -2 && ui->cartListWidget->item(selectedRow))
    {
        if (ui->cartListWidget->item(selectedRow)->data(Qt::UserRole).toInt() == 0)
        {
            QMessageBox errorMsg;
            errorMsg.setText("You can't remove the college name from your cart, silly! It's just a label. Try selecting an actual item from your cart.");
            errorMsg.exec();
            return;
        }
        qDebug() << "Before crash";
        QMessageBox::StandardButton confirm;
        confirm = QMessageBox::question(this, "Confirm Deletion", "Are you sure you want to remove the selected item from your cart?",
                                        QMessageBox::Yes|QMessageBox::No);
        if (confirm == QMessageBox::Yes) {
            QListWidgetItem* itemToDelete = ui->cartListWidget->item(selectedRow);
            souvenirItem deletedItem = DatabaseManager::getInstance()->getMenuItemByID(itemToDelete->data(Qt::UserRole).toInt());
            qDebug() << "Edit role: " << itemToDelete->data(128).toInt();
            College collegePurchasedFrom = DatabaseManager::getInstance()->getCollegeByID(itemToDelete->data(128).toInt());
            shoppingCart.deleteTransaction(Transaction(collegePurchasedFrom, deletedItem));
            // Delete the actual item from memory
            delete itemToDelete;

            // Forces the user to re-select an item if they want to delete contiguous items from the cart
            // Prevents accidental deletions
            selectedRow=-2;
        } else {
            // Do nothing
        }
    }
    else
    {
        QMessageBox errorMsg;
        errorMsg.setText("Make sure to explicitly select an item from the cart each time you remove one!");
        errorMsg.exec();
    }
}

void CollegeModel::on_viewTotalsButton_clicked()
{
    if (shoppingCart.size() > 0)
    {
        TripWindow* totalsWindow = new TripWindow(shoppingCart, this);
        totalsWindow->show();
    }
}
