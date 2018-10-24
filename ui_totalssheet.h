/********************************************************************************
** Form generated from reading UI file 'totalssheet.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOTALSSHEET_H
#define UI_TOTALSSHEET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_totalsSheet
{
public:
    QGridLayout *gridLayout;
    QListWidget *totals_list;

    void setupUi(QDialog *totalsSheet)
    {
        if (totalsSheet->objectName().isEmpty())
            totalsSheet->setObjectName(QStringLiteral("totalsSheet"));
        totalsSheet->resize(402, 323);
        gridLayout = new QGridLayout(totalsSheet);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        totals_list = new QListWidget(totalsSheet);
        totals_list->setObjectName(QStringLiteral("totals_list"));

        gridLayout->addWidget(totals_list, 0, 0, 1, 1);


        retranslateUi(totalsSheet);

        QMetaObject::connectSlotsByName(totalsSheet);
    } // setupUi

    void retranslateUi(QDialog *totalsSheet)
    {
        totalsSheet->setWindowTitle(QApplication::translate("totalsSheet", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class totalsSheet: public Ui_totalsSheet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOTALSSHEET_H
