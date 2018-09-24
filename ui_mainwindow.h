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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Trip;
    QAction *adminLoginAction;
    QAction *actionNew;
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *splashPage;
    QLabel *welcomeLabel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *adminLoginButton_2;
    QPushButton *beginTripButton;
    QLabel *copyrightLabel;
    QWidget *mainMenuPage;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *planTripFromSaddlebackButton;
    QPushButton *mostEffecientTripFromUCIButton;
    QWidget *adminLoginPage;
    QWidget *layoutWidget1;
    QVBoxLayout *adminLoginLayout;
    QLabel *loginTitleLabel;
    QLabel *loginErrorLabel;
    QLineEdit *usernameInput;
    QLineEdit *passwordInput;
    QPushButton *adminLoginButton;
    QPushButton *loginPageBackButton;
    QWidget *adminPanelPage;
    QFrame *CollegeOperationsFrame;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *collegeOperationsLayout;
    QPushButton *newCollegeButton;
    QPushButton *addNewMenuItemButton;
    QLabel *menuItemsLabel;
    QListWidget *menuItemsListWidget;
    QLabel *label_2;
    QPushButton *adminPageBackButton;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuNew_Trip;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(583, 744);
        MainWindow->setWindowOpacity(1);
        MainWindow->setStyleSheet(QLatin1String("QToolTip {\n"
"    border: 1px solid #76797C;\n"
"    background-color: #5A7566;\n"
"    color: white;\n"
"    padding: 0px;                /*remove padding, for fix combobox tooltip.*/\n"
"    opacity: 200;\n"
"}\n"
"\n"
"QWidget {\n"
"    background: qlineargradient(x1:0 y1:0, x2:1 y2:0, stop:0 #000000, stop:1 #434343);\n"
"\n"
"    selection-background-color: #3daee9;\n"
"    selection-color: #eff0f1;\n"
"    background-clip: border;\n"
"    border-image: none;\n"
"    border: 0px transparent black;\n"
"    outline: 0;\n"
"}\n"
"QHBoxLayout {\n"
"    background-color:black;\n"
"}\n"
"\n"
"QWidget:item:hover {\n"
"    background-color: #18465d;\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
"QWidget:item:selected {\n"
"    background-color: #18465d;\n"
"}\n"
"\n"
"QCheckBox {\n"
"    spacing: 5px;\n"
"    outline: none;\n"
"    color: #eff0f1;\n"
"    margin-bottom: 2px;\n"
"}\n"
"\n"
"QCheckBox:disabled {\n"
"    color: #76797C;\n"
"}\n"
"\n"
"QCheckBox::indicator,\n"
"QGroupBox::indicator {\n"
"    width: 18px;\n"
""
                        "    height: 18px;\n"
"}\n"
"\n"
"QGroupBox::indicator {\n"
"    margin-left: 2px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"    image: url(:/qss_icons/rc/checkbox_unchecked.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover,\n"
"QCheckBox::indicator:unchecked:focus,\n"
"QCheckBox::indicator:unchecked:pressed,\n"
"QGroupBox::indicator:unchecked:hover,\n"
"QGroupBox::indicator:unchecked:focus,\n"
"QGroupBox::indicator:unchecked:pressed {\n"
"    border: none;\n"
"    image: url(:/qss_icons/rc/checkbox_unchecked_focus.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    image: url(:/qss_icons/rc/checkbox_checked.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:hover,\n"
"QCheckBox::indicator:checked:focus,\n"
"QCheckBox::indicator:checked:pressed,\n"
"QGroupBox::indicator:checked:hover,\n"
"QGroupBox::indicator:checked:focus,\n"
"QGroupBox::indicator:checked:pressed {\n"
"    border: none;\n"
"    image: url(:/qss_icons/rc/checkbox_checked_focus.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:i"
                        "ndeterminate {\n"
"    image: url(:/qss_icons/rc/checkbox_indeterminate.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:indeterminate:focus,\n"
"QCheckBox::indicator:indeterminate:hover,\n"
"QCheckBox::indicator:indeterminate:pressed {\n"
"    image: url(:/qss_icons/rc/checkbox_indeterminate_focus.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:disabled,\n"
"QGroupBox::indicator:checked:disabled {\n"
"    image: url(:/qss_icons/rc/checkbox_checked_disabled.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:disabled,\n"
"QGroupBox::indicator:unchecked:disabled {\n"
"    image: url(:/qss_icons/rc/checkbox_unchecked_disabled.png);\n"
"}\n"
"\n"
"QRadioButton {\n"
"    spacing: 5px;\n"
"    outline: none;\n"
"    color: #eff0f1;\n"
"    margin-bottom: 2px;\n"
"}\n"
"\n"
"QRadioButton:disabled {\n"
"    color: #76797C;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width: 21px;\n"
"    height: 21px;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked {\n"
"    image: url(:/qss_icons/rc/radio_unchecked.png);\n"
"}\n"
"\n"
""
                        "QRadioButton::indicator:unchecked:hover,\n"
"QRadioButton::indicator:unchecked:focus,\n"
"QRadioButton::indicator:unchecked:pressed {\n"
"    border: none;\n"
"    outline: none;\n"
"    image: url(:/qss_icons/rc/radio_unchecked_focus.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    border: none;\n"
"    outline: none;\n"
"    image: url(:/qss_icons/rc/radio_checked.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:hover,\n"
"QRadioButton::indicator:checked:focus,\n"
"QRadioButton::indicator:checked:pressed {\n"
"    border: none;\n"
"    outline: none;\n"
"    image: url(:/qss_icons/rc/radio_checked_focus.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:disabled {\n"
"    outline: none;\n"
"    image: url(:/qss_icons/rc/radio_checked_disabled.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:disabled {\n"
"    image: url(:/qss_icons/rc/radio_unchecked_disabled.png);\n"
"}\n"
"\n"
"QMenuBar {\n"
"    background-color: #31363b;\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
"QMenuBar::item {\n"
""
                        "    background: transparent;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background: transparent;\n"
"    border: 1px solid #76797C;\n"
"}\n"
"\n"
"QMenuBar::item:pressed {\n"
"    border: 1px solid #76797C;\n"
"    background-color: #3daee9;\n"
"    color: #eff0f1;\n"
"    margin-bottom: -1px;\n"
"    padding-bottom: 1px;\n"
"}\n"
"\n"
"QMenu {\n"
"    border: 1px solid #76797C;\n"
"    color: #eff0f1;\n"
"    margin: 2px;\n"
"}\n"
"\n"
"QMenu::icon {\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QMenu::item {\n"
"    padding: 5px 30px 5px 30px;\n"
"    border: 1px solid transparent;\n"
"    /* reserve space for selection border */\n"
"}\n"
"\n"
"QMenu::item:selected {\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
"QMenu::separator {\n"
"    height: 2px;\n"
"    background: lightblue;\n"
"    margin-left: 10px;\n"
"    margin-right: 5px;\n"
"}\n"
"\n"
"QMenu::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"}\n"
"\n"
"\n"
"/* non-exclusive indicator = check box style indicator\n"
"   (see QActionGroup::setExclus"
                        "ive) */\n"
"\n"
"QMenu::indicator:non-exclusive:unchecked {\n"
"    image: url(:/qss_icons/rc/checkbox_unchecked.png);\n"
"}\n"
"\n"
"QMenu::indicator:non-exclusive:unchecked:selected {\n"
"    image: url(:/qss_icons/rc/checkbox_unchecked_disabled.png);\n"
"}\n"
"\n"
"QMenu::indicator:non-exclusive:checked {\n"
"    image: url(:/qss_icons/rc/checkbox_checked.png);\n"
"}\n"
"\n"
"QMenu::indicator:non-exclusive:checked:selected {\n"
"    image: url(:/qss_icons/rc/checkbox_checked_disabled.png);\n"
"}\n"
"\n"
"\n"
"/* exclusive indicator = radio button style indicator (see QActionGroup::setExclusive) */\n"
"\n"
"QMenu::indicator:exclusive:unchecked {\n"
"    image: url(:/qss_icons/rc/radio_unchecked.png);\n"
"}\n"
"\n"
"QMenu::indicator:exclusive:unchecked:selected {\n"
"    image: url(:/qss_icons/rc/radio_unchecked_disabled.png);\n"
"}\n"
"\n"
"QMenu::indicator:exclusive:checked {\n"
"    image: url(:/qss_icons/rc/radio_checked.png);\n"
"}\n"
"\n"
"QMenu::indicator:exclusive:checked:selected {\n"
"    image: url"
                        "(:/qss_icons/rc/radio_checked_disabled.png);\n"
"}\n"
"\n"
"QMenu::right-arrow {\n"
"    margin: 5px;\n"
"    image: url(:/qss_icons/rc/right_arrow.png)\n"
"}\n"
"\n"
"QWidget:disabled {\n"
"    color: #454545;\n"
"    background-color: #31363b;\n"
"}\n"
"\n"
"QAbstractItemView {\n"
"    alternate-background-color: #31363b;\n"
"    color: #eff0f1;\n"
"    border: 1px solid #3A3939;\n"
"    border-radius: 2px;\n"
"}\n"
"\n"
"QWidget:focus,\n"
"QMenuBar:focus {\n"
"    border: 1px solid #3daee9;\n"
"}\n"
"\n"
"QTabWidget:focus,\n"
"QCheckBox:focus,\n"
"QRadioButton:focus,\n"
"QSlider:focus {\n"
"    border: none;\n"
"}\n"
"\n"
"QLineEdit {\n"
"    background-color: #232629;\n"
"    padding: 5px;\n"
"    border-style: solid;\n"
"    border: 1px solid #76797C;\n"
"    border-radius: 2px;\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
"QAbstractItemView QLineEdit {\n"
"    padding: 0;\n"
"}\n"
"\n"
"QGroupBox {\n"
"    border: 1px solid #76797C;\n"
"    border-radius: 2px;\n"
"    margin-top: 20px;\n"
"}\n"
"\n"
"QGroupBox:"
                        ":title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding-left: 10px;\n"
"    padding-right: 10px;\n"
"    padding-top: 10px;\n"
"}\n"
"\n"
"QAbstractScrollArea {\n"
"    border-radius: 2px;\n"
"    border: 1px solid #76797C;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    height: 15px;\n"
"    margin: 3px 15px 3px 15px;\n"
"    border: 1px transparent #2A2929;\n"
"    border-radius: 4px;\n"
"    background-color: #2A2929;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background-color: #605F5F;\n"
"    min-width: 5px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal {\n"
"    margin: 0px 3px 0px 3px;\n"
"    border-image: url(:/qss_icons/rc/right_arrow_disabled.png);\n"
"    width: 10px;\n"
"    height: 10px;\n"
"    subcontrol-position: right;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal {\n"
"    margin: 0px 3px 0px 3px;\n"
"    border-image: url(:/qss_icons"
                        "/rc/left_arrow_disabled.png);\n"
"    height: 10px;\n"
"    width: 10px;\n"
"    subcontrol-position: left;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal:hover,\n"
"QScrollBar::add-line:horizontal:on {\n"
"    border-image: url(:/qss_icons/rc/right_arrow.png);\n"
"    height: 10px;\n"
"    width: 10px;\n"
"    subcontrol-position: right;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal:hover,\n"
"QScrollBar::sub-line:horizontal:on {\n"
"    border-image: url(:/qss_icons/rc/left_arrow.png);\n"
"    height: 10px;\n"
"    width: 10px;\n"
"    subcontrol-position: left;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::up-arrow:horizontal,\n"
"QScrollBar::down-arrow:horizontal {\n"
"    background: none;\n"
"}\n"
"\n"
"QScrollBar::add-page:horizontal,\n"
"QScrollBar::sub-page:horizontal {\n"
"    background: none;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    background-color: #2A2929;\n"
"    width: 15px;\n"
"    margin: 15px 3px 15px"
                        " 3px;\n"
"    border: 1px transparent #2A2929;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background-color: #605F5F;\n"
"    min-height: 5px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical {\n"
"    margin: 3px 0px 3px 0px;\n"
"    border-image: url(:/qss_icons/rc/up_arrow_disabled.png);\n"
"    height: 10px;\n"
"    width: 10px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical {\n"
"    margin: 3px 0px 3px 0px;\n"
"    border-image: url(:/qss_icons/rc/down_arrow_disabled.png);\n"
"    height: 10px;\n"
"    width: 10px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical:hover,\n"
"QScrollBar::sub-line:vertical:on {\n"
"    border-image: url(:/qss_icons/rc/up_arrow.png);\n"
"    height: 10px;\n"
"    width: 10px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-line:ver"
                        "tical:hover,\n"
"QScrollBar::add-line:vertical:on {\n"
"    border-image: url(:/qss_icons/rc/down_arrow.png);\n"
"    height: 10px;\n"
"    width: 10px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::up-arrow:vertical,\n"
"QScrollBar::down-arrow:vertical {\n"
"    background: none;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical,\n"
"QScrollBar::sub-page:vertical {\n"
"    background: none;\n"
"}\n"
"\n"
"QTextEdit {\n"
"    background-color: #232629;\n"
"    color: #eff0f1;\n"
"    border: 1px solid #76797C;\n"
"}\n"
"\n"
"QPlainTextEdit {\n"
"    background-color: #232629;\n"
"    ;\n"
"    color: #eff0f1;\n"
"    border-radius: 2px;\n"
"    border: 1px solid #76797C;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #76797C;\n"
"    color: #eff0f1;\n"
"    padding: 5px;\n"
"    border: 1px solid #76797C;\n"
"}\n"
"\n"
"QSizeGrip {\n"
"    image: url(:/qss_icons/rc/sizegrip.png);\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
"\n"
"QMainWind"
                        "ow::separator {\n"
"    background-color: #31363b;\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    spacing: 2px;\n"
"    border: 1px dashed #76797C;\n"
"}\n"
"\n"
"QMainWindow::separator:hover {\n"
"    background-color: #787876;\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #76797C;\n"
"    spacing: 2px;\n"
"}\n"
"\n"
"QMenu::separator {\n"
"    height: 1px;\n"
"    background-color: #76797C;\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    margin-left: 10px;\n"
"    margin-right: 5px;\n"
"}\n"
"\n"
"QFrame {\n"
"    border-radius: 2px;\n"
"    border: 1px solid #76797C;\n"
"}\n"
"\n"
"QFrame[frameShape=\"0\"] {\n"
"    border-radius: 2px;\n"
"    border: 1px transparent #76797C;\n"
"}\n"
"\n"
"QStackedWidget {\n"
"    border: 1px transparent black;\n"
"}\n"
"\n"
"QToolBar {\n"
"    border: 1px transparent #393838;\n"
"    background: 1px solid #31363b;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QToolBar::handle:horizontal {\n"
"    image: url(:/qss_icons/rc/Hmovet"
                        "oolbar.png);\n"
"}\n"
"\n"
"QToolBar::handle:vertical {\n"
"    image: url(:/qss_icons/rc/Vmovetoolbar.png);\n"
"}\n"
"\n"
"QToolBar::separator:horizontal {\n"
"    image: url(:/qss_icons/rc/Hsepartoolbar.png);\n"
"}\n"
"\n"
"QToolBar::separator:vertical {\n"
"    image: url(:/qss_icons/rc/Vsepartoolbar.png);\n"
"}\n"
"\n"
"QToolButton#qt_toolbar_ext_button {\n"
"    background: #58595a\n"
"}\n"
"\n"
"QPushButton {\n"
"    color: white;\n"
"    background: qlineargradient(x1:0 y1:0, x2:1 y2:0, stop:0 #333333, stop:1 #dd1818);\n"
"\n"
"    border-width: 1px;\n"
"    border-color: rgb(255, 0, 24);\n"
"    border-style: solid;\n"
"    padding: 5px;\n"
"    border-radius: 2px;\n"
"    outline: none;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #e65c00;\n"
"    padding-top: -15px;\n"
"    padding-bottom: -17px;\n"
"}\n"
"\n"
"QComboBox {\n"
"    selection-background-color: #3daee9;\n"
"    border-style: solid;\n"
"    border: 1px solid #76797C;\n"
"    border-radius: 2px;\n"
"    padding: 5px;\n"
""
                        "    min-width: 75px;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    background-color: #76797C;\n"
"    border-color: #6A6969;\n"
"}\n"
"\n"
"QComboBox:hover,\n"
"QPushButton:hover,\n"
"QAbstractSpinBox:hover,\n"
"QLineEdit:hover,\n"
"QTextEdit:hover,\n"
"QPlainTextEdit:hover,\n"
"QAbstractView:hover,\n"
"QTreeView:hover {\n"
"    border: 2px solid yellow;\n"
"    color: yellow;\n"
"}\n"
"\n"
"QComboBox:on {\n"
"    padding-top: 3px;\n"
"    padding-left: 4px;\n"
"    selection-background-color: rgba(255, 0, 0, 0.5);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #232629;\n"
"    border-radius: 2px;\n"
"    border: 1px solid #76797C;\n"
"    selection-background-color: #18465d;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"    border-left-width: 0px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
""
                        "}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/qss_icons/rc/down_arrow_disabled.png);\n"
"}\n"
"\n"
"QComboBox::down-arrow:on,\n"
"QComboBox::down-arrow:hover,\n"
"QComboBox::down-arrow:focus {\n"
"    image: url(:/qss_icons/rc/down_arrow.png);\n"
"}\n"
"\n"
"QAbstractSpinBox {\n"
"    padding: 5px;\n"
"    border: 1px solid #76797C;\n"
"    background-color: #232629;\n"
"    color: #eff0f1;\n"
"    border-radius: 2px;\n"
"    min-width: 75px;\n"
"}\n"
"\n"
"QAbstractSpinBox:up-button {\n"
"    background-color: transparent;\n"
"    subcontrol-origin: border;\n"
"    subcontrol-position: center right;\n"
"}\n"
"\n"
"QAbstractSpinBox:down-button {\n"
"    background-color: transparent;\n"
"    subcontrol-origin: border;\n"
"    subcontrol-position: center left;\n"
"}\n"
"\n"
"QAbstractSpinBox::up-arrow,\n"
"QAbstractSpinBox::up-arrow:disabled,\n"
"QAbstractSpinBox::up-arrow:off {\n"
"    image: url(:/qss_icons/rc/up_arrow_disabled.png);\n"
"    width: 10px;\n"
"    height: 10px;\n"
"}\n"
"\n"
"QAbstrac"
                        "tSpinBox::up-arrow:hover {\n"
"    image: url(:/qss_icons/rc/up_arrow.png);\n"
"}\n"
"\n"
"QAbstractSpinBox::down-arrow,\n"
"QAbstractSpinBox::down-arrow:disabled,\n"
"QAbstractSpinBox::down-arrow:off {\n"
"    image: url(:/qss_icons/rc/down_arrow_disabled.png);\n"
"    width: 10px;\n"
"    height: 10px;\n"
"}\n"
"\n"
"QAbstractSpinBox::down-arrow:hover {\n"
"    image: url(:/qss_icons/rc/down_arrow.png);\n"
"}\n"
"\n"
"QLabel {\n"
"    border: 0px solid black;\n"
"}\n"
"\n"
"QTabWidget {\n"
"    border: 0px transparent black;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    border: 1px solid #76797C;\n"
"    padding: 5px;\n"
"    margin: 0px;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"    /* left: 5px; move to the right by 5px */\n"
"}\n"
"\n"
"QTabBar {\n"
"    qproperty-drawBase: 0;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QTabBar:focus {\n"
"    border: 0px transparent black;\n"
"}\n"
"\n"
"QTabBar::close-button {\n"
"    image: url(:/qss_icons/rc/close.png);\n"
"    background: transparent;\n"
"}\n"
"\n"
"QTabBa"
                        "r::close-button:hover {\n"
"    image: url(:/qss_icons/rc/close-hover.png);\n"
"    background: transparent;\n"
"}\n"
"\n"
"QTabBar::close-button:pressed {\n"
"    image: url(:/qss_icons/rc/close-pressed.png);\n"
"    background: transparent;\n"
"}\n"
"\n"
"\n"
"/* TOP TABS */\n"
"\n"
"QTabBar::tab:top {\n"
"    color: #eff0f1;\n"
"    border: 1px solid #76797C;\n"
"    border-bottom: 1px transparent black;\n"
"    background-color: #31363b;\n"
"    padding: 5px;\n"
"    min-width: 50px;\n"
"    border-top-left-radius: 2px;\n"
"    border-top-right-radius: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:top:selected {\n"
"    color: #eff0f1;\n"
"    background-color: #54575B;\n"
"    border: 1px solid #76797C;\n"
"    border-bottom: 2px solid #3daee9;\n"
"    border-top-left-radius: 2px;\n"
"    border-top-right-radius: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:top:!selected:hover {\n"
"    background-color: #3daee9;\n"
"}\n"
"\n"
"\n"
"/* BOTTOM TABS */\n"
"\n"
"QTabBar::tab:bottom {\n"
"    color: #eff0f1;\n"
"    border: 1px solid"
                        " #76797C;\n"
"    border-top: 1px transparent black;\n"
"    background-color: #31363b;\n"
"    padding: 5px;\n"
"    border-bottom-left-radius: 2px;\n"
"    border-bottom-right-radius: 2px;\n"
"    min-width: 50px;\n"
"}\n"
"\n"
"QTabBar::tab:bottom:selected {\n"
"    color: #eff0f1;\n"
"    background-color: #54575B;\n"
"    border: 1px solid #76797C;\n"
"    border-top: 2px solid #3daee9;\n"
"    border-bottom-left-radius: 2px;\n"
"    border-bottom-right-radius: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:bottom:!selected:hover {\n"
"    background-color: #3daee9;\n"
"}\n"
"\n"
"\n"
"/* LEFT TABS */\n"
"\n"
"QTabBar::tab:left {\n"
"    color: #eff0f1;\n"
"    border: 1px solid #76797C;\n"
"    border-left: 1px transparent black;\n"
"    background-color: #31363b;\n"
"    padding: 5px;\n"
"    border-top-right-radius: 2px;\n"
"    border-bottom-right-radius: 2px;\n"
"    min-height: 50px;\n"
"}\n"
"\n"
"QTabBar::tab:left:selected {\n"
"    color: #eff0f1;\n"
"    background-color: #54575B;\n"
"    border: 1px solid #7"
                        "6797C;\n"
"    border-left: 2px solid #3daee9;\n"
"    border-top-right-radius: 2px;\n"
"    border-bottom-right-radius: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:left:!selected:hover {\n"
"    background-color: #3daee9;\n"
"}\n"
"\n"
"\n"
"/* RIGHT TABS */\n"
"\n"
"QTabBar::tab:right {\n"
"    color: #eff0f1;\n"
"    border: 1px solid #76797C;\n"
"    border-right: 1px transparent black;\n"
"    background-color: #31363b;\n"
"    padding: 5px;\n"
"    border-top-left-radius: 2px;\n"
"    border-bottom-left-radius: 2px;\n"
"    min-height: 50px;\n"
"}\n"
"\n"
"QTabBar::tab:right:selected {\n"
"    color: #eff0f1;\n"
"    background-color: #54575B;\n"
"    border: 1px solid #76797C;\n"
"    border-right: 2px solid #3daee9;\n"
"    border-top-left-radius: 2px;\n"
"    border-bottom-left-radius: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:right:!selected:hover {\n"
"    background-color: #3daee9;\n"
"}\n"
"\n"
"QTabBar QToolButton::right-arrow:enabled {\n"
"    image: url(:/qss_icons/rc/right_arrow.png);\n"
"}\n"
"\n"
"QTabBar QTool"
                        "Button::left-arrow:enabled {\n"
"    image: url(:/qss_icons/rc/left_arrow.png);\n"
"}\n"
"\n"
"QTabBar QToolButton::right-arrow:disabled {\n"
"    image: url(:/qss_icons/rc/right_arrow_disabled.png);\n"
"}\n"
"\n"
"QTabBar QToolButton::left-arrow:disabled {\n"
"    image: url(:/qss_icons/rc/left_arrow_disabled.png);\n"
"}\n"
"\n"
"QDockWidget {\n"
"    background: #31363b;\n"
"    border: 1px solid #403F3F;\n"
"    titlebar-close-icon: url(:/qss_icons/rc/close.png);\n"
"    titlebar-normal-icon: url(:/qss_icons/rc/undock.png);\n"
"}\n"
"\n"
"QDockWidget::close-button,\n"
"QDockWidget::float-button {\n"
"    border: 1px solid transparent;\n"
"    border-radius: 2px;\n"
"    background: transparent;\n"
"}\n"
"\n"
"QDockWidget::close-button:hover,\n"
"QDockWidget::float-button:hover {\n"
"    background: rgba(255, 255, 255, 10);\n"
"}\n"
"\n"
"QDockWidget::close-button:pressed,\n"
"QDockWidget::float-button:pressed {\n"
"    padding: 1px -1px -1px 1px;\n"
"    background: rgba(255, 255, 255, 10);\n"
"}\n"
"\n"
"Q"
                        "TreeView,\n"
"QListView {\n"
"    border: 1px solid #76797C;\n"
"    background-color: #232629;\n"
"}\n"
"\n"
"QTreeView:branch:selected,\n"
"QTreeView:branch:hover {\n"
"    background: url(:/qss_icons/rc/transparent.png);\n"
"}\n"
"\n"
"QTreeView::branch:has-siblings:!adjoins-item {\n"
"    border-image: url(:/qss_icons/rc/transparent.png);\n"
"}\n"
"\n"
"QTreeView::branch:has-siblings:adjoins-item {\n"
"    border-image: url(:/qss_icons/rc/transparent.png);\n"
"}\n"
"\n"
"QTreeView::branch:!has-children:!has-siblings:adjoins-item {\n"
"    border-image: url(:/qss_icons/rc/transparent.png);\n"
"}\n"
"\n"
"QTreeView::branch:has-children:!has-siblings:closed,\n"
"QTreeView::branch:closed:has-children:has-siblings {\n"
"    image: url(:/qss_icons/rc/branch_closed.png);\n"
"}\n"
"\n"
"QTreeView::branch:open:has-children:!has-siblings,\n"
"QTreeView::branch:open:has-children:has-siblings {\n"
"    image: url(:/qss_icons/rc/branch_open.png);\n"
"}\n"
"\n"
"QTreeView::branch:has-children:!has-siblings:closed:hover,"
                        "\n"
"QTreeView::branch:closed:has-children:has-siblings:hover {\n"
"    image: url(:/qss_icons/rc/branch_closed-on.png);\n"
"}\n"
"\n"
"QTreeView::branch:open:has-children:!has-siblings:hover,\n"
"QTreeView::branch:open:has-children:has-siblings:hover {\n"
"    image: url(:/qss_icons/rc/branch_open-on.png);\n"
"}\n"
"\n"
"QListView::item:!selected:hover,\n"
"QTreeView::item:!selected:hover {\n"
"    background: #18465d;\n"
"    outline: 0;\n"
"    color: #eff0f1\n"
"}\n"
"\n"
"QListView::item:selected:hover,\n"
"QTreeView::item:selected:hover {\n"
"    background: #287399;\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
"QTreeView::indicator:checked,\n"
"QListView::indicator:checked {\n"
"    image: url(:/qss_icons/rc/checkbox_checked.png);\n"
"}\n"
"\n"
"QTreeView::indicator:unchecked,\n"
"QListView::indicator:unchecked {\n"
"    image: url(:/qss_icons/rc/checkbox_unchecked.png);\n"
"}\n"
"\n"
"QTreeView::indicator:checked:hover,\n"
"QTreeView::indicator:checked:focus,\n"
"QTreeView::indicator:checked:pressed,\n"
"QLis"
                        "tView::indicator:checked:hover,\n"
"QListView::indicator:checked:focus,\n"
"QListView::indicator:checked:pressed {\n"
"    image: url(:/qss_icons/rc/checkbox_checked_focus.png);\n"
"}\n"
"\n"
"QTreeView::indicator:unchecked:hover,\n"
"QTreeView::indicator:unchecked:focus,\n"
"QTreeView::indicator:unchecked:pressed,\n"
"QListView::indicator:unchecked:hover,\n"
"QListView::indicator:unchecked:focus,\n"
"QListView::indicator:unchecked:pressed {\n"
"    image: url(:/qss_icons/rc/checkbox_unchecked_focus.png);\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    border: 1px solid #565a5e;\n"
"    height: 4px;\n"
"    background: #565a5e;\n"
"    margin: 0px;\n"
"    border-radius: 2px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: #232629;\n"
"    border: 1px solid #565a5e;\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    margin: -8px 0;\n"
"    border-radius: 9px;\n"
"}\n"
"\n"
"QSlider::groove:vertical {\n"
"    border: 1px solid #565a5e;\n"
"    width: 4px;\n"
"    background: #565a5e;\n"
"   "
                        " margin: 0px;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QSlider::handle:vertical {\n"
"    background: #232629;\n"
"    border: 1px solid #565a5e;\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    margin: 0 -8px;\n"
"    border-radius: 9px;\n"
"}\n"
"\n"
"QToolButton {\n"
"    background-color: transparent;\n"
"    border: 1px transparent #76797C;\n"
"    border-radius: 2px;\n"
"    margin: 3px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QToolButton[popupMode=\"1\"] {\n"
"    /* only for MenuButtonPopup */\n"
"    padding-right: 20px;\n"
"    /* make way for the popup button */\n"
"    border: 1px #76797C;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QToolButton[popupMode=\"2\"] {\n"
"    /* only for InstantPopup */\n"
"    padding-right: 10px;\n"
"    /* make way for the popup button */\n"
"    border: 1px #76797C;\n"
"}\n"
"\n"
"QToolButton:hover,\n"
"QToolButton::menu-button:hover {\n"
"    background-color: transparent;\n"
"    border: 1px solid #3daee9;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QToolButton:checked,\n"
""
                        "QToolButton:pressed,\n"
"QToolButton::menu-button:pressed {\n"
"    background-color: #3daee9;\n"
"    border: 1px solid #3daee9;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"\n"
"/* the subcontrol below is used only in the InstantPopup or DelayedPopup mode */\n"
"\n"
"QToolButton::menu-indicator {\n"
"    image: url(:/qss_icons/rc/down_arrow.png);\n"
"    top: -7px;\n"
"    left: -2px;\n"
"    /* shift it a bit */\n"
"}\n"
"\n"
"\n"
"/* the subcontrols below are used only in the MenuButtonPopup mode */\n"
"\n"
"QToolButton::menu-button {\n"
"    border: 1px transparent #76797C;\n"
"    border-top-right-radius: 6px;\n"
"    border-bottom-right-radius: 6px;\n"
"    /* 16px width + 4px for border = 20px allocated above */\n"
"    width: 16px;\n"
"    outline: none;\n"
"}\n"
"\n"
"QToolButton::menu-arrow {\n"
"    image: url(:/qss_icons/rc/down_arrow.png);\n"
"}\n"
"\n"
"QToolButton::menu-arrow:open {\n"
"    border: 1px solid #76797C;\n"
"}\n"
"\n"
"QPushButton::menu-indicator {\n"
"    subcontrol-origin: padding;\n"
" "
                        "   subcontrol-position: bottom right;\n"
"    left: 8px;\n"
"}\n"
"\n"
"QTableView {\n"
"    border: 1px solid #76797C;\n"
"    gridline-color: #31363b;\n"
"    background-color: #232629;\n"
"}\n"
"\n"
"QTableView,\n"
"QHeaderView {\n"
"    border-radius: 0px;\n"
"}\n"
"\n"
"QTableView::item:pressed,\n"
"QListView::item:pressed,\n"
"QTreeView::item:pressed {\n"
"    background: #18465d;\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
"QTableView::item:selected:active,\n"
"QTreeView::item:selected:active,\n"
"QListView::item:selected:active {\n"
"    background: #287399;\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
"QHeaderView {\n"
"    background-color: #31363b;\n"
"    border: 1px transparent;\n"
"    border-radius: 0px;\n"
"    margin: 0px;\n"
"    padding: 0px;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #31363b;\n"
"    color: #eff0f1;\n"
"    padding: 5px;\n"
"    border: 1px solid #76797C;\n"
"    border-radius: 0px;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QHeaderView::section::vertical::first,\n"
""
                        "QHeaderView::section::vertical::only-one {\n"
"    border-top: 1px solid #76797C;\n"
"}\n"
"\n"
"QHeaderView::section::vertical {\n"
"    border-top: transparent;\n"
"}\n"
"\n"
"QHeaderView::section::horizontal::first,\n"
"QHeaderView::section::horizontal::only-one {\n"
"    border-left: 1px solid #76797C;\n"
"}\n"
"\n"
"QHeaderView::section::horizontal {\n"
"    border-left: transparent;\n"
"}\n"
"\n"
"QHeaderView::section:checked {\n"
"    color: white;\n"
"    background-color: #334e5e;\n"
"}\n"
"\n"
"\n"
"/* style the sort indicator */\n"
"\n"
"QHeaderView::down-arrow {\n"
"    image: url(:/qss_icons/rc/down_arrow.png);\n"
"}\n"
"\n"
"QHeaderView::up-arrow {\n"
"    image: url(:/qss_icons/rc/up_arrow.png);\n"
"}\n"
"\n"
"QTableCornerButton::section {\n"
"    background-color: #31363b;\n"
"    border: 1px transparent #76797C;\n"
"    border-radius: 0px;\n"
"}\n"
"\n"
"QToolBox {\n"
"    padding: 5px;\n"
"    border: 1px transparent black;\n"
"}\n"
"\n"
"QToolBox::tab {\n"
"    color: #eff0f1;\n"
"    backgr"
                        "ound-color: #31363b;\n"
"    border: 1px solid #76797C;\n"
"    border-bottom: 1px transparent #31363b;\n"
"    border-top-left-radius: 5px;\n"
"    border-top-right-radius: 5px;\n"
"}\n"
"\n"
"QToolBox::tab:selected {\n"
"    /* italicize selected tabs */\n"
"    font: italic;\n"
"    background-color: #31363b;\n"
"    border-color: #3daee9;\n"
"}\n"
"\n"
"QStatusBar::item {\n"
"    border: 0px transparent dark;\n"
"}\n"
"\n"
"QFrame[height=\"3\"],\n"
"QFrame[width=\"3\"] {\n"
"    background-color: #76797C;\n"
"}\n"
"\n"
"QSplitter::handle {\n"
"    border: 1px dashed #76797C;\n"
"}\n"
"\n"
"QSplitter::handle:hover {\n"
"    background-color: #787876;\n"
"    border: 1px solid #76797C;\n"
"}\n"
"\n"
"QSplitter::handle:horizontal {\n"
"    width: 1px;\n"
"}\n"
"\n"
"QSplitter::handle:vertical {\n"
"    height: 1px;\n"
"}\n"
"\n"
"QProgressBar {\n"
"    border: 1px solid #76797C;\n"
"    border-radius: 5px;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #05B8CC;\n"
""
                        "}\n"
"\n"
"QDateEdit {\n"
"    selection-background-color: #3daee9;\n"
"    border-style: solid;\n"
"    border: 1px solid #3375A3;\n"
"    border-radius: 2px;\n"
"    padding: 1px;\n"
"    min-width: 75px;\n"
"}\n"
"\n"
"QDateEdit:on {\n"
"    padding-top: 3px;\n"
"    padding-left: 4px;\n"
"    selection-background-color: rgba(255, 0, 0, 0.5)\n"
"}\n"
"\n"
"QDateEdit QAbstractItemView {\n"
"    background-color: #232629;\n"
"    border-radius: 2px;\n"
"    border: 1px solid #3375A3;\n"
"    selection-background-color: #3daee9;\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"    border-left-width: 0px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QDateEdit::down-arrow {\n"
"    image: url(:/qss_icons/rc/down_arrow_disabled.png);\n"
"}\n"
"\n"
"QDateEdit::down-arrow:on,\n"
"QDateEdit::down-arrow:hover,\n"
""
                        "QDateEdit::down-arrow:focus {\n"
"    image: url(:/qss_icons/rc/down_arrow.png);\n"
"}\n"
""));
        actionNew_Trip = new QAction(MainWindow);
        actionNew_Trip->setObjectName(QStringLiteral("actionNew_Trip"));
        adminLoginAction = new QAction(MainWindow);
        adminLoginAction->setObjectName(QStringLiteral("adminLoginAction"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 5, 571, 721));
        stackedWidget->setStyleSheet(QStringLiteral(""));
        splashPage = new QWidget();
        splashPage->setObjectName(QStringLiteral("splashPage"));
        splashPage->setMinimumSize(QSize(0, 1));
        welcomeLabel = new QLabel(splashPage);
        welcomeLabel->setObjectName(QStringLiteral("welcomeLabel"));
        welcomeLabel->setGeometry(QRect(100, 50, 361, 31));
        welcomeLabel->setStyleSheet(QLatin1String("QLabel {\n"
"background-color: rgba(255, 0,0,0.50);\n"
"color: white;\n"
"}"));
        welcomeLabel->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(splashPage);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(134, 100, 281, 51));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        adminLoginButton_2 = new QPushButton(layoutWidget);
        adminLoginButton_2->setObjectName(QStringLiteral("adminLoginButton_2"));
        adminLoginButton_2->setMinimumSize(QSize(131, 32));
        adminLoginButton_2->setMaximumSize(QSize(131, 32));

        horizontalLayout_2->addWidget(adminLoginButton_2);

        beginTripButton = new QPushButton(layoutWidget);
        beginTripButton->setObjectName(QStringLiteral("beginTripButton"));
        beginTripButton->setMinimumSize(QSize(113, 32));
        beginTripButton->setMaximumSize(QSize(113, 32));

        horizontalLayout_2->addWidget(beginTripButton);

        copyrightLabel = new QLabel(splashPage);
        copyrightLabel->setObjectName(QStringLiteral("copyrightLabel"));
        copyrightLabel->setGeometry(QRect(17, 289, 201, 16));
        copyrightLabel->setStyleSheet(QLatin1String("QLabel {\n"
"    background: qlineargradient(x1:0 y1:0, x2:1 y2:0, stop:0 #333333, stop:1 #dd1818);\n"
"color:white;\n"
"}\n"
""));
        stackedWidget->addWidget(splashPage);
        mainMenuPage = new QWidget();
        mainMenuPage->setObjectName(QStringLiteral("mainMenuPage"));
        gridLayoutWidget = new QWidget(mainMenuPage);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(13, 55, 531, 561));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(mainMenuPage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(61, 23, 441, 21));
        label->setStyleSheet(QLatin1String("QLabel {\n"
"background-color: rgba(255, 0,0,0.5);\n"
"color: white;\n"
"}"));
        label->setAlignment(Qt::AlignCenter);
        layoutWidget_2 = new QWidget(mainMenuPage);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(30, 640, 501, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        planTripFromSaddlebackButton = new QPushButton(layoutWidget_2);
        planTripFromSaddlebackButton->setObjectName(QStringLiteral("planTripFromSaddlebackButton"));

        horizontalLayout->addWidget(planTripFromSaddlebackButton);

        mostEffecientTripFromUCIButton = new QPushButton(layoutWidget_2);
        mostEffecientTripFromUCIButton->setObjectName(QStringLiteral("mostEffecientTripFromUCIButton"));

        horizontalLayout->addWidget(mostEffecientTripFromUCIButton);

        stackedWidget->addWidget(mainMenuPage);
        adminLoginPage = new QWidget();
        adminLoginPage->setObjectName(QStringLiteral("adminLoginPage"));
        layoutWidget1 = new QWidget(adminLoginPage);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(90, 20, 321, 181));
        adminLoginLayout = new QVBoxLayout(layoutWidget1);
        adminLoginLayout->setSpacing(1);
        adminLoginLayout->setContentsMargins(11, 11, 11, 11);
        adminLoginLayout->setObjectName(QStringLiteral("adminLoginLayout"));
        adminLoginLayout->setContentsMargins(0, 0, 0, 0);
        loginTitleLabel = new QLabel(layoutWidget1);
        loginTitleLabel->setObjectName(QStringLiteral("loginTitleLabel"));
        loginTitleLabel->setMaximumSize(QSize(1000, 1000));
        loginTitleLabel->setStyleSheet(QLatin1String("QLabel {\n"
"background-color: rgba(255, 0,0,0.25);\n"
"color: white;\n"
"}"));
        loginTitleLabel->setAlignment(Qt::AlignCenter);

        adminLoginLayout->addWidget(loginTitleLabel);

        loginErrorLabel = new QLabel(layoutWidget1);
        loginErrorLabel->setObjectName(QStringLiteral("loginErrorLabel"));
        loginErrorLabel->setMinimumSize(QSize(0, 0));
        loginErrorLabel->setMaximumSize(QSize(500, 500));
        loginErrorLabel->setStyleSheet(QLatin1String("QLabel {\n"
"background-color: rgba(0, 0,0,0.0);\n"
"color: red;\n"
"}"));
        loginErrorLabel->setAlignment(Qt::AlignCenter);

        adminLoginLayout->addWidget(loginErrorLabel);

        usernameInput = new QLineEdit(layoutWidget1);
        usernameInput->setObjectName(QStringLiteral("usernameInput"));
        usernameInput->setAlignment(Qt::AlignCenter);

        adminLoginLayout->addWidget(usernameInput);

        passwordInput = new QLineEdit(layoutWidget1);
        passwordInput->setObjectName(QStringLiteral("passwordInput"));
        passwordInput->setEchoMode(QLineEdit::Password);
        passwordInput->setAlignment(Qt::AlignCenter);

        adminLoginLayout->addWidget(passwordInput);

        adminLoginButton = new QPushButton(layoutWidget1);
        adminLoginButton->setObjectName(QStringLiteral("adminLoginButton"));

        adminLoginLayout->addWidget(adminLoginButton);

        loginPageBackButton = new QPushButton(layoutWidget1);
        loginPageBackButton->setObjectName(QStringLiteral("loginPageBackButton"));

        adminLoginLayout->addWidget(loginPageBackButton);

        stackedWidget->addWidget(adminLoginPage);
        adminPanelPage = new QWidget();
        adminPanelPage->setObjectName(QStringLiteral("adminPanelPage"));
        CollegeOperationsFrame = new QFrame(adminPanelPage);
        CollegeOperationsFrame->setObjectName(QStringLiteral("CollegeOperationsFrame"));
        CollegeOperationsFrame->setGeometry(QRect(10, 70, 211, 161));
        CollegeOperationsFrame->setFrameShape(QFrame::StyledPanel);
        CollegeOperationsFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(CollegeOperationsFrame);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        collegeOperationsLayout = new QVBoxLayout();
        collegeOperationsLayout->setSpacing(50);
        collegeOperationsLayout->setObjectName(QStringLiteral("collegeOperationsLayout"));
        newCollegeButton = new QPushButton(CollegeOperationsFrame);
        newCollegeButton->setObjectName(QStringLiteral("newCollegeButton"));
        newCollegeButton->setMinimumSize(QSize(131, 32));

        collegeOperationsLayout->addWidget(newCollegeButton);

        addNewMenuItemButton = new QPushButton(CollegeOperationsFrame);
        addNewMenuItemButton->setObjectName(QStringLiteral("addNewMenuItemButton"));
        addNewMenuItemButton->setMinimumSize(QSize(131, 32));

        collegeOperationsLayout->addWidget(addNewMenuItemButton);


        verticalLayout_2->addLayout(collegeOperationsLayout);

        menuItemsLabel = new QLabel(adminPanelPage);
        menuItemsLabel->setObjectName(QStringLiteral("menuItemsLabel"));
        menuItemsLabel->setGeometry(QRect(350, 0, 81, 20));
        menuItemsLabel->setStyleSheet(QLatin1String("QLabel {\n"
"color: yellow;\n"
"}"));
        menuItemsLabel->setAlignment(Qt::AlignCenter);
        menuItemsListWidget = new QListWidget(adminPanelPage);
        menuItemsListWidget->setObjectName(QStringLiteral("menuItemsListWidget"));
        menuItemsListWidget->setGeometry(QRect(250, 20, 301, 261));
        label_2 = new QLabel(adminPanelPage);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(4, 35, 251, 16));
        label_2->setStyleSheet(QLatin1String("QLabel {\n"
"background: rgba(0,0,0,0);\n"
"color:yellow;\n"
"}"));
        adminPageBackButton = new QPushButton(adminPanelPage);
        adminPageBackButton->setObjectName(QStringLiteral("adminPageBackButton"));
        adminPageBackButton->setGeometry(QRect(387, 286, 151, 32));
        stackedWidget->addWidget(adminPanelPage);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 583, 21));
        menuNew_Trip = new QMenu(menuBar);
        menuNew_Trip->setObjectName(QStringLiteral("menuNew_Trip"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuNew_Trip->menuAction());
        menuNew_Trip->addAction(adminLoginAction);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Saddleback College Tour", Q_NULLPTR));
        actionNew_Trip->setText(QApplication::translate("MainWindow", "New Trip", Q_NULLPTR));
        adminLoginAction->setText(QApplication::translate("MainWindow", "Home", Q_NULLPTR));
        actionNew->setText(QApplication::translate("MainWindow", "New", Q_NULLPTR));
        welcomeLabel->setText(QApplication::translate("MainWindow", "Welcome to the College Tour Planner!", Q_NULLPTR));
        adminLoginButton_2->setText(QApplication::translate("MainWindow", "Administrator Login", Q_NULLPTR));
        beginTripButton->setText(QApplication::translate("MainWindow", "Begin Trip", Q_NULLPTR));
        copyrightLabel->setText(QApplication::translate("MainWindow", "Agile Development Team \302\251 2018", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Select an initial college to begin planning your trip from Saddleback:", Q_NULLPTR));
        planTripFromSaddlebackButton->setText(QApplication::translate("MainWindow", "Shortest Trip from Saddleback", Q_NULLPTR));
        mostEffecientTripFromUCIButton->setText(QApplication::translate("MainWindow", "Shortest Trip from UCI", Q_NULLPTR));
        loginTitleLabel->setText(QApplication::translate("MainWindow", "Please login:", Q_NULLPTR));
        loginErrorLabel->setText(QString());
        usernameInput->setPlaceholderText(QApplication::translate("MainWindow", "Username", Q_NULLPTR));
        passwordInput->setPlaceholderText(QApplication::translate("MainWindow", "Password", Q_NULLPTR));
        adminLoginButton->setText(QApplication::translate("MainWindow", "Login", Q_NULLPTR));
        loginPageBackButton->setText(QApplication::translate("MainWindow", "Back", Q_NULLPTR));
        newCollegeButton->setText(QApplication::translate("MainWindow", "Upload College From File", Q_NULLPTR));
        addNewMenuItemButton->setText(QApplication::translate("MainWindow", "Add Souvenir Item", Q_NULLPTR));
        menuItemsLabel->setText(QApplication::translate("MainWindow", "Souvenir Items", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Double click a souvenir item to modify it", Q_NULLPTR));
        adminPageBackButton->setText(QApplication::translate("MainWindow", "Back to Main Menu", Q_NULLPTR));
        menuNew_Trip->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
