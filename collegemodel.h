#ifndef COLLEGEMODEL_H
#define COLLEGEMODEL_H

#include <QWidget>
#include <QPushButton>
#include <QListWidgetItem>
#include "QInputDialog"
#include <QMessageBox>
#include "mainwindow.h"
#include "dbmanager.h"
#include "cart.h"
#include "totalssheet.h"

#include <QMovie>
#include <QDateTime>

/*! College Model Interface
 *  This class will handle the functionality the user
 * will interact with. Public functions will allow
 * most program capabilities and the private data will
 * be processed and stored. The UI class will allow
 * a student to generate a college trip and
 * the ability to purchase souvenirs along the way.
 */
namespace Ui {
class CollegeModel;
}

/*!
 * \brief The CollegeModel class
 * The class that will process all the functionality
 * of the UI and allow the user to properly plan
 * their trip and make purchases.
 */
class CollegeModel : public QWidget
{
    Q_OBJECT

public:
    //! Constructor
    explicit CollegeModel(College collegeClicked, bool asuTrip, QWidget *parent = 0);
    ~CollegeModel();    //!< Default Destructor

    //! Recursive function to effectively plan the trip amongst colleges
    void recursivePathPlanner(College currentCollege, QVector<College> &mostEfficientList);

    void getTripLength();   //!< Function to receive trip length from student
    void populateSouvenirMenu(int collegeID);   //!< Populates menu with souvenir data to be purchased
    void clearWidgets(QLayout *layout);         //!< Clears widgets to maintain integrity
    bool vectorContains(QVector<College> colleges, College searchRest); //!< Search function for college
    void confirmPurchase(souvenirItem souvenir);    //!< Reassurance of purchase from student
    void updateCart(souvenirItem item);         //!< Adds item to cart and updates

    void delay(int n);      //! Timing function

protected slots:
    void loadingPage();     //! Processes intermission between traversal

public slots:
    void souvenirButtonPressed();   //! Selects souvenir item to be purchased

private slots:
    void on_next_college_button_clicked();  //! Starts processes to next college
    void on_cartList_clicked(const QModelIndex &index); //! Shows current shopping cart index
    void on_removeCartItemButton_clicked(); //! Removes item from currrently selected row

    void on_totals_button_clicked();    //! Opens sheet of current totals

private:
    Ui::CollegeModel *ui;           //! The UI class
    College collegeClicked;         //! Struct of currently selected college
    int totalCollegesToVisit;       //! Number of colleges to be visited

    QMovie *drivingGif;             //! Animated Gif for loading page

    Cart cart;                      //! Vector of transactions to handle purhcasing

    QVector<College> mostEfficientTrip;         //! QVector of colleges to store trip order
    QVector<College>::iterator tripIterator;    //! Iterator to follow traversal of student
    QVector<double> totalDistancesIndexed;      //! QVector that will store the current indexed distance
    double totalDistance;           //! Total distance traveled
    int selectedRow;                //! Selected row to access database
};

#endif // COLLEGEMODEL_H
