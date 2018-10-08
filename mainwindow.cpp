#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adminwindow.h"
#include <QStyle>
#include <QDesktopWidget>
#include <QFileDialog>
#include <QFile>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    populateMenu();
    connect(ui->adminLoginAction, SIGNAL(triggered()), this, SLOT(on_adminPageBackButton_clicked()));
    // We will be changing the width and height later and needing to revert back to original size
    originalHeight = this->height();
    originalWidth = this->width();

}
MainWindow::~MainWindow()
{
    delete ui;
}

// Populates the main menu with college buttons for each college read from database file
void MainWindow::populateMenu()
{
    // Load all college from SQL database into College vector in MainWindow class
    QVector<College> colleges = DatabaseManager::getInstance()->getAllColleges();

    qDebug() << "Colleges size: " << colleges.size();

    int row = 0;
    int col = 0;

    // For each college in database, construct a CollegeButton (subclassed QPushButton) and associate it with said college
    for (int index=0; index < colleges.size(); index++)
    {
        // Click event is handled within the CollegeButton class (CollegeButton.cpp/.h)
        QPushButton* collegeName = new QPushButton(colleges[index].name, this);
        QFont font = collegeName->font();
        font.setPointSize(12);
        font.setFamily(QString::fromStdString("Harmonia Sans Pro, Lucia Bright,sans-serif"));
        collegeName->setObjectName(QString::number(colleges[index].id));
        collegeName->setStyleSheet("color: white;background-color: rgba(31, 34, 31, .70);border-style: solid;border-color: black;border-width: 5px; border-radius:10px;");
        collegeName->setGeometry(240,180,125,40);
        collegeName->setFont(font);

        connect(collegeName, SIGNAL(clicked()), this, SLOT(initialCollegeSelected()));

        collegeName->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

        if (col == 4)
        {
            row++;
            col = 0;
            ui->gridLayout->addWidget(collegeName, row, col);
        }
        else
        {
             ui->gridLayout->addWidget(collegeName, row, col);
        }
        col++;
    }
}
void MainWindow::initialCollegeSelected()
{
    // Get the QPushButton object that was clicked
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());

    // get all college information associated with the button that was clicked
    // (Each button's objectName is assigned the collegeID of college it represents!)
    College collegeClicked = DatabaseManager::getInstance()->getCollegeByID(clickedButton->objectName().toInt());

    // Create and show the CollegeModel
    CollegeModel* collegeView = new CollegeModel(collegeClicked, true);

    collegeView->show();
    collegeView->getTripLengthFromUser();
}

void MainWindow::on_adminLoginButton_clicked()
{
    // Authenticates a login rewquest, displays an error if username/password do not match
    // a corresponding entry in the database
    QString usernameInput = ui->usernameInput->text();
    QString passwordInput = ui->passwordInput->text();
    if (DatabaseManager::getInstance()->authenticateAdminLoginRequest(usernameInput, passwordInput))
    {
        ui->stackedWidget->setCurrentIndex(3);
        this->setWindowTitle("College Administration Panel");
        populateAdminMenu();

    } else {
        ui->loginErrorLabel->setText("Invalid username/password");
    }
}
void MainWindow::populateAdminMenu()
{
    ui->menuItemsListWidget->clear();
    QVector<College> colleges = DatabaseManager::getInstance()->getAllColleges();
    for (int index=0; index < colleges.size(); index++)
    {
        QVector<MenuItem> menuItems = colleges[index].menuItems;
        qDebug() << "menu Items size: " << menuItems.size();

        // Adds a label for each colleges menu items, makes it unselectable f
        QListWidgetItem* collegeLabel = new QListWidgetItem("Menu items for college: " + colleges[index].name);
        collegeLabel->setFlags(collegeLabel->flags() & ~Qt::ItemIsSelectable);
        ui->menuItemsListWidget->addItem(collegeLabel);
        for (int menuIndex=0; menuIndex < menuItems.size(); menuIndex++)
        {
            QListWidgetItem* newItem = new QListWidgetItem(" °  " + menuItems[menuIndex].name + " - " + QString::number(menuItems[menuIndex].price));
            newItem->setData(Qt::UserRole, menuItems[menuIndex].id);
            newItem->setData(128, colleges[index].id);
            ui->menuItemsListWidget->addItem(newItem);
        }
    }
}


void MainWindow::on_adminPageBackButton_clicked()
{
    // Back to main menu, resize and set stackedWidget index number
    ui->stackedWidget->setCurrentIndex(0);
    this->setWindowTitle("College Administration Panel");
    this->resize(originalWidth, originalHeight);
    this->setGeometry(
                QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignCenter,
                    this->size(),
                    qApp->desktop()->availableGeometry()
                    )
                );
}

void MainWindow::on_loginPageBackButton_clicked()
{
    // Same as pressing back on the admin page. (the above function)
    on_adminPageBackButton_clicked();
}

bool MainWindow::compareByDistToSaddleback(const College &A, const College &B)
{
    return A.distanceToSaddleback < B.distanceToSaddleback;
}

void MainWindow::on_planTripFromSaddlebackButton_clicked()
{

    // Find the closest college to saddleback
    QVector<College> colleges = DatabaseManager::getInstance()->getAllColleges();

    // Sorts the colleges by their distances to saddleback in ascending order.
    // Uses an overloaded operator defined inside class of College
    std::sort(colleges.begin(), colleges.end());

    CollegeModel* newView = new CollegeModel(colleges[0], true);
    newView->show();
    newView->getTripLengthFromUser();
}

void MainWindow::on_newCollegeButton_clicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setNameFilter(tr("Images (*.txt)"));
    QStringList fileName; // There should only be one uploaded file
    if (dialog.exec()) {
        fileName = dialog.selectedFiles();
    } else {
        QMessageBox errorMsg;
        errorMsg.setText("There was a problem attempting to upload the file. Please try again. ");
        errorMsg.exec();
        return;
    }

    qDebug() << fileName.front();
    QFile inputFile(fileName.front());
    if (inputFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "File opened successfully";
    } else {
        QMessageBox errorMsg;
        errorMsg.setText("There was a problem attempting to upload the file. Please try again. ");
        errorMsg.exec();
        return;
    }
    QTextStream in(&inputFile);
    QStringList parts;
    while (!in.atEnd()) {
        // Read college name
        QString line = in.readLine();
        parts = line.split(": ");
        QString collegeName = parts.back(); // Saves the college name
        qDebug() << "College name: " << collegeName;
        // Read College ID
        line = in.readLine();
        parts = line.split("number ");
        int college_ID = parts.back().toInt();
        qDebug() << college_ID;

        // ignore useless line in inputfile
        line = in.readLine(); // We don't need to do anything with this line, so go to the next
        QVector<Distance> distances;
        for (int index=0; index < 12; index++)
        {
            // read in all the distances related to this current college
            line = in.readLine();
            parts = line.split(" ");
            qDebug() << "Distance to ID: " << parts.front() << ": " << parts.back();
            if (parts.back().toDouble() != 0.0)
            {
                // All the distances related to the college_ID read in above this for loop
                Distance newDistance;
                //newDistance.destinationCollege_ID = parts.front().toInt();
                newDistance.distanceTo = parts.back().toDouble();
                distances.push_back(newDistance);
            }
        }

        // Read in the distance to saddleback
        line = in.readLine();
        parts = line.split(" ");
        double distanceToSaddleback = parts.front().toDouble();

        // Read in all menu items
        // Get the number of menu items
        line = in.readLine();
        parts = line.split(" ");
        int numOfMenuItems = parts.front().toInt();
        // Read in all the items
        QVector<MenuItem> items;
        for (int index=0; index < numOfMenuItems; index++)
        {
            // Read in item name
            line = in.readLine();
            QString itemName = line;

            // Read in item price
            line = in.readLine();
            double itemPrice = line.toDouble();

            // Create new menu item
            MenuItem newItem;
            newItem.name = itemName;
            newItem.price = itemPrice;
            items.push_back(newItem);
            qDebug() << "Pushing menu item: " << newItem.name;
        }

        College newCollege(college_ID, collegeName, distanceToSaddleback, items);
        qDebug() << "Num of menu items: " << newCollege.menuItems.size();

        DatabaseManager::getInstance()->addCollege(newCollege, distances);
        line = in.readLine();
        line = in.readLine();
    }
    populateMenu();
}

void MainWindow::on_beginTripButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    this->resize(originalWidth, originalHeight);
    this->setGeometry(
                QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignCenter,
                    this->size(),
                    qApp->desktop()->availableGeometry()
                    )
                );
}

void MainWindow::on_adminLoginButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_menuItemsListWidget_clicked(const QModelIndex &index)
{
    selectedRow = index.row();
}

void MainWindow::on_menuItemsListWidget_doubleClicked(const QModelIndex &index)
{
    // Get the menu item that was double clicked
    int menuItemID = ui->menuItemsListWidget->item(index.row())->data(Qt::UserRole).toInt();
    MenuItem itemDblClicked = DatabaseManager::getInstance()->getMenuItemByID(menuItemID);

    QInputDialog inputOperation;
    QStringList operations;
    operations << "Modify Item" << "Delete Item";
    inputOperation.setComboBoxItems(operations);

    inputOperation.setWindowTitle("Select an operation to perform on menu item: " + itemDblClicked.name);
    if (inputOperation.exec())
    {
        if (inputOperation.textValue() == "Delete Item")
        {
            DatabaseManager::getInstance()->deleteMenuItem(itemDblClicked);
            populateAdminMenu();


        } else if (inputOperation.textValue() == "Modify Item")
        {
            // Get menu item data from the item that was clicked from UI list
            int collegeID = ui->menuItemsListWidget->item(index.row())->data(128).toInt();

            // Get full college and menu item data from data of item clicked in UI
            College forCollege = DatabaseManager::getInstance()->getCollegeByID(collegeID);

            AdminWindow* newOperation = new AdminWindow(true, this, itemDblClicked, forCollege);
            newOperation->show();
        }
    }
}

void MainWindow::on_addNewMenuItemButton_clicked()
{
    AdminWindow* newOperation = new AdminWindow(false, this, MenuItem(), College());
    newOperation->show();


}

void MainWindow::on_mostEffecientTripFromUCIButton_clicked()
{
    // Create and show the CollegeModel
    College uci = DatabaseManager::getInstance()->getCollegeByID(3);
    CollegeModel* collegeView = new CollegeModel(uci, false);

    collegeView->show();
    collegeView->getTripLengthFromUser();
}

void MainWindow::on_pushButton_admin_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_mainPage_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
