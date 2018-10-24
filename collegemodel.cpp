#include "collegemodel.h"
#include "ui_collegemodel.h"

/*! The College User-Interface
 * \brief CollegeModel::CollegeModel
 * \param collegeClicked - A struct argument
 * \param asuTrip       - bool for starting point
 * \param parent
 */
CollegeModel::CollegeModel(College collegeClicked, bool asuTrip, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CollegeModel)
{
    ui->setupUi(this);
    ui->college_model_stacked_widget->setCurrentIndex(0);

    if (asuTrip)
    {
        ui->trip_distance_label->setText("Total Trip Distance: " + QString::number(collegeClicked.distanceToSaddleback, 'f', 2) + " miles");
        totalCollegesToVisit = dbManager::getInstance()->getTotalColleges();
    }
    else
    {
        totalDistance = 0;
    }

    drivingGif = new QMovie(":/new/prefix1/driving.gif");
    ui->loading_gif->setMovie(drivingGif);
    ui->loading_gif->setScaledContents(true);

    QVector<Distance> distances = dbManager::getInstance()->getDistancesFrom(collegeClicked.id);
    College nextClosest = dbManager::getInstance()->getCollegeByID(distances[0].destinationCollege_ID);
    ui->next_college_button->setText("Next Closest College\n(" + nextClosest.name + ")");

    this->collegeClicked = collegeClicked;
    populateSouvenirMenu(collegeClicked.id);

    QListWidgetItem* newLabel = new QListWidgetItem(collegeClicked.name);
    newLabel->setBackgroundColor(Qt::darkCyan);
    newLabel->setFlags(newLabel->flags() & ~Qt::ItemIsSelectable);
    ui->cartList->addItem(newLabel);
}


/*!
 * \brief CollegeModel::clearWidgets
 * \param layout - Widget to be cleared argument
 */
void CollegeModel::clearWidgets(QLayout * layout)
{
    if (!layout)
        return;
    while (auto item = layout->takeAt(0)) {
        delete item->widget();
        clearWidgets(item->layout());
    }
}

/*!
 * \brief CollegeModel::getTripLength
 * prompts user for trip length based on total colleges in database
 */
void CollegeModel::getTripLength()
{
    bool ok;
    // get user input as soon as the CollegeModel is instantiated from mainmenu.cpp button click event
    int numOfCollegesInput = QInputDialog::getInt(this, tr("Number of College Campus Stops"),
                                                  tr("Please enter the total number of colleges you wish to visit:"), 1, 0, dbManager::getInstance()->getTotalColleges(), 1, &ok);
    if (ok) // save the user's input for later use
    {
        this->totalCollegesToVisit = numOfCollegesInput;
        if (this->totalCollegesToVisit == 1)
        {
            ui->next_college_button->setText("End Trip (Checkout)");
        }
    } else {
        // The user did not specify a number of colleges to visit, so close the restuarant view window.
        this->close();
    }
}

/*!
 * \brief CollegeModel::populateSouvenirMenu
 * populates layout with souvenir buttons representing the
 * databases souvenir items for current college that the
 * student can interact with to add souvenirs to their cart
 * \param collegeID - A struct argument
 */
void CollegeModel::populateSouvenirMenu(int collegeID)
{
    clearWidgets(ui->gridLayout);
    College currentCollege = dbManager::getInstance()->getCollegeByID(collegeID);
    QVector<souvenirItem> souvenirs = currentCollege.souvenirItems;

    // Set up labels
    ui->trip_distance_label->setText("Distance to Saddleback: " + QString::number(currentCollege.distanceToSaddleback) + " miles");
    ui->college_name_label->setText(currentCollege.name);
    this->setWindowTitle("Viewing College: " + currentCollege.name);

    // Populates the menu item buttons on Layout
    if (souvenirs.size() > 0)
    {
        int row = 0;
        for (int index=0; index < souvenirs.size(); index++)
        {
            QPushButton* souvenir_button = new QPushButton(souvenirs[index].name + "\n$ " + QString::number(souvenirs[index].price));
            souvenir_button->setMaximumHeight(200);

            souvenir_button->setObjectName(QString::number(souvenirs[index].id));

            connect(souvenir_button, SIGNAL(clicked()), this, SLOT(souvenirButtonPressed()));

            souvenir_button->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
            ui->gridLayout->addWidget(souvenir_button, row, 0);
            row++;
        }
    }
    this->collegeClicked = currentCollege;
}

/*!
 * \brief CollegeModel::souvenirButtonPressed
 * Function to use data from the souvenir buttons
 * to add item from database into their transactions
 */
void CollegeModel::souvenirButtonPressed()
{
    // Get the QPushButton object that was clicked
    QPushButton *clickedSouvenirButton = qobject_cast<QPushButton*>(sender());
    // get the ID of menuItem clicked
    int clickedSouvenirID = clickedSouvenirButton->objectName().toInt();

    // Get menu item data from database using the ID
    souvenirItem clickedSouvenir = dbManager::getInstance()->getSouvenirByID(clickedSouvenirID);

    // Prompt the user to confirm their purchase
    confirmPurchase(clickedSouvenir);
}

/*!
 * \brief CollegeModel::confirmPurchase
 * Confirms if the user wants to purchase the item they have
 * selected for reassurance.
 * \param souvenir - A struct argument
 */
void CollegeModel::confirmPurchase(souvenirItem souvenir)
{
    bool ok;
    int souvenirAmountInput = QInputDialog::getInt(this, tr("Souvenir Amount"),
                                                   tr("How many of this item would you like:"), 1, 0, 99, 1, &ok);
    if(souvenirAmountInput != 0)
    {
        for(int i = 0; i < souvenirAmountInput; i++)
        {
            cart.addTransaction(collegeClicked, souvenir);
            updateCart(souvenir);
        }

    }
}

/*!
 * \brief CollegeModel::vectorContains
 * Scans vector of colleges if a specified college argument is present
 * \param colleges - A QVector of structs
 * \param searchRest - A struct argument
 * \return bool of if searched college was found
 */
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

/*!
 * \brief CollegeModel::recursivePathPlanner
 * Recursively travels from each college to the next based upon the shortest
 * distance between each of the colleges, thens stores the traversal order
 * into a QVector of colleges to be used for the student's trip.
 * \param currentCollege - A struct argument
 * \param mostEfficientList - A QVector of structs
 */
void CollegeModel::recursivePathPlanner(College currentCollege, QVector<College>& mostEfficientList)
{
    mostEfficientList.push_back(currentCollege);

    // cut off the algorithm once we have calculated only the number of colleges the user wants to visit, nothing more
    if (mostEfficientList.size() == this->totalCollegesToVisit)
    {
        return;
    }
    else
    {
        QVector<Distance> distances = dbManager::getInstance()->getDistancesFrom(currentCollege.id);

        College nextClosest = dbManager::getInstance()->getCollegeByID(distances.at(0).destinationCollege_ID);

        int index = 1;
        if (vectorContains(mostEfficientList, nextClosest))
        {
            while(vectorContains(mostEfficientList, nextClosest))
            {
                nextClosest = dbManager::getInstance()->getCollegeByID(distances.at(index).destinationCollege_ID);
                index++;
            }
            totalDistance += distances.at(index-1).distanceTo;

        }
        else
        {
            totalDistance += distances.at(0).distanceTo;

        }
        totalDistancesIndexed.push_back(totalDistance);

        recursivePathPlanner(nextClosest, mostEfficientList);
    }
}

/*! Default Constructor
 * \brief CollegeModel::~CollegeModel
 */
CollegeModel::~CollegeModel()
{
    delete ui;
}

/*!
 * \brief CollegeModel::on_next_college_button_clicked
 * Iterates to the next college and processes new menus
 */
void CollegeModel::on_next_college_button_clicked()
{
    if(totalCollegesToVisit == 1)
    {
        this->close();
    }
    else if(mostEfficientTrip.size() == 0)
    {
        QVector<Distance> distances = dbManager::getInstance()->getDistancesFrom(collegeClicked.id);
        College nextClosest = dbManager::getInstance()->getCollegeByID(distances.at(0).destinationCollege_ID);

        if(totalCollegesToVisit == 2)
        {
            loadingPage();

            populateSouvenirMenu(distances.at(0).destinationCollege_ID);
            totalDistance += distances.at(0).distanceTo;

            this->mostEfficientTrip.push_back(collegeClicked);
            this->mostEfficientTrip.push_back(nextClosest);

            ui->trip_distance_label->setText("Total Trip Distance: " + QString::number((totalDistance), 'f', 2) + " miles");
            ui->next_college_button->setText("End Trip (Checkout)");

            tripIterator = (mostEfficientTrip.end() - 1);

            QListWidgetItem* newLabel = new QListWidgetItem(nextClosest.name);
            newLabel->setBackgroundColor(Qt::darkCyan);
            newLabel->setFlags(newLabel->flags() & ~Qt::ItemIsSelectable);
            ui->cartList->addItem(newLabel);

            return;
        }

        this->mostEfficientTrip.push_back(collegeClicked);

        totalDistance += distances.at(0).distanceTo;
        totalDistancesIndexed.push_back(totalDistance);
        recursivePathPlanner(nextClosest, this->mostEfficientTrip);

        this->tripIterator = this->mostEfficientTrip.begin() + 1;

        loadingPage();
        populateSouvenirMenu(tripIterator->id);
        ui->trip_distance_label->setText("Total Trip Distance: " + QString::number((totalDistancesIndexed.front())) + " miles");

        // Display the name of the next closest college in UI button
        ui->next_college_button->setText("Next Closest College:\n(" + (tripIterator + 1)->name + ")");
        totalDistancesIndexed.pop_front();
        collegeClicked = *tripIterator;

        QListWidgetItem* newLabel = new QListWidgetItem(collegeClicked.name);
        newLabel->setBackgroundColor(Qt::darkCyan);
        newLabel->setFlags(newLabel->flags() & ~Qt::ItemIsSelectable);
        ui->cartList->addItem(newLabel);
    }
    else if(tripIterator != mostEfficientTrip.end() -1)
    {
        loadingPage();
        tripIterator++;
        populateSouvenirMenu(tripIterator->id);

        // update total distance
        ui->trip_distance_label->setText("Total Trip Distance: " + QString::number((totalDistancesIndexed.front())) + " miles");
        totalDistancesIndexed.pop_front();
        collegeClicked = *tripIterator;

        QListWidgetItem* newLabel = new QListWidgetItem(collegeClicked.name);
        newLabel->setBackgroundColor(Qt::darkCyan);
        newLabel->setFlags(newLabel->flags() & ~Qt::ItemIsSelectable);
        ui->cartList->addItem(newLabel);

        if (tripIterator == mostEfficientTrip.end() -1)
        {
            ui->next_college_button->setText("End Trip (Checkout)");
        }
        else
        {
            // Display the name of the next closest college in UI button
            ui->next_college_button->setText("Next Closest College:\n(" + (tripIterator + 1)->name + ")");
        }
    }
    else //trip end
    {
        this->close();
    }
}

/*!
 * \brief CollegeModel::on_cartList_clicked
 * \param index - representation of item clicked
 */
void CollegeModel::on_cartList_clicked(const QModelIndex &index)
{
    this->selectedRow = index.row();
}

/*!
 * \brief CollegeModel::on_removeCartItemButton_clicked
 * Processes removal of item selected by user from the purchases
 * data vector in transactions
 */
void CollegeModel::on_removeCartItemButton_clicked()
{
    if (this->cart.size() > 0 && selectedRow != -2 && ui->cartList->item(selectedRow))
    {
        if (ui->cartList->item(selectedRow)->data(Qt::UserRole).toInt() == 0)
        {
            QMessageBox errorMsg;
            errorMsg.setText("You can't remove the college name from your cart, silly! It's just a label. Try selecting an actual item from your cart.");
            errorMsg.exec();
            return;
        }

        QMessageBox::StandardButton confirm;
        confirm = QMessageBox::question(this, "Confirm Deletion", "Are you sure you want to remove the selected item from your cart?",
                                        QMessageBox::Yes|QMessageBox::No);

        if (confirm == QMessageBox::Yes)
        {
            QListWidgetItem* itemToDelete = ui->cartList->item(selectedRow);
            souvenirItem deletedItem = dbManager::getInstance()->getSouvenirByID(itemToDelete->data(Qt::UserRole).toInt());

            College collegePurchasedFrom = dbManager::getInstance()->getCollegeByID(itemToDelete->data(128).toInt());
            cart.deleteTransaction(Transaction(collegePurchasedFrom, deletedItem));

            // Delete the actual item from memory
            delete itemToDelete;

            // Forces the user to re-select an item if they want to delete contiguous items from the cart
            // Prevents accidental deletions
            selectedRow=-2;

        }
    }
    else
    {
        QMessageBox errorMsg;
        errorMsg.setText("Make sure to explicitly select an item from the cart each time you remove one!");
        errorMsg.exec();
    }
}

/*!
 * \brief CollegeModel::updateCart
 * Updates student's cart to ensure it is accurate and
 * all items are proper
 * \param item - A struct argument
 */
void CollegeModel::updateCart(souvenirItem item)
{
    QListWidgetItem* newItem = new QListWidgetItem;
    newItem->setData(Qt::UserRole, item.id);
    newItem->setData(128, collegeClicked.id);
    newItem->setText(" °  " + item.name + " - $" + QString::number(item.price));

    ui->cartList->addItem(newItem);
    ui->totals_label->setText("Total: $" + QString::number(cart.getTotal(), 'f', 2));
}

/*!
 * \brief CollegeModel::on_totals_button_clicked
 * Creates instance of totalssheet class to view
 * a layout detailing trip expenses.
 */
void CollegeModel::on_totals_button_clicked()
{
    if (cart.size() > 0)
    {
        totalsSheet* totalsWindow = new totalsSheet(cart, this);
        totalsWindow->show();
    }
}

/*!
 * \brief CollegeModel::loadingPage
 * Brief intermission when traveling
 */
void CollegeModel::loadingPage()
{
    drivingGif->start();
    ui->college_model_stacked_widget->setCurrentIndex(1);
    delay(1);
    drivingGif->stop();
    ui->college_model_stacked_widget->setCurrentIndex(0);
}

/*!
 * \brief CollegeModel::delay
 * Helper timing function for loading page
 * \param n - Amount of seconds to delay
 */
void CollegeModel::delay(int n)
{
    QTime dieTime= QTime::currentTime().addSecs(n);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
