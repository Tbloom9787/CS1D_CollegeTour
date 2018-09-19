#ifndef CART_H
#define CART_H

#include "databasemanager.h"

//! The Transaction Handler
/*!
  The proccessing for the transactions of items.
  It is to be composed into the class Cart as
  a private QVector data member.
 */

class Transaction {
public:
    College college;                 //!< Struct of college to have access to its members
    MenuItem itemPurchased;                //!< Struct of menu items to know what the user purchased

    //! A Constructor
    /*!
     * \brief Transaction Sets the arguments that are
     * passed into the classes data members.
     * \param college A struct argument
     * \param itemPurchased A struct argument
     */
    Transaction(College college, MenuItem itemPurchased)
    {

        this->college = college;
        this->itemPurchased = itemPurchased;
    }


    //! Overloaded Operator
    /*!
     * \brief operator == Overloads the 'equal to' operator for processing
     * \param other the items purchased to be compared for reassurance of correct item
     * \return A boolean that is true if this item is equal to the other item
     */
    bool operator==(Transaction& other)
    {
        return ((other.itemPurchased.name == this->itemPurchased.name) && (other.college.id == this->college.id));
    }

    Transaction() {}
    ~Transaction() {}

};


//! The Shopping Cart
/*!
  The shopping cart handles the basic
  capabilities of your standard shopping cart.
  It is able to add or delete a transaction and
  display the total cost and items in cart.
 */

class Cart
{
private:
    QVector<Transaction> purchases;        /*!< A QVector of the transactions that stores purchase from each college. Each
                                                transaction has the college that it occurred at, and the menu items purchased */

public:
    friend class TripWindow;         //!< A class that will display the total costs from all visited colleges in a new window

    Cart();

    //! The size of transactions vector
    /*!
     * \brief size Used for proccessing.
     * \return Will return vector size as int
     */
    int size()
    {
        return purchases.size();
    }

    //! To print shopping cart transactions to console
    /*!
     * \brief printCart Will print out the transactions
     * for each college visited.
     */
    void printCart()
    {
        if (this->purchases.size())
        {
            int index= 0;

            College college = purchases[index].college;
            qDebug() << "Transactions for college: " << college.name;
            while(index < purchases.size())
            {
                if (purchases[index].college.id != college.id)
                {

                    college = purchases[index].college;
                    qDebug() << "\nTransactions for College: " << college.name;
                }
                qDebug() << purchases[index].itemPurchased.name;
                index++;
            }
        }
    }

    //! To add an item to purchased list
    /*!
     * \brief addTransaction It will take the menu item and
     * corresponding college as arguments and store them into purchases.
     * \param college A struct argument
     * \param itemPurchased A struct argument
     */
    void addTransaction(College college, MenuItem itemPurchased);

    //! To delete an item from purchased list
    /*!
     * \brief deleteTransaction It will take all the current
     * transaction that was made as a mistake and delete it from
     * the purchases.
     * \param transaction A struct argument
     */
    void deleteTransaction(Transaction transaction);

    //! To get the total cost
    /*!
     * \brief getTotal It will calculate the total cost
     * for the trip of purchased menu items.
     * \return A double of the total cost
     */
    double getTotal();
};

#endif // CART_H
