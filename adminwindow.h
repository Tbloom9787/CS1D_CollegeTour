#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QWidget>
#include "databasemanager.h"
#include <QListWidget>
#include "mainwindow.h"
namespace Ui {
class AdminWindow;
}

//! The Restaurant Operations.
/*!
  This class handles the basic operations of the
  User-Interface when buttons are clicked.
 */

class AdminWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AdminWindow(bool modifying = true, MainWindow* listWidget = 0, MenuItem item = MenuItem(), College college = College(), QWidget *parent = 0);
    ~AdminWindow();

private slots:

    void on_pushButton_clicked();

    void on_itemNameInput_textChanged(const QString &arg1);

    void on_itemPriceInput_valueChanged(double arg1);

    void on_collegeComboBox_currentIndexChanged(int index);

    void on_newItemNameInput_textChanged(const QString &arg1);

    void on_newItemPriceInput_valueChanged(double arg1);

    void on_addNewItemButton_clicked();

    void on_cancelButton_2_clicked();

private:
    Ui::AdminWindow *ui;

    //! Used for updating the UI after an operation has been performed on the database
    MainWindow* mainWindow;

    //! Only used for modify existing menu item operation
    MenuItem menuItemToModify;

    //! Only used for add new menu item operation
    int collegeIDSelected;
    MenuItem newItem;
};

#endif // ADMINWINDOW_H