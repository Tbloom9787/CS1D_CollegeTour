#include "tripwindow.h"
#include "ui_tripwindow.h"
TripWindow::TripWindow(Cart newShoppingCart, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TripWindow)
{
    ui->setupUi(this);
    this->shoppingCart = newShoppingCart;
    shoppingCart.printCart();
    QVector<Transaction> purchases = shoppingCart.purchases;

    College currCollege = purchases.front().college;
    QListWidgetItem* newLabel = new QListWidgetItem("Shopping cart for college: " + currCollege.name);
    newLabel->setBackgroundColor(Qt::red);
    ui->totalsListWidget->addItem(newLabel);
    double collegeTotal = 0;
    for (int index = 0; index < shoppingCart.size(); index++)
    {
        if (purchases[index].college.id != currCollege.id)
        {
            ui->totalsListWidget->addItem("Total: $" + QString::number(collegeTotal, 'f', 2) + "\n");
            collegeTotal = 0;
            currCollege = purchases[index].college;
            QListWidgetItem* newLabel = new QListWidgetItem("Shopping cart for college: " + currCollege.name);
            newLabel->setBackgroundColor(Qt::red);
            ui->totalsListWidget->addItem(newLabel);
        }
        souvenirItem itemPurchased = purchases[index].itemPurchased;
        collegeTotal += itemPurchased.price;
        ui->totalsListWidget->addItem("  °  " + itemPurchased.name + " - $" + QString::number(itemPurchased.price, 'f', 2));

    }
    ui->totalsListWidget->addItem("Total: $" + QString::number(collegeTotal, 'f', 2) + "\n");
    ui->totalsListWidget->addItem("Grand total: $" + QString::number(shoppingCart.getTotal(), 'f', 2));
}

TripWindow::~TripWindow()
{
    delete ui;
}
