#ifndef CollegeModel_H
#define CollegeModel_H

#include <QWidget>
#include <QPushButton>
#include "cart.h"
#include <QListWidgetItem>
#include "tripwindow.h"
namespace Ui {
class CollegeModel;
}

//! The College User-Interface
/*!
  This class handles most functionality, along with
  displays of the User-Interface and data being used.
  The public methods will perform most capabilities
  of the program. The private data members are used to
  store and proccess data of the colleges. The class
  allows the user to plan a trip to as many colleges
  desired and purchase food as you would in a normal
  college.
*/

class CollegeModel : public QWidget
{
    Q_OBJECT

public:
    //! Constructor
    explicit CollegeModel(College collegeClicked, bool startingFromSaddleback=false, QWidget *parent = 0);
    ~CollegeModel();

    //! User-Interface function to populate the display with the given college's menu items.
    /*!
     * \brief populateMenuItemDisplay The college's ID is
     * passed in to determine the current college and the
     * menu is displayed in a gridLayout.
     *
     * \param collegeID An integer argument.
     */
    void populateMenuItemDisplay(int collegeID);

    //! The recursive function to effectively plan the most efficient trip
    /*!
     * \brief recursivePathPlanner The entire efficient path
     * is planned after start college is passed.
     *
     * The starting college is initially passed in and becomes
     * the currentCollege along with the repeatedly updated mostEfficientList.
     * The base case to exit the function is when the mostEfficientList's size is
     * the user's desired amount of colleges. The recursive call is performed
     * by passing in the next closest college toyour current location and set
     * it as the currentCollege with an updated list.
     *
     * \param currentCollege A struct argument
     * \param mostEffecientList A qvector argument
     */
    void recursivePathPlanner(College currentCollege, QVector<College>& mostEffecientList);

    //! A search function to traverse through the list of colleges
    /*!
     * \brief vectorContains The function will traverse through colleges
     * as it looks for the passed in searchRest and compare each one by ID.
     *
     * \param colleges A qvector argument
     * \param searchRest A struct argument
     * \return A boolean that is true if college is found
     */
    bool vectorContains(QVector<College> colleges, College searchRest);

    //! A function that requires user-input of trip length
    /*!
     * \brief getTripLengthFromUser The user is prompted to enter
     * the desired trip length in a QInputDialog box.
     */
    void getTripLengthFromUser();

    //! To clear the widgets on a window
    /*!
     * \brief clearWidgets Will look through the layout for the
     * pointed to poisiton and clear the widgets of that position.
     * \param layout A qlayout argument
     */
    void clearWidgets(QLayout *layout);

    //! A function for reassurance by user of a purchase
    /*!
     * \brief confirmPurchase The user is prompted if they
     * confirm a purchase of a menu item in a QMessageBox.
     *
     * \param item A struct argument
     */
    void confirmPurchase(souvenirItem item);

    //! To add an item to the shopping cart
    /*!
     * \brief updateShoppingCart It will be passed the
     * user's desired menu item and store it into their
     * shopping cart.
     *
     * \param item A struct argument
     */
    void updateShoppingCart(souvenirItem item);
public slots:
    //! Will activate the function to add the menu item to cart
    void menuItemButtonPressed();
private slots:

    //! Will open the window to the next closest Colleges menu
    void on_nextClosestCollegeButton_clicked();

    //! Will open the window that displays the current shopping cart
    void on_cartListWidget_clicked(const QModelIndex &index);

    //! Will activate the function to delete a transaction
    void on_removeCartItemButton_clicked();

    //! Will open the total expenses window
    void on_viewTotalsButton_clicked();

private:
    Ui::CollegeModel *ui;                   //!< The User-Interface for the class
    Cart shoppingCart;                              //!< Vector of shopping cart that handles all colleges visited
    College collegeClicked;                   //!< Struct of the currently clicked college by user
    QVector<College> mostEffecientTrip;          //!< QVector of colleges that stores the most efficient trip
    QVector<College>::iterator tripIterator;     //!< An iterator that is for traversals and processing of the trip
    int numberOfCollegesToVisit;                 //!< The number of colleges the user has specified to visit
    QVector<double> totalDistancesIndexed;          //!< QVector of double that will store the current indexed total distance
    double totalDistance;                           //!< An accumulator of type double that will store the entire trip total distance
    int selectedRow;                                //!< The selected row to access the database
};

#endif // CollegeModel_H
