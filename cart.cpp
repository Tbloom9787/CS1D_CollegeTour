#include "cart.h"

Cart::Cart()
{

}
void Cart::addTransaction(College college, MenuItem itemPurchased)
{
    Transaction newTrans = Transaction(college, itemPurchased);
    purchases.push_back(newTrans);
}

void Cart::deleteTransaction(Transaction transaction)
{
    for (int index=0; index < purchases.size(); index++)
    {
        if (purchases[index] == transaction)
        {
            qDebug() << "Removing!";
            purchases.remove(index);
            break;
        }
    }
}


double Cart::getTotal()
{
    double total = 0;
    for (int index=0; index < purchases.size(); index++)
    {
        total += purchases[index].itemPurchased.price;
    }
    return total;
}
