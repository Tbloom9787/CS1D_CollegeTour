#ifndef MAINTENANCE_H
#define MAINTENANCE_H

#include <QWidget>
#include "dbmanager.h"
#include "mainwindow.h"

namespace Ui {
class maintenance;
}

/*! Maintenance Operations
 * \brief The maintenance class
 * This class will handle basic operations of
 * User-Interface and altering database records
 * used in the program
 */
class maintenance : public QWidget
{
    Q_OBJECT

public:
    explicit maintenance(bool modifying = true, MainWindow *listWidget = 0, souvenirItem souvenir = souvenirItem(),
                        College college = College(), QWidget *parent = 0);
    ~maintenance();

private slots:
    void on_add_button_clicked();   //! Begins process of college addition to database

    void on_college_combo_box_currentIndexChanged(int index);   //! Chooses college from database

    void on_modify_name_edit_textChanged(const QString &arg1);  //! Stores name for new item

    void on_modify_price_valueChanged(double arg1); //! Stores price for new item

    void on_save_button_clicked();  //! Saves item to database

    void on_cancel_button_2_clicked();  //! Returns to main page

    void on_cancel_button_clicked();    //! Returns to main page

private:
    Ui::maintenance *ui;

    MainWindow* mainWindow;     //! Pointer to main window to update UI after database alterations
    souvenirItem itemToModify;  //! Struct to modify souvenir data
    int selectedCollegeID;      //! Struct for college additions to data
    souvenirItem newSouvenir;   //! Struct for souvenir additions to data
};

#endif // MAINTENANCE_H
