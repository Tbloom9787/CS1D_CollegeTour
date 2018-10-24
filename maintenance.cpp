#include "maintenance.h"
#include "ui_maintenance.h"

/*! Constructor
 * \brief maintenance::maintenance
 * \param modifying - bool if modifiying item
 * \param mainWindow - pointer to mainwindow for updates
 * \param souvenir - A struct argument
 * \param college - a struct argument
 * \param parent
 */
maintenance::maintenance(bool modifying, MainWindow *mainWindow, souvenirItem souvenir, College college, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::maintenance)
{
    ui->setupUi(this);
    ui->maintenance_stacked_widget->setCurrentIndex(1);
    this->mainWindow = mainWindow;
    if(modifying)
    {
        ui->modify_price->setDecimals(2);
        ui->modify_price->setSingleStep(0.01);
        ui->college_label->setText("For college: " + college.name);
        ui->modify_name_edit->setText(souvenir.name);
        ui->modify_price->setValue(souvenir.price);
        this->itemToModify= souvenir;
    }
    else
    {
        // We are adding a new item instead of modifying an existing one
        ui->maintenance_stacked_widget->setCurrentIndex(0);
        QVector<College> colleges = dbManager::getInstance()->getColleges();
        for (int index=0; index < colleges.size(); index++)
        {
            ui->college_combo_box->addItem(colleges[index].name, colleges[index].id);
        }
    }
}

/*! Default Destructor
 * \brief maintenance::~maintenance
 */
maintenance::~maintenance()
{
    delete ui;
}

/*!
 * \brief maintenance::on_add_button_clicked
 * Processes new item addition
 */
void maintenance::on_add_button_clicked()
{
    this->newSouvenir.name = ui->new_item_name->text();
    this->newSouvenir.price = ui->new_item_price->value();

    if (newSouvenir.name.isEmpty())
    {
        QMessageBox errorMsg;
        errorMsg.setText("Item name cannot be empty!");
        errorMsg.exec();
    } else
    {
        QMessageBox::StandardButton confirm;
        confirm = QMessageBox::question(this, "Confirm Modifications", "Are you sure you want to modify the database?",
                                        QMessageBox::Yes|QMessageBox::No);
        if (confirm == QMessageBox::Yes)
        {
            College collegeToAddItemTo = dbManager::getInstance()->getCollegeByID(selectedCollegeID);
            qDebug() << "New souvenir item: " << newSouvenir.name;
            qDebug() << "Adding to college: " << collegeToAddItemTo.name;
            dbManager::getInstance()->addSouvenirItem(newSouvenir, collegeToAddItemTo);
            mainWindow->populateAdminMenu();
        }
        this->close();
    }

}

/*!
 * \brief maintenance::on_college_combo_box_currentIndexChanged
 * \param index - An integer argument
 */
void maintenance::on_college_combo_box_currentIndexChanged(int index)
{
    this->selectedCollegeID = ui->college_combo_box->itemData(index, Qt::UserRole).toInt();
}

/*!
 * \brief maintenance::on_modify_name_edit_textChanged
 * \param newName - A QString argument
 */
void maintenance::on_modify_name_edit_textChanged(const QString &newName)
{
    this->itemToModify.name = newName;
}

/*!
 * \brief maintenance::on_modify_price_valueChanged
 * \param newPrice - A double argument
 */
void maintenance::on_modify_price_valueChanged(double newPrice)
{
    this->itemToModify.price = newPrice;
}

/*!
 * \brief maintenance::on_save_button_clicked
 * Confrims item to database
 */
void maintenance::on_save_button_clicked()
{
    QMessageBox::StandardButton confirm;
    confirm = QMessageBox::question(this, "Confirm Modifications", "Are you sure you want to commit the changes to this menu item?",
                                    QMessageBox::Yes|QMessageBox::No);
    if (confirm == QMessageBox::Yes) {
        dbManager::getInstance()->modifySouvenirItem(itemToModify);
        mainWindow->populateAdminMenu();
    }
    this->close();
}

/*!
 * \brief maintenance::on_cancel_button_2_clicked
 */
void maintenance::on_cancel_button_2_clicked()
{
    this->close();
}

/*!
 * \brief maintenance::on_cancel_button_clicked
 */
void maintenance::on_cancel_button_clicked()
{
    this->close();
}
