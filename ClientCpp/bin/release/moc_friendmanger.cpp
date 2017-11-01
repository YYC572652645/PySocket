/****************************************************************************
** Meta object code from reading C++ file 'friendmanger.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../friendmanger/friendmanger.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'friendmanger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FriendManger_t {
    QByteArrayData data[11];
    char stringdata0[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FriendManger_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FriendManger_t qt_meta_stringdata_FriendManger = {
    {
QT_MOC_LITERAL(0, 0, 12), // "FriendManger"
QT_MOC_LITERAL(1, 13, 14), // "lookPersonInfo"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 30), // "on_pushButtonAddFriend_clicked"
QT_MOC_LITERAL(4, 60, 25), // "on_pushButtonSend_clicked"
QT_MOC_LITERAL(5, 86, 27), // "on_treeWidget_doubleClicked"
QT_MOC_LITERAL(6, 114, 5), // "index"
QT_MOC_LITERAL(7, 120, 26), // "on_pushButtonColor_clicked"
QT_MOC_LITERAL(8, 147, 39), // "on_fontComboBoxFont_currentIn..."
QT_MOC_LITERAL(9, 187, 4), // "arg1"
QT_MOC_LITERAL(10, 192, 25) // "on_comboBoxSize_activated"

    },
    "FriendManger\0lookPersonInfo\0\0"
    "on_pushButtonAddFriend_clicked\0"
    "on_pushButtonSend_clicked\0"
    "on_treeWidget_doubleClicked\0index\0"
    "on_pushButtonColor_clicked\0"
    "on_fontComboBoxFont_currentIndexChanged\0"
    "arg1\0on_comboBoxSize_activated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FriendManger[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    1,   52,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    1,   56,    2, 0x08 /* Private */,
      10,    1,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,

       0        // eod
};

void FriendManger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FriendManger *_t = static_cast<FriendManger *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->lookPersonInfo(); break;
        case 1: _t->on_pushButtonAddFriend_clicked(); break;
        case 2: _t->on_pushButtonSend_clicked(); break;
        case 3: _t->on_treeWidget_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->on_pushButtonColor_clicked(); break;
        case 5: _t->on_fontComboBoxFont_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_comboBoxSize_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject FriendManger::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FriendManger.data,
      qt_meta_data_FriendManger,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FriendManger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FriendManger::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FriendManger.stringdata0))
        return static_cast<void*>(const_cast< FriendManger*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int FriendManger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
