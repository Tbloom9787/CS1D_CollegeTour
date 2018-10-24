#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbmanager.h"
#include "collegemodel.h"
#include "maintenance.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->error_label->hide();
    ui->main_stacked_widget->setCurrentIndex(0);
    populateMenu();
}


/*! Default Destructor
 * \brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/*!
 * \brief MainWindow::on_startButton_clicked
 */
void MainWindow::on_startButton_clicked()
{
    ui->main_stacked_widget->setCurrentIndex(1);
}

/*!
 * \brief MainWindow::initialCollegeSelected
 */
void MainWindow::initialCollegeSelected()
{
    // Get the QPushButton object that was clicked
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());

    // get all college information associated with the button that was clicked
    // (Each button's objectName is assigned the collegeID of college it represents!)
    College collegeClicked = dbManager::getInstance()->getCollegeByID(clickedButton->objectName().toInt());

    // Create and show the CollegeModel
    CollegeModel* collegeView = new CollegeModel(collegeClicked, false);

    collegeView->show();
    collegeView->getTripLength();
}

/*!
 * \brief MainWindow::populateMenu
 * Fills menu up with database colleges to allow user to choose
 * which college they wish to start their custom trip at.
 */
void MainWindow::populateMenu()
{
    QVector<College> colleges = dbManager::getInstance()->getColleges();

    qDebug() << "Colleges size: " << colleges.size();

    int row = 0;
    int col = 0;

    //For each college in database, construct a CollegeButton (subclassed QPushButton) and associate it with said college
    for (int index=0; index < colleges.size(); index++)
    {
        // Click event is handled within the CollegeButton class (CollegeButton.cpp/.h)
        QPushButton* collegeName = new QPushButton(colleges[index].name + "\nDistance to Saddleback: " + QString::number(colleges[index].distanceToSaddleback) + " miles", this);


        collegeName->setObjectName(QString::number(colleges[index].id));

        connect(collegeName, SIGNAL(clicked()), this, SLOT(initialCollegeSelected()));

        collegeName->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

        if(col == 2)
        {
            row++;
            col=0;
            ui->gridLayout->addWidget(collegeName,row,col);
        }
        else
        {
            ui->gridLayout->addWidget(collegeName,row,col);
        }
        col++;
    }
}


/*!
 * \brief MainWindow::on_header_icon_push_button_clicked
 */
void MainWindow::on_header_icon_push_button_clicked()
{
    ui->main_stacked_widget->setCurrentIndex(0);
}

/*!
 * \brief MainWindow::on_ASU_trip_button_clicked
 */
void MainWindow::on_ASU_trip_button_clicked()
{
    CollegeModel* collegeView = new CollegeModel(dbManager::getInstance()->getCollegeByID(1), true);

    collegeView->show();

}

/*!
 * \brief MainWindow::on_shortest_trip_button_clicked
 */
void MainWindow::on_shortest_trip_button_clicked()
{
    College uci = dbManager::getInstance()->getCollegeByID(6);
    CollegeModel* collegeView = new CollegeModel(uci, false);

    collegeView->show();
    collegeView->getTripLength();
}

/*!
 * \brief MainWindow::on_admin_push_button_clicked
 */
void MainWindow::on_admin_push_button_clicked()
{
    ui->main_stacked_widget->setCurrentIndex(2);
}

/*!
 * \brief MainWindow::on_back_button_clicked
 */
void MainWindow::on_back_button_clicked()
{
    ui->main_stacked_widget->setCurrentIndex(0);
}

/*!
 * \brief MainWindow::validateLogin
 * Function to check login credentials for validity
 * and if not will prompt user
 */
void MainWindow::validateLogin()
{

    QString userName = ui->username_line_edit->text();
    QString password = ui->password_line_edit->text();

    if (dbManager::getInstance()->authenticateAdminLoginRequest(userName, password))
    {
        ui->main_stacked_widget->setCurrentIndex(3);
        populateAdminMenu();
    }
    else
    {
        ui->error_label->show();
        ui->username_line_edit->clear();
        ui->password_line_edit->clear();
    }

}

/*!
 * \brief MainWindow::on_login_button_clicked
 * Attempts login process
 */
void MainWindow::on_login_button_clicked()
{
    validateLogin();
    ui->username_line_edit->clear();
    ui->password_line_edit->clear();
}

/*!
 * \brief MainWindow::on_username_line_edit_returnPressed
 */
void MainWindow::on_username_line_edit_returnPressed()
{
    validateLogin();
    ui->username_line_edit->clear();
    ui->password_line_edit->clear();
}
/*!
 * \brief MainWindow::on_password_line_edit_returnPressed
 */
void MainWindow::on_password_line_edit_returnPressed()
{
    validateLogin();
    ui->username_line_edit->clear();
    ui->password_line_edit->clear();
}

/*!
 * \brief MainWindow::on_username_line_edit_textEdited
 * \param arg1
 */
void MainWindow::on_username_line_edit_textEdited(const QString &arg1)
{
    ui->error_label->hide();
}

/*!
 * \brief MainWindow::on_password_line_edit_textEdited
 * \param arg1
 */
void MainWindow::on_password_line_edit_textEdited(const QString &arg1)
{
    ui->error_label->hide();
}

/*!
 * \brief MainWindow::populateAdminMenu
 * Populates admin menu with souvenir lists from which
 * the user can select an item to change or delete
 */
void MainWindow::populateAdminMenu()
{
    ui->souvenir_list_widget->clear();
    QVector<College> colleges = dbManager::getInstance()->getColleges();
    for (int index=0; index < colleges.size(); index++)
    {
        QVector<souvenirItem> souvenirItems = colleges[index].souvenirItems;

        QListWidgetItem* collegeLabel = new QListWidgetItem("Souvenir items for college: " + colleges[index].name);
        collegeLabel->setBackgroundColor(Qt::darkYellow);
        collegeLabel->setFlags(collegeLabel->flags() & ~Qt::ItemIsSelectable);
        ui->souvenir_list_widget->addItem(collegeLabel);
        for (int i=0; i < souvenirItems.size(); i++)
        {
            QListWidgetItem* newItem = new QListWidgetItem(" °  " + souvenirItems[i].name + " - " + QString::number(souvenirItems[i].price, 'f', 2));
            newItem->setData(Qt::UserRole, souvenirItems[i].id);
            newItem->setData(128, colleges[index].id);
            ui->souvenir_list_widget->addItem(newItem);
        }
    }
}

/*!
 * \brief MainWindow::on_add_souvenir_button_clicked
 */
void MainWindow::on_add_souvenir_button_clicked()
{
    maintenance* addSouvenirOperation = new maintenance(false, this, souvenirItem(), College());
    addSouvenirOperation->show();
}

/*!
 * \brief MainWindow::on_souvenir_list_widget_clicked
 * \param index
 */
void MainWindow::on_souvenir_list_widget_clicked(const QModelIndex &index)
{
    selectedRow = index.row();
}

/*!
 * \brief MainWindow::on_souvenir_list_widget_doubleClicked
 * \param index - An integer argument
 */
void MainWindow::on_souvenir_list_widget_doubleClicked(const QModelIndex &index)
{
    int souvenirItemID = ui->souvenir_list_widget->item(index.row())->data(Qt::UserRole).toInt();
    souvenirItem itemClicked = dbManager::getInstance()->getSouvenirByID(souvenirItemID);

    QInputDialog inputOperation;
    QStringList operations;
    operations << "Modify Item" << "Delete Item";
    inputOperation.setComboBoxItems(operations);

    inputOperation.setWindowTitle("Select an operation to perform on the item: " + itemClicked.name);
    if (inputOperation.exec())
    {
        if (inputOperation.textValue() == "Delete Item")
        {
            dbManager::getInstance()->deleteSouvenirItem(itemClicked);
            populateAdminMenu();

        } else if (inputOperation.textValue() == "Modify Item")
        {
            int collegeID = ui->souvenir_list_widget->item(index.row())->data(128).toInt();

            College forCollege = dbManager::getInstance()->getCollegeByID(collegeID);

            maintenance* newOperation = new maintenance(true, this, itemClicked, forCollege);
            newOperation->show();
        }
    }
}

/*!
 * \brief MainWindow::on_upload_college_button_clicked
 * Reads from a file to add a college into the database
 */
void MainWindow::on_upload_college_button_clicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setNameFilter(tr("Images (*.txt)"));
    QStringList fileName; // There should only be one uploaded file
    if (dialog.exec()) {
        fileName = dialog.selectedFiles();
    } else
    {
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
    }
    else
    {
        QMessageBox errorMsg;
        errorMsg.setText("There was a problem attempting to upload the file. Please try again. ");
        errorMsg.exec();
        return;
    }
    QTextStream in(&inputFile);
    QStringList parts;
    while (!in.atEnd())
    {
        // Read college name
        QString line = in.readLine();
        parts = line.split(": ");
        QString collegeName = parts.back(); // Saves the college name
        qDebug() << "College name: " << collegeName;
        // Read College ID
        line = in.readLine();
        int college_ID = line.toInt();
        qDebug() << college_ID;

        QVector<Distance> distances;
        for (int index=0; index < 11; index++)
        {
            // read in all the distances related to this current college
            line = in.readLine();
            parts = line.split(" ");
            qDebug() << "Distance to ID: " << parts.front() << ": " << parts.back();
            if (parts.back().toDouble() != 0.0)
            {
                // All the distances related to the college_ID read in above this for loop
                Distance newDistance;
                newDistance.destinationCollege_ID = parts.front().toInt();
                newDistance.distanceTo = parts.back().toDouble();
                distances.push_back(newDistance);
            }
        }
        double distanceToSaddleback = parts.back().toDouble();
        line  = in.readLine();
        parts = line.split(": ");
        int itemsSize = parts.back().toInt();

        QVector<souvenirItem> items;
        for (int index = 0; index < itemsSize; index++)
        {
            // Read in the item name and price and split
            line  = in.readLine();
            parts = line.split(" ");

            QString itemName  = parts.front();
            double  itemPrice = parts.back().toDouble();

            souvenirItem newItem;
            newItem.name  = itemName;
            newItem.price = itemPrice;
            items.push_back(newItem);
            qDebug() << "Pushing new souvenir item: " << newItem.name;
        }

        College newCollege(college_ID, collegeName, distanceToSaddleback, items);

        dbManager::getInstance()->addCollege(newCollege, distances);

        // Skip this line for new colleges
        line = in.readLine();
    }
    populateMenu();
}

/*!
 * \brief MainWindow::on_exit_button_clicked
 */
void MainWindow::on_exit_button_clicked()
{
    ui->main_stacked_widget->setCurrentIndex(0);
}
