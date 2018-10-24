#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QVector>
#include <QMessageBox>
#include <fstream>
#include <QFileDialog>
#include <QFile>

/*! Souvenir Item Struct
 * \brief The souvenirItem struct
 * Will replicate details of a souvenir and will be
 * composed into colleges to represent their souvenirs.
 */
struct souvenirItem {
    int id;                            //!< The integer ID for each items
    QString name;                      //!< A QString for the name of items
    double price;                      //!< A double to store each item's price
    int    quantity;                   //!< An integer to store quantity purchased
};

/*! College Struct
 * \brief The College struct
 * Stores colleges with their relevant data as well as
 * operations to compare to other college structs.
 */
struct College {
    int id;                                    //!< The integer ID of each college
    QString name;                              //!< A QString for the name of college
    double distanceToSaddleback;               //!< Double for each colleges's distance to Saddleback
    QVector<souvenirItem> souvenirItems;       //!< QVector of souvenir items that has each colleges' souvenirs

    /*! Operator < Overload
     * \brief operator <
     * Overloaded to compare distances of colleges to each other
     * to find which is the closest.
     * \param otherCollege - A struct argument
     * \return A boolean if one college's distance is less than the others
     */
    bool operator<(const College& otherCollege) const
    {
        return this->distanceToSaddleback < otherCollege.distanceToSaddleback;
    }

    College() {} //! Default Constructor

    /*! Constructor
     * \brief College
     * Constructs college with preset data
     * \param id - An integer argument
     * \param name - A QString argument
     * \param distanceToSaddleback - A double argument
     * \param items - A QVector argument
     */
    explicit College(int id, QString name, double distanceToSaddleback, QVector<souvenirItem> items)
    {
        this->id = id;
        this->name = name;
        this->distanceToSaddleback = distanceToSaddleback;
        this->souvenirItems = items;
    }
};

/*! Distance Struct
 * \brief The Distance struct
 * Stores distances between two colleges
 */
struct Distance
{
    int destinationCollege_ID;      //!< An integer of the destination's ID
    double distanceTo;                 //!< A double of the distance to the destination
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    void populateMenu();        //! Populates main menu with colleges to start at
    void populateAdminMenu();   //! Populates admin menu with souvenirs from each college

    ~MainWindow();  //! Default Destructor

signals:
    void collegeClickedSignal(College);

private slots:
    void on_startButton_clicked();  //! Starts custom trip

    void initialCollegeSelected();  //! Sends signal with initial college information

    void on_header_icon_push_button_clicked();  //! Returns to home page

    void on_ASU_trip_button_clicked();  //! Initiates preset trip from ASU

    void on_shortest_trip_button_clicked(); //! Inititaes preset trip from UCI

    void on_admin_push_button_clicked();    //! Changes to admin login page

    void on_back_button_clicked();  //! Returns to home page

    void on_login_button_clicked(); //! Authenticates credentials

    void on_username_line_edit_returnPressed(); //! Authenticates login credentials

    void on_password_line_edit_returnPressed(); //! Authenticates login credentials

    void on_username_line_edit_textEdited(const QString &arg1); //!Clears error message

    void on_password_line_edit_textEdited(const QString &arg1); //!Clears error message

    void on_add_souvenir_button_clicked();  //! Begins souvenir addition process

    void on_souvenir_list_widget_clicked(const QModelIndex &index); //! Selects souvenir index

    void on_souvenir_list_widget_doubleClicked(const QModelIndex &index);   //! Prompts modification or deletion

    void on_upload_college_button_clicked();    //! Begins process to upload college from file

    void on_exit_button_clicked();  //! Returns to main window

private:
    void validateLogin();   //! Function to validate credentials to database
    Ui::MainWindow *ui; //! Pointer to main window to keep updates from database persistent
    int selectedRow;    //! Integer from row selected
};



#endif // MAINWINDOW_H
