#ifndef TOTALSSHEET_H
#define TOTALSSHEET_H

#include <QDialog>
#include "cart.h"

namespace Ui {
class totalsSheet;
}

/*! TotalsSheet Class
 * \brief The totalsSheet class
 * UI to display the expenses and invoice
 * from the trip at the time it was invoked
 */
class totalsSheet : public QDialog
{
    Q_OBJECT

public:
    explicit totalsSheet(Cart cartInfo, QWidget *parent = 0);   //! Constructor
    ~totalsSheet(); //! Default Destructor

private:
    Ui::totalsSheet *ui;    //! UI that displays information from trip
    Cart cart;              //! Cart class of information to be displayed
};

#endif // TOTALSSHEET_H
