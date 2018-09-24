#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "ui_collegemodel.h"
#include <QMessageBox>
AdminWindow::AdminWindow(bool modifying, MainWindow* mainWindow, souvenirItem item, College college, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    this->mainWindow = mainWindow;
    if (modifying)
    {
        ui->itemPriceInput->setDecimals(2);
        ui->itemPriceInput->setSingleStep(0.01);
        ui->collegeLabel->setText("For college: " + college.name);
        ui->itemNameInput->setText(item.name);
        ui->itemPriceInput->setValue(item.price);
        this->souvenirItemToModify= item;
    } else {
        // We are adding a new item instead of modifying an existing one
        ui->stackedWidget->setCurrentIndex(1);
        QVector<College> colleges = DatabaseManager::getInstance()->getAllColleges();
        for (int index=0; index < colleges.size(); index++)
        {
            ui->collegeComboBox->addItem(colleges[index].name, colleges[index].id);
        }
    }

}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::on_pushButton_clicked()
{
    QMessageBox::StandardButton confirm;
    confirm = QMessageBox::question(this, "Confirm Modifications", "Are you sure you want to commit the changes to this menu item?",
                                    QMessageBox::Yes|QMessageBox::No);
    if (confirm == QMessageBox::Yes) {
        // DatabaseManager::modifyMenuItem
        DatabaseManager::getInstance()->modifyMenuItem(souvenirItemToModify);
        mainWindow->populateAdminMenu();
    }
    this->close();
}

void AdminWindow::on_itemNameInput_textChanged(const QString &newName)
{
    this->souvenirItemToModify.name = newName;

}

void AdminWindow::on_itemPriceInput_valueChanged(double newPrice)
{
    this->souvenirItemToModify.price = newPrice;
}


void AdminWindow::on_collegeComboBox_currentIndexChanged(int index)
{
    this->collegeIDSelected = ui->collegeComboBox->itemData(index, Qt::UserRole).toInt();
}

void AdminWindow::on_newItemNameInput_textChanged(const QString &itemName)
{
    this->newItem.name = itemName;

}

void AdminWindow::on_newItemPriceInput_valueChanged(double price)
{
    this->newItem.price = price;
}

void AdminWindow::on_addNewItemButton_clicked()
{
    if (newItem.name.isEmpty())
    {
        QMessageBox errorMsg;
        errorMsg.setText("Item name cannot be empty!");
        errorMsg.exec();
    } else {
        QMessageBox::StandardButton confirm;
        confirm = QMessageBox::question(this, "Confirm Modifications", "Are you sure you want to modify the database?",
                                        QMessageBox::Yes|QMessageBox::No);
        if (confirm == QMessageBox::Yes) {
            College collegeToAddItemTo = DatabaseManager::getInstance()->getCollegeByID(collegeIDSelected);
            qDebug() << "New souvenir item: " << newItem.name;
            qDebug() << "Adding to college: " << collegeToAddItemTo.name;
            DatabaseManager::getInstance()->addMenuItem(newItem, collegeToAddItemTo);
            mainWindow->populateAdminMenu();
        }
        this->close();
    }

}




void AdminWindow::on_cancelButton_2_clicked()
{
    this->close();
}
