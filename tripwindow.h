#ifndef TRIPWINDOW_H
#define TRIPWINDOW_H

#include <QDialog>
#include "cart.h"
namespace Ui {
class TripWindow;
}

class TripWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TripWindow(Cart newShoppingCart, QWidget *parent = 0);
    ~TripWindow();
friend class Cart;
private:
    Ui::TripWindow *ui;
    Cart shoppingCart;
};

#endif // TRIPWINDOW_H
