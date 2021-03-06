#include "totals.h"
#include "ui_totals.h"

totals::totals(Cart cartInfo, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::totals)
{
    ui->setupUi(this);
    this->cart = cartInfo;
    cart.printCart();
    QVector<Transaction> purchases = cart.getPurchases();

    College currentCollege = purchases.front().college;
    QListWidgetItem *newLabel = new QListWidgetItem("Cart for college: " + currentCollege.name);


    newLabel->setBackgroundColor(Qt::red);
    ui->totals_list->addItem(newLabel);
    double collegeTotal = 0;
    for (int index = 0; index < cart.size(); index++)
    {
        if (purchases[index].college.id != currentCollege.id)
        {
            ui->totals_list->addItem("Total: $" + QString::number(collegeTotal, 'f', 2) + "\n");
            collegeTotal = 0;
            currentCollege = purchases[index].college;
            QListWidgetItem* newLabel = new QListWidgetItem("Shopping cart for college: " + currentCollege.name);
            newLabel->setBackgroundColor(Qt::red);
            ui->totals_list->addItem(newLabel);
        }
        souvenirItem itemPurchased = purchases[index].itemPurchased;
        collegeTotal += itemPurchased.price;
        ui->totals_list->addItem("  °  " + itemPurchased.name + " - $" + QString::number(itemPurchased.price, 'f', 2));

    }
    ui->totals_list->addItem("Total: $" + QString::number(collegeTotal, 'f', 2) + "\n");
    ui->totals_list->addItem("Grand total: $" + QString::number(cart.getTotal(), 'f', 2));
}


totals::~totals()
{
    delete ui;
}
