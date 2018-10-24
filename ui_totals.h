/********************************************************************************
** Form generated from reading UI file 'totals.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOTALS_H
#define UI_TOTALS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_totals
{
public:
    QListWidget *totals_list;

    void setupUi(QWidget *totals)
    {
        if (totals->objectName().isEmpty())
            totals->setObjectName(QStringLiteral("totals"));
        totals->resize(400, 345);
        totals_list = new QListWidget(totals);
        totals_list->setObjectName(QStringLiteral("totals_list"));
        totals_list->setGeometry(QRect(60, 20, 281, 301));

        retranslateUi(totals);

        QMetaObject::connectSlotsByName(totals);
    } // setupUi

    void retranslateUi(QWidget *totals)
    {
        totals->setWindowTitle(QApplication::translate("totals", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class totals: public Ui_totals {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOTALS_H
