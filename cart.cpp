#include "cart.h"


/***************************************
 *  Transaction Class Functions
 **************************************/

/*! Constructor with parameters
 * \brief Transaction::Transaction
 * \param college - A struct argument
 * \param itemPurchased - A struct argument
 */
Transaction::Transaction(College college, souvenirItem itemPurchased)
{

    this->college = college;
    this->itemPurchased = itemPurchased;
}

/*! Overloaded Operator
 * \brief Transaction::operator ==
 * \param other - A class argument
 * \return boolean for if they are equivalent or not
 */
bool Transaction::operator==(Transaction& other)
{
    return ((other.itemPurchased.name == this->itemPurchased.name) && (other.college.id == this->college.id));
}



/***************************************
 *  Cart Class Functions
 **************************************/

/*!
 * \brief Cart::size
 * \return size of purchases vector
 */
int Cart::size()
{
    return purchases.size();
}

/*!
 * \brief Cart::printCart
 */
void Cart::printCart()
{
    if (this->purchases.size())
    {
        int index= 0;

        College college = purchases[index].college;

        while(index < purchases.size())
        {
            if (purchases[index].college.id != college.id)
            {
                college = purchases[index].college;
            }
            index++;
        }
    }
}

/*!
 * \brief Cart::addTransaction
 * \param college   - A struct argument
 * \param itemPurchased - A struct argument
 */
void Cart::addTransaction(College college, souvenirItem itemPurchased)
{
    Transaction newTrans = Transaction(college, itemPurchased);
    purchases.push_back(newTrans);
}

/*!
 * \brief Cart::deleteTransaction
 * \param transaction - A class argument
 */
void Cart::deleteTransaction(Transaction transaction)
{
    for (int index=0; index < purchases.size(); index++)
    {
        if (purchases[index] == transaction)
        {
            purchases.remove(index);
            break;
        }
    }
}

/*!
 * \brief Cart::getTotal
 * \return double value of total costs
 */
double Cart::getTotal()
{
    double total = 0;
    for (int index=0; index < purchases.size(); index++)
    {
        total += purchases[index].itemPurchased.price;
    }
    return total;
}

/*!
 * \brief Cart::getPurchases
 * \return vector of private data members to examine
 */
QVector<Transaction> Cart::getPurchases()
{
    QVector<Transaction> dummyVector;
    for(int i = 0; i < purchases.size(); i++)
    {
        dummyVector.append(purchases[i]);
    }
    return dummyVector;
}
