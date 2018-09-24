#ifndef COLLEGE_H
#define COLLEGE_H

#include <QString>
#include <QVector>

//! The College Tour Structures
/*!
  These are some of the structs that are
  used throughout the program mainly
  for storage, proccesssing, and output
  of data.
 */


//! souvenirItem Struct
/*!
 * \brief The stored data of the menu
 * items for each college.
 */
struct souvenirItem {
    int id;                            //!< The integer ID for each items
    QString name;                      //!< A QString for the name of items
    double price;                      //!< A double to store each item's price
    int    quantity;                   //!< An integer to store quantity purchased
};


//! College Struct
/*!
 * \brief The stored colleges' data which
 * consists of their IDs, names, distances to Saddleback,
 * and souvenir items.
 */
struct College {
    int id;                            //!< The integer ID of each college
    QString name;                      //!< A QString for the name of college
    double distanceToSaddleback;       //!< Double for each restaurants distance to Saddleback
    QVector<souvenirItem> souvenirItems;       //!< QVector of souvenir items that has each colleges' souvenirs

    /*! \brief An operator overload to compare distances to Saddleback.
     * \param otherRestaurant A constant struct argument
     * \return A boolean that is true if this restaurant is less than other
     */
    bool operator<(const College& otherCollege) const
    {
        return this->distanceToSaddleback < otherCollege.distanceToSaddleback;
    }

    College() {}

    /*! \brief An explicit constructor of the struct to set all the data.
     * \param id An integer argument
     * \param name A qstring argument
     * \param distanceToSaddleback A double argument
     * \param items A qvector argument
     */
    explicit College(int id, QString name, double distanceToSaddleback, QVector<souvenirItem> items)
    {
        this->id = id;
        this->name = name;
        this->distanceToSaddleback = distanceToSaddleback;
        this->souvenirItems = items;

    }
};


//! Distance Struct
/*!
 * \brief The stored distance to the next college.
 */
struct Distance
{
    int destinationCollege_ID;      //!< An integer of the destination's ID
    double distanceTo;                 //!< A double of the distance to the destination
};

#endif // RESTAURANT_H
