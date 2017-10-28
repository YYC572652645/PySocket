/****************************************************************************
** Meta object code from reading C++ file 'maintitlebar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../maintitlebar/maintitlebar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maintitlebar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainTitleBar_t {
    QByteArrayData data[8];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainTitleBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainTitleBar_t qt_meta_stringdata_MainTitleBar = {
    {
QT_MOC_LITERAL(0, 0, 12), // "MainTitleBar"
QT_MOC_LITERAL(1, 13, 9), // "sendIndex"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "showMax"
QT_MOC_LITERAL(4, 32, 7), // "showMin"
QT_MOC_LITERAL(5, 40, 9), // "showClose"
QT_MOC_LITERAL(6, 50, 12), // "receiveIndex"
QT_MOC_LITERAL(7, 63, 5) // "index"

    },
    "MainTitleBar\0sendIndex\0\0showMax\0showMin\0"
    "showClose\0receiveIndex\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainTitleBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   42,    2, 0x0a /* Public */,
       4,    0,   43,    2, 0x0a /* Public */,
       5,    0,   44,    2, 0x0a /* Public */,
       6,    1,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void MainTitleBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainTitleBar *_t = static_cast<MainTitleBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->showMax(); break;
        case 2: _t->showMin(); break;
        case 3: _t->showClose(); break;
        case 4: _t->receiveIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainTitleBar::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainTitleBar::sendIndex)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainTitleBar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainTitleBar.data,
      qt_meta_data_MainTitleBar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainTitleBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainTitleBar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainTitleBar.stringdata0))
        return static_cast<void*>(const_cast< MainTitleBar*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainTitleBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void MainTitleBar::sendIndex(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
