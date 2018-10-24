/********************************************************************************
** Form generated from reading UI file 'collegemodel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLLEGEMODEL_H
#define UI_COLLEGEMODEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CollegeModel
{
public:
    QStackedWidget *college_model_stacked_widget;
    QWidget *trip_page;
    QPushButton *next_college_button;
    QGroupBox *souvenir_group_box;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *trip_distance_label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *totals_label;
    QPushButton *totals_button;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_5;
    QFrame *line_5;
    QLabel *college_name_label;
    QFrame *line_6;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QListWidget *cartList;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *removeCartItemButton;
    QSpacerItem *horizontalSpacer_2;
    QWidget *loading_page;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_3;
    QFrame *line;
    QSpacerItem *horizontalSpacer_5;
    QLabel *loading_gif;
    QSpacerItem *horizontalSpacer_6;
    QFrame *line_2;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_4;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *loading_label;
    QSpacerItem *horizontalSpacer_4;
    QFrame *line_4;

    void setupUi(QWidget *CollegeModel)
    {
        if (CollegeModel->objectName().isEmpty())
            CollegeModel->setObjectName(QStringLiteral("CollegeModel"));
        CollegeModel->resize(904, 561);
        CollegeModel->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 205);"));
        college_model_stacked_widget = new QStackedWidget(CollegeModel);
        college_model_stacked_widget->setObjectName(QStringLiteral("college_model_stacked_widget"));
        college_model_stacked_widget->setGeometry(QRect(10, 20, 871, 521));
        college_model_stacked_widget->setStyleSheet(QStringLiteral(""));
        trip_page = new QWidget();
        trip_page->setObjectName(QStringLiteral("trip_page"));
        trip_page->setStyleSheet(QLatin1String("QGroupBox\n"
"{\n"
"font: 75 italic 20pt \"Cambria\";\n"
"border: 2px solid black;\n"
"border-radius: 11px; \n"
"margin-top: 0.5em;\n"
"background: #e9e9e9;\n"
"}\n"
"\n"
"QGroupBox::title\n"
"{\n"
"    subcontrol-origin: margin;\n"
"    left: 10px;\n"
"    padding: 0 3px 0 3px;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"font: 75 14pt \"Cambria\";\n"
"color: white;\n"
"background-color: rgba(31, 34, 31, .70);\n"
"border-style: solid;\n"
"border-color:black;\n"
"border-width: 5px;\n"
"border-radius:10px;\n"
"}\n"
"\n"
"QPushButton::Hover\n"
"{\n"
"border-color:white;\n"
"}\n"
"\n"
"QPushButton::Pressed\n"
"{\n"
"border-color:black;\n"
"}"));
        next_college_button = new QPushButton(trip_page);
        next_college_button->setObjectName(QStringLiteral("next_college_button"));
        next_college_button->setGeometry(QRect(280, 440, 281, 71));
        souvenir_group_box = new QGroupBox(trip_page);
        souvenir_group_box->setObjectName(QStringLiteral("souvenir_group_box"));
        souvenir_group_box->setGeometry(QRect(580, 80, 291, 431));
        souvenir_group_box->setStyleSheet(QStringLiteral(""));
        souvenir_group_box->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        verticalLayoutWidget = new QWidget(souvenir_group_box);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 30, 271, 391));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);

        verticalLayout->addLayout(gridLayout);

        trip_distance_label = new QLabel(trip_page);
        trip_distance_label->setObjectName(QStringLiteral("trip_distance_label"));
        trip_distance_label->setGeometry(QRect(11, 83, 351, 22));
        trip_distance_label->setStyleSheet(QStringLiteral("font: 75 14pt \"Arial\";"));
        layoutWidget = new QWidget(trip_page);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(330, 310, 181, 101));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        totals_label = new QLabel(layoutWidget);
        totals_label->setObjectName(QStringLiteral("totals_label"));
        totals_label->setStyleSheet(QStringLiteral("font: 75 16pt \"Arial\";"));
        totals_label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(totals_label);

        totals_button = new QPushButton(layoutWidget);
        totals_button->setObjectName(QStringLiteral("totals_button"));

        verticalLayout_2->addWidget(totals_button);

        layoutWidget1 = new QWidget(trip_page);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 851, 71));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        line_5 = new QFrame(layoutWidget1);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setMaximumSize(QSize(250, 16777215));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(line_5);

        college_name_label = new QLabel(layoutWidget1);
        college_name_label->setObjectName(QStringLiteral("college_name_label"));
        college_name_label->setStyleSheet(QLatin1String("font: 75 italic 26pt \"Sitka\";\n"
"color:white;\n"
"background-color: rgb(30, 26, 152, 150);\n"
"border-style:solid;\n"
"border-color: rgb(0, 0, 0);\n"
"border-radius:25px;\n"
""));
        college_name_label->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(college_name_label);

        line_6 = new QFrame(layoutWidget1);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setMaximumSize(QSize(250, 16777215));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(line_6);

        layoutWidget2 = new QWidget(trip_page);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(11, 111, 249, 381));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        cartList = new QListWidget(layoutWidget2);
        cartList->setObjectName(QStringLiteral("cartList"));

        verticalLayout_3->addWidget(cartList);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        removeCartItemButton = new QPushButton(layoutWidget2);
        removeCartItemButton->setObjectName(QStringLiteral("removeCartItemButton"));

        horizontalLayout->addWidget(removeCartItemButton);

        horizontalSpacer_2 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout);

        college_model_stacked_widget->addWidget(trip_page);
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        souvenir_group_box->raise();
        next_college_button->raise();
        trip_distance_label->raise();
        loading_page = new QWidget();
        loading_page->setObjectName(QStringLiteral("loading_page"));
        loading_page->setStyleSheet(QStringLiteral("background-color: rgb(229, 229, 229);"));
        layoutWidget3 = new QWidget(loading_page);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(40, 90, 791, 421));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        line = new QFrame(layoutWidget3);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(5);
        line->setFrameShape(QFrame::VLine);

        horizontalLayout_3->addWidget(line);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        loading_gif = new QLabel(layoutWidget3);
        loading_gif->setObjectName(QStringLiteral("loading_gif"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(loading_gif->sizePolicy().hasHeightForWidth());
        loading_gif->setSizePolicy(sizePolicy);
        loading_gif->setMinimumSize(QSize(679, 419));
        loading_gif->setMaximumSize(QSize(679, 419));
        loading_gif->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/driving.gif")));

        horizontalLayout_3->addWidget(loading_gif);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        line_2 = new QFrame(layoutWidget3);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(5);
        line_2->setFrameShape(QFrame::VLine);

        horizontalLayout_3->addWidget(line_2);

        layoutWidget4 = new QWidget(loading_page);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(40, 20, 791, 71));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        line_3 = new QFrame(layoutWidget4);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        loading_label = new QLabel(layoutWidget4);
        loading_label->setObjectName(QStringLiteral("loading_label"));
        loading_label->setStyleSheet(QLatin1String("font: 63 22pt \"Yu Gothic UI Semibold\";\n"
"background-color: rgba(255, 66, 41, .6);\n"
"border-radius: 30px;"));
        loading_label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(loading_label);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        line_4 = new QFrame(layoutWidget4);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line_4);

        college_model_stacked_widget->addWidget(loading_page);

        retranslateUi(CollegeModel);

        college_model_stacked_widget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CollegeModel);
    } // setupUi

    void retranslateUi(QWidget *CollegeModel)
    {
        CollegeModel->setWindowTitle(QApplication::translate("CollegeModel", "Form", Q_NULLPTR));
        next_college_button->setText(QApplication::translate("CollegeModel", "Next College", Q_NULLPTR));
        souvenir_group_box->setTitle(QApplication::translate("CollegeModel", "Souvenirs:", Q_NULLPTR));
        trip_distance_label->setText(QApplication::translate("CollegeModel", "Trip Distance: 0 miles", Q_NULLPTR));
        totals_label->setText(QApplication::translate("CollegeModel", "Total: $0", Q_NULLPTR));
        totals_button->setText(QApplication::translate("CollegeModel", "Review Purchases", Q_NULLPTR));
        college_name_label->setText(QApplication::translate("CollegeModel", "College Name", Q_NULLPTR));
        removeCartItemButton->setText(QApplication::translate("CollegeModel", "Remove", Q_NULLPTR));
        loading_gif->setText(QString());
        loading_label->setText(QApplication::translate("CollegeModel", "LOADING...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CollegeModel: public Ui_CollegeModel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLLEGEMODEL_H
