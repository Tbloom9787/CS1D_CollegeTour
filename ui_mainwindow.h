/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *main_stacked_widget;
    QWidget *welcome_page;
    QPushButton *startButton;
    QLabel *welcome_label;
    QLabel *splash_background;
    QLabel *transparent_box;
    QLabel *transparent_box_2;
    QPushButton *ASU_trip_button;
    QPushButton *shortest_trip_button;
    QWidget *tours_page;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *choosing_label;
    QWidget *admin_login_page;
    QLabel *transparent_box_3;
    QLabel *error_label;
    QPushButton *back_button;
    QPushButton *login_button;
    QLineEdit *password_line_edit;
    QLineEdit *username_line_edit;
    QLabel *password_label;
    QLabel *username_label;
    QLabel *admin_login_label;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QLabel *maintenance_label;
    QWidget *maintenance_page;
    QListWidget *souvenir_list_widget;
    QFrame *line;
    QPushButton *exit_button;
    QFrame *line_2;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QPushButton *add_souvenir_button;
    QPushButton *upload_college_button;
    QLabel *header_label;
    QPushButton *header_icon_push_button;
    QPushButton *admin_push_button;
    QLabel *admin_label;
    QFrame *header_line;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QWidget *layoutWidget1;
    QFormLayout *formLayout_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(991, 755);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(991, 755));
        MainWindow->setMaximumSize(QSize(991, 755));
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        main_stacked_widget = new QStackedWidget(centralWidget);
        main_stacked_widget->setObjectName(QStringLiteral("main_stacked_widget"));
        main_stacked_widget->setGeometry(QRect(0, 130, 991, 571));
        sizePolicy.setHeightForWidth(main_stacked_widget->sizePolicy().hasHeightForWidth());
        main_stacked_widget->setSizePolicy(sizePolicy);
        main_stacked_widget->setMinimumSize(QSize(991, 571));
        main_stacked_widget->setMaximumSize(QSize(991, 571));
        main_stacked_widget->setStyleSheet(QStringLiteral("background-color:rgb(216, 215, 188)"));
        welcome_page = new QWidget();
        welcome_page->setObjectName(QStringLiteral("welcome_page"));
        welcome_page->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"font-family:'Harmonia Sans Pro, Lucia Bright,sans-serif';\n"
"font-size: 20px;\n"
"background-color:rgba(122,122,122,255);\n"
"color:white;\n"
"border-style:solid;\n"
"border-radius:10px;\n"
"}\n"
"\n"
"QPushButton::Hover\n"
"{\n"
"color:rgb(255, 255, 255);\n"
"background-color: qlineargradient(spread:pad, x1:0.517, y1:0, x2:0.517, y2:1, stop:0 rgba(122, 122, 122, 255), stop: 0.501 rgba(122, 122, 122, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color:rgb(255, 255, 255);\n"
"border-width:2px\n"
"}\n"
"\n"
"QPushButton::Pressed\n"
"{\n"
"	border-color: rgb(0, 0, 0);\n"
"}"));
        startButton = new QPushButton(welcome_page);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(130, 380, 201, 41));
        startButton->setStyleSheet(QStringLiteral(""));
        welcome_label = new QLabel(welcome_page);
        welcome_label->setObjectName(QStringLiteral("welcome_label"));
        welcome_label->setGeometry(QRect(380, 70, 271, 51));
        welcome_label->setStyleSheet(QLatin1String("background-color: rgba(31, 34, 31, .70);\n"
"border-radius: 10px;\n"
"color: white;"));
        welcome_label->setAlignment(Qt::AlignCenter);
        splash_background = new QLabel(welcome_page);
        splash_background->setObjectName(QStringLiteral("splash_background"));
        splash_background->setGeometry(QRect(0, -60, 1021, 691));
        splash_background->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/uclatest2.jpg")));
        transparent_box = new QLabel(welcome_page);
        transparent_box->setObjectName(QStringLiteral("transparent_box"));
        transparent_box->setGeometry(QRect(50, 340, 371, 121));
        transparent_box->setStyleSheet(QLatin1String("background-color: rgba(31, 34, 31, .70);\n"
"border-radius: 10px;\n"
"color: white;"));
        transparent_box_2 = new QLabel(welcome_page);
        transparent_box_2->setObjectName(QStringLiteral("transparent_box_2"));
        transparent_box_2->setGeometry(QRect(580, 340, 371, 121));
        transparent_box_2->setStyleSheet(QLatin1String("background-color: rgba(31, 34, 31, .70);\n"
"border-radius: 10px;\n"
"color: white;"));
        ASU_trip_button = new QPushButton(welcome_page);
        ASU_trip_button->setObjectName(QStringLiteral("ASU_trip_button"));
        ASU_trip_button->setGeometry(QRect(600, 380, 151, 41));
        shortest_trip_button = new QPushButton(welcome_page);
        shortest_trip_button->setObjectName(QStringLiteral("shortest_trip_button"));
        shortest_trip_button->setGeometry(QRect(780, 380, 151, 41));
        main_stacked_widget->addWidget(welcome_page);
        splash_background->raise();
        welcome_label->raise();
        transparent_box->raise();
        startButton->raise();
        transparent_box_2->raise();
        ASU_trip_button->raise();
        shortest_trip_button->raise();
        tours_page = new QWidget();
        tours_page->setObjectName(QStringLiteral("tours_page"));
        tours_page->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"font: 75 12pt \"Sitka\";\n"
"color: white;\n"
"background-color: rgba(31, 34, 31, .70);\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 5px;\n"
"border-radius:10px;\n"
"}\n"
"\n"
"QPushButton::Hover\n"
"{\n"
"border-color: rgb(255, 255, 255);\n"
"}"));
        gridLayoutWidget = new QWidget(tours_page);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(150, 150, 721, 381));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        choosing_label = new QLabel(tours_page);
        choosing_label->setObjectName(QStringLiteral("choosing_label"));
        choosing_label->setGeometry(QRect(260, 70, 511, 41));
        QFont font;
        font.setFamily(QStringLiteral("Georgia"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        choosing_label->setFont(font);
        choosing_label->setStyleSheet(QLatin1String("background-color: rgba(31, 34, 31, .70);\n"
"border-radius: 10px;\n"
"color: white;"));
        choosing_label->setFrameShape(QFrame::NoFrame);
        choosing_label->setFrameShadow(QFrame::Raised);
        choosing_label->setLineWidth(10);
        choosing_label->setTextFormat(Qt::PlainText);
        choosing_label->setAlignment(Qt::AlignCenter);
        main_stacked_widget->addWidget(tours_page);
        admin_login_page = new QWidget();
        admin_login_page->setObjectName(QStringLiteral("admin_login_page"));
        admin_login_page->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"font: 75 12pt \"Sitka\";\n"
"background-color: rgb(241, 241, 240);\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius:10px;\n"
"}\n"
"\n"
"QPushButton::Hover\n"
"{\n"
"border-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton::Pressed\n"
"{\n"
"border-color: rgb(0, 0, 255);\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"background-color: rgba(0, 61, 185, .01);\n"
"font: 75 12pt \"System\";\n"
"}\n"
"\n"
"QLineEdit\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
""));
        transparent_box_3 = new QLabel(admin_login_page);
        transparent_box_3->setObjectName(QStringLiteral("transparent_box_3"));
        transparent_box_3->setGeometry(QRect(310, 170, 371, 251));
        transparent_box_3->setStyleSheet(QLatin1String("background-color: rgba(0, 61, 185, .60);\n"
"border-radius: 10px;\n"
"color: white;"));
        error_label = new QLabel(admin_login_page);
        error_label->setObjectName(QStringLiteral("error_label"));
        error_label->setGeometry(QRect(350, 250, 281, 21));
        back_button = new QPushButton(admin_login_page);
        back_button->setObjectName(QStringLiteral("back_button"));
        back_button->setGeometry(QRect(400, 340, 201, 41));
        login_button = new QPushButton(admin_login_page);
        login_button->setObjectName(QStringLiteral("login_button"));
        login_button->setGeometry(QRect(400, 290, 201, 41));
        password_line_edit = new QLineEdit(admin_login_page);
        password_line_edit->setObjectName(QStringLiteral("password_line_edit"));
        password_line_edit->setGeometry(QRect(409, 218, 241, 20));
        password_line_edit->setEchoMode(QLineEdit::Password);
        username_line_edit = new QLineEdit(admin_login_page);
        username_line_edit->setObjectName(QStringLiteral("username_line_edit"));
        username_line_edit->setGeometry(QRect(409, 192, 241, 20));
        password_label = new QLabel(admin_login_page);
        password_label->setObjectName(QStringLiteral("password_label"));
        password_label->setGeometry(QRect(332, 218, 68, 16));
        password_label->setAutoFillBackground(false);
        password_label->setWordWrap(false);
        username_label = new QLabel(admin_login_page);
        username_label->setObjectName(QStringLiteral("username_label"));
        username_label->setGeometry(QRect(332, 192, 71, 16));
        admin_login_label = new QLabel(admin_login_page);
        admin_login_label->setObjectName(QStringLiteral("admin_login_label"));
        admin_login_label->setGeometry(QRect(320, 110, 351, 31));
        admin_login_label->setFrameShape(QFrame::WinPanel);
        admin_login_label->setAlignment(Qt::AlignCenter);
        line_3 = new QFrame(admin_login_page);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(310, 150, 371, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(admin_login_page);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(173, 30, 20, 521));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(admin_login_page);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(780, 30, 20, 521));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);
        maintenance_label = new QLabel(admin_login_page);
        maintenance_label->setObjectName(QStringLiteral("maintenance_label"));
        maintenance_label->setGeometry(QRect(236, 30, 501, 61));
        QFont font1;
        font1.setFamily(QStringLiteral("Times New Roman"));
        font1.setPointSize(26);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        maintenance_label->setFont(font1);
        maintenance_label->setStyleSheet(QLatin1String("background-color: rgba(31, 34, 31, .70);\n"
"border-radius: 10px;\n"
"color: white;\n"
"font: 75 bold 26pt \"Times New Roman\";"));
        maintenance_label->setAlignment(Qt::AlignCenter);
        main_stacked_widget->addWidget(admin_login_page);
        transparent_box_3->raise();
        back_button->raise();
        login_button->raise();
        password_line_edit->raise();
        username_line_edit->raise();
        error_label->raise();
        username_label->raise();
        password_label->raise();
        admin_login_label->raise();
        line_3->raise();
        line_4->raise();
        line_5->raise();
        maintenance_label->raise();
        maintenance_page = new QWidget();
        maintenance_page->setObjectName(QStringLiteral("maintenance_page"));
        maintenance_page->setStyleSheet(QLatin1String("QListWidget\n"
"{\n"
"background-color: rgba(31,31,31,.9);\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 5px;\n"
"border-radius: 10px;\n"
"color: white;\n"
"}\n"
"QPushButton\n"
"{\n"
"font: 75 12pt \"Sitka\";\n"
"background-color: rgb(241, 241, 240);\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius:10px;\n"
"}\n"
"\n"
"QPushButton::Hover\n"
"{\n"
"border-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton::Pressed\n"
"{\n"
"border-color: rgb(0, 0, 255);\n"
"}"));
        souvenir_list_widget = new QListWidget(maintenance_page);
        souvenir_list_widget->setObjectName(QStringLiteral("souvenir_list_widget"));
        souvenir_list_widget->setGeometry(QRect(370, 70, 511, 481));
        line = new QFrame(maintenance_page);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(290, 20, 21, 541));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        exit_button = new QPushButton(maintenance_page);
        exit_button->setObjectName(QStringLiteral("exit_button"));
        exit_button->setGeometry(QRect(100, 310, 111, 31));
        line_2 = new QFrame(maintenance_page);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(940, 20, 21, 541));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        frame = new QFrame(maintenance_page);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(40, 100, 241, 161));
        frame->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"font: 75 12pt \"Sitka\";\n"
"background-color: rgb(241, 241, 240);\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius:10px;\n"
"}\n"
"\n"
"QPushButton::Hover\n"
"{\n"
"border-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton::Pressed\n"
"{\n"
"border-color: rgb(0, 0, 255);\n"
"}\n"
"\n"
"QFrame\n"
"{\n"
"background-color: rgba(0, 61, 185, .60);\n"
"border-radius: 10px;\n"
"color: white;\n"
"}\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        add_souvenir_button = new QPushButton(frame);
        add_souvenir_button->setObjectName(QStringLiteral("add_souvenir_button"));
        add_souvenir_button->setMinimumSize(QSize(141, 51));

        gridLayout_2->addWidget(add_souvenir_button, 0, 0, 1, 1);

        upload_college_button = new QPushButton(frame);
        upload_college_button->setObjectName(QStringLiteral("upload_college_button"));
        upload_college_button->setMinimumSize(QSize(141, 51));

        gridLayout_2->addWidget(upload_college_button, 1, 0, 1, 1);

        main_stacked_widget->addWidget(maintenance_page);
        header_label = new QLabel(centralWidget);
        header_label->setObjectName(QStringLiteral("header_label"));
        header_label->setGeometry(QRect(0, 0, 991, 141));
        header_label->setMinimumSize(QSize(991, 141));
        header_label->setMaximumSize(QSize(991, 141));
        QFont font2;
        font2.setFamily(QStringLiteral("Sitka Banner"));
        font2.setPointSize(26);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setUnderline(false);
        font2.setWeight(75);
        header_label->setFont(font2);
        header_label->setStyleSheet(QLatin1String("QLabel {\n"
"background-color: rgb(84, 190, 255);\n"
"color: white;\n"
"}"));
        header_label->setFrameShape(QFrame::NoFrame);
        header_label->setFrameShadow(QFrame::Plain);
        header_label->setLineWidth(1);
        header_label->setMidLineWidth(0);
        header_label->setTextFormat(Qt::RichText);
        header_label->setAlignment(Qt::AlignCenter);
        header_icon_push_button = new QPushButton(centralWidget);
        header_icon_push_button->setObjectName(QStringLiteral("header_icon_push_button"));
        header_icon_push_button->setGeometry(QRect(0, 0, 211, 141));
        header_icon_push_button->setAutoFillBackground(false);
        header_icon_push_button->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-color: rgb(84, 190, 255);\n"
"border-style:solid;\n"
"border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton::Hover\n"
"{\n"
"color:rgb(255, 255, 255);\n"
"border-color:rgb(255, 255, 255);\n"
"border-width:2px\n"
"}\n"
"\n"
"QPushButton::Pressed\n"
"{\n"
"border-color: rgb(0, 0, 0);\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/headerIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        header_icon_push_button->setIcon(icon);
        header_icon_push_button->setIconSize(QSize(130, 200));
        admin_push_button = new QPushButton(centralWidget);
        admin_push_button->setObjectName(QStringLiteral("admin_push_button"));
        admin_push_button->setEnabled(true);
        admin_push_button->setGeometry(QRect(920, 1, 41, 44));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(admin_push_button->sizePolicy().hasHeightForWidth());
        admin_push_button->setSizePolicy(sizePolicy1);
        admin_push_button->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-color: rgb(84, 190, 255);\n"
"border-style:solid;\n"
"border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton::Hover\n"
"{\n"
"color:rgb(255, 255, 255);\n"
"border-color:rgb(255, 255, 255);\n"
"border-width:2px\n"
"}\n"
"\n"
"QPushButton::Pressed\n"
"{\n"
"border-color: rgb(0, 0, 0);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/admin.png"), QSize(), QIcon::Normal, QIcon::Off);
        admin_push_button->setIcon(icon1);
        admin_push_button->setIconSize(QSize(200, 200));
        admin_push_button->setCheckable(false);
        admin_label = new QLabel(centralWidget);
        admin_label->setObjectName(QStringLiteral("admin_label"));
        admin_label->setGeometry(QRect(910, 50, 61, 21));
        admin_label->setAutoFillBackground(false);
        admin_label->setStyleSheet(QLatin1String("background-color: rgb(84, 190, 255);\n"
""));
        admin_label->setFrameShape(QFrame::WinPanel);
        admin_label->setFrameShadow(QFrame::Plain);
        admin_label->setTextFormat(Qt::AutoText);
        admin_label->setAlignment(Qt::AlignCenter);
        admin_label->setWordWrap(true);
        header_line = new QFrame(centralWidget);
        header_line->setObjectName(QStringLiteral("header_line"));
        header_line->setGeometry(QRect(280, 100, 431, 16));
        header_line->setAutoFillBackground(false);
        header_line->setStyleSheet(QLatin1String("background-color: rgb(84, 190, 255);\n"
""));
        header_line->setFrameShadow(QFrame::Sunken);
        header_line->setLineWidth(2);
        header_line->setFrameShape(QFrame::HLine);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 2, 2));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 0, 2, 2));
        formLayout_2 = new QFormLayout(layoutWidget1);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 991, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        main_stacked_widget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        startButton->setText(QApplication::translate("MainWindow", "Start Custom Trip", Q_NULLPTR));
        welcome_label->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:600;\">Welcome!</span></p></body></html>", Q_NULLPTR));
        splash_background->setText(QString());
        transparent_box->setText(QString());
        transparent_box_2->setText(QString());
        ASU_trip_button->setText(QApplication::translate("MainWindow", "ASU Trip", Q_NULLPTR));
        shortest_trip_button->setText(QApplication::translate("MainWindow", "Shortest Trip", Q_NULLPTR));
        choosing_label->setText(QApplication::translate("MainWindow", "Let's start with choosing our starting campus!", Q_NULLPTR));
        transparent_box_3->setText(QString());
        error_label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:400; color:#ff0000;\">*Error* - Username/Password is incorrect!</span></p></body></html>", Q_NULLPTR));
        back_button->setText(QApplication::translate("MainWindow", "Back", Q_NULLPTR));
        login_button->setText(QApplication::translate("MainWindow", "Login", Q_NULLPTR));
        password_line_edit->setInputMask(QString());
        password_label->setText(QApplication::translate("MainWindow", "Password:", Q_NULLPTR));
        username_label->setText(QApplication::translate("MainWindow", "Username:", Q_NULLPTR));
        admin_login_label->setText(QApplication::translate("MainWindow", "Please enter your login credentials", Q_NULLPTR));
        maintenance_label->setText(QApplication::translate("MainWindow", "Maintenance Login", Q_NULLPTR));
        exit_button->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        add_souvenir_button->setText(QApplication::translate("MainWindow", "Add Souvenir", Q_NULLPTR));
        upload_college_button->setText(QApplication::translate("MainWindow", "Upload College from File", Q_NULLPTR));
        header_label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:36pt;\">College Tour Planner</span></p></body></html>", Q_NULLPTR));
        header_icon_push_button->setText(QString());
        admin_push_button->setText(QString());
        admin_label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">ADMIN</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
