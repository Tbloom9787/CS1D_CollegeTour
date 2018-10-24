#ifndef CART_H
#define CART_H

#include "dbmanager.h"

/*! The Transaction Handler
 * \brief The Transaction class
 *
 * The transaction class will handle operations in the
 * cart class of which it is composed as a private
 * QVector data member.
 */
class Transaction
{
public:
    College college;                //!< Struct of college to represent colleges
    souvenirItem itemPurchased;     //!< Struct of souvenir items to track purchasing

    //! Overloaded Operator
    /*!
     * \brief operator == Overloads the 'equal to' operator for processing
     * \param other the items purchased to be compared for reassurance of correct item
     * \return A boolean that is true if this item is equal to the other item
     */
    bool operator==(Transaction &other);

    //! A Constructor
    /*!
     * \brief Transaction Sets the arguments that are
     * passed into the classes data members.
     * \param college - A struct argument
     * \param itemPurchased - A struct argument
     */
    Transaction(College college, souvenirItem itemPurchased);

    Transaction() {}    //!< Default Constructor
    ~Transaction() {}   //!< Default Constructor
};

/*! The Shopping Cart
 * \brief The Cart class
 *
 * The cart will handles the basics of purhcasing a collective
 * of items and has the capabilities to add and remove items at
 * user's will. Will rely upon functionality from transaction class.
 */
class Cart
{
public:
    Cart() {}   //!< Default Constructor

    int size();         //!< Function to return size of transactions vector
    void printCart();   //!< Prints out contents of transactions in cart

    /*! To add item to purchases
     * \brief addTransaction Will take item and corresponding college as
     * arguments and store into purchases
     * \param college - A struct argument
     * \param itemPurchased - A struct argument
     */
    void addTransaction(College college, souvenirItem itemPurchased);

    /*! To delete item from purchases
     * \brief deleteTransaction Will take selected transaction and
     * remove it from purchases.
     * \param transaction - A class argument
     */
    void deleteTransaction(Transaction transaction);

    double getTotal();           //!< Function to calculate total costs of purchases
    QVector<Transaction> getPurchases();    //!<Function to return dummy vector of purchases

private:
    QVector<Transaction> purchases; /*!< A QVector of the transactions that stores purchase from each college. Each
                                         transaction has the college that it occurred at, and the souvenirs purchased */
};

#endif // CART_H
