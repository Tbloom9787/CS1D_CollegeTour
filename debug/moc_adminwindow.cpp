/****************************************************************************
** Meta object code from reading C++ file 'adminwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../adminwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adminwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AdminWindow_t {
    QByteArrayData data[12];
    char stringdata0[265];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AdminWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AdminWindow_t qt_meta_stringdata_AdminWindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "AdminWindow"
QT_MOC_LITERAL(1, 12, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 28), // "on_itemNameInput_textChanged"
QT_MOC_LITERAL(4, 64, 4), // "arg1"
QT_MOC_LITERAL(5, 69, 30), // "on_itemPriceInput_valueChanged"
QT_MOC_LITERAL(6, 100, 38), // "on_collegeComboBox_currentInd..."
QT_MOC_LITERAL(7, 139, 5), // "index"
QT_MOC_LITERAL(8, 145, 31), // "on_newItemNameInput_textChanged"
QT_MOC_LITERAL(9, 177, 33), // "on_newItemPriceInput_valueCha..."
QT_MOC_LITERAL(10, 211, 27), // "on_addNewItemButton_clicked"
QT_MOC_LITERAL(11, 239, 25) // "on_cancelButton_2_clicked"

    },
    "AdminWindow\0on_pushButton_clicked\0\0"
    "on_itemNameInput_textChanged\0arg1\0"
    "on_itemPriceInput_valueChanged\0"
    "on_collegeComboBox_currentIndexChanged\0"
    "index\0on_newItemNameInput_textChanged\0"
    "on_newItemPriceInput_valueChanged\0"
    "on_addNewItemButton_clicked\0"
    "on_cancelButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdminWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    1,   55,    2, 0x08 /* Private */,
       5,    1,   58,    2, 0x08 /* Private */,
       6,    1,   61,    2, 0x08 /* Private */,
       8,    1,   64,    2, 0x08 /* Private */,
       9,    1,   67,    2, 0x08 /* Private */,
      10,    0,   70,    2, 0x08 /* Private */,
      11,    0,   71,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AdminWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AdminWindow *_t = static_cast<AdminWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_itemNameInput_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_itemPriceInput_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->on_collegeComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_newItemNameInput_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_newItemPriceInput_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->on_addNewItemButton_clicked(); break;
        case 7: _t->on_cancelButton_2_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject AdminWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AdminWindow.data,
      qt_meta_data_AdminWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AdminWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdminWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AdminWindow.stringdata0))
        return static_cast<void*>(const_cast< AdminWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int AdminWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
