#ifndef COLLEGE_H
#define COLLEGE_H

#include <QString>
#include <QVector>

//! The Restaurant Structures
/*!
  These are some of the structs that are
  used throughout the program mainly
  for storage, proccesssing, and output
  of data.
 */


//! MenuItem Struct
/*!
 * \brief The stored data of the menu
 * items for each restaurant.
 */
struct MenuItem {
    int id;                            //!< The integer ID for each items
    QString name;                      //!< A QString for the name of items
    double price;                      //!< A double to store each item's price
    int    quantity;                   //!< An integer to store quantity purchased
};


//! Restaurant Struct
/*!
 * \brief The stored restaurants' data which
 * consists of their IDs, names, distances to Saddleback,
 * and menu items.
 */
struct College {
    int id;                            //!< The integer ID of each restaurant
    QString name;                      //!< A QString for the name of restaurants
    double distanceToSaddleback;       //!< Double for each restaurants distance to Saddleback
    QVector<MenuItem> menuItems;       //!< QVector of menu items that has each restaurants menu

    /*! \brief An operator overload to compare distances to Saddleback.
     * \param otherRestaurant A constant struct argument
     * \return A boolean that is true if this restaurant is less than other
     */
    bool operator<(const College& otherRestaurant) const
    {
        return this->distanceToSaddleback < otherRestaurant.distanceToSaddleback;
    }

    College() {}

    /*! \brief An explicit constructor of the struct to set all the data.
     * \param id An integer argument
     * \param name A qstring argument
     * \param distanceToSaddleback A double argument
     * \param items A qvector argument
     */
    explicit College(int id, QString name, double distanceToSaddleback, QVector<MenuItem> items)
    {
        this->id = id;
        this->name = name;
        this->distanceToSaddleback = distanceToSaddleback;
        this->menuItems = items;

    }
};


//! Distance Struct
/*!
 * \brief The stored distance to the next restaurant.
 */
struct Distance
{
    int destinationCollege_ID;      //!< An integer of the destination's ID
    double distanceTo;                 //!< A double of the distance to the destination
};

#endif // RESTAURANT_H
