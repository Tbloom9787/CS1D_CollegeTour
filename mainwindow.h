#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "databasemanager.h"
#include <QGridLayout>
#include <QMessageBox>
#include "collegemodel.h"
#include <algorithm>

namespace Ui {
class MainWindow;
}

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    //! Populate the main menu with a list of all colleges in database
    void populateMenu();

    //! Compare which college is closer to Saddleback and return a boolean
    bool compareByDistToSaddleback(const College &A, const College &B);

    //! Fill admin menu with the required information
    void populateAdminMenu();
signals:
    void collegeClickedSignal(College);

private slots:

    //! Will activate verification function and open admin window if passed
    void on_adminLoginButton_clicked();

    //! Will go back a window
    void on_adminPageBackButton_clicked();

    //! Will go back to main menu window
    void on_loginPageBackButton_clicked();

    //! Will open dialog box to enter number of colleges
    void on_planTripFromSaddlebackButton_clicked();

    void initialCollegeSelected();

    void on_newCollegeButton_clicked();

    void on_beginTripButton_clicked();

    void on_adminLoginButton_2_clicked();

    void on_menuItemsListWidget_clicked(const QModelIndex &index);

    void on_menuItemsListWidget_doubleClicked(const QModelIndex &index);

    void on_addNewMenuItemButton_clicked();

    void on_mostEffecientTripFromUCIButton_clicked();

private:
    Ui::MainWindow *ui;
    int originalWidth;
    int originalHeight;
    int selectedRow;
};

#endif // MAINWINDOW_H
