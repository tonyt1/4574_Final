/****************************************************************************
** Meta object code from reading C++ file 'randomfact.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DesktopAppIntegrationTest/randomfact.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'randomfact.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RandomFact_t {
    QByteArrayData data[11];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RandomFact_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RandomFact_t qt_meta_stringdata_RandomFact = {
    {
QT_MOC_LITERAL(0, 0, 10), // "RandomFact"
QT_MOC_LITERAL(1, 11, 15), // "SendHTTPRequest"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 17), // "HttpRequestInput*"
QT_MOC_LITERAL(4, 46, 5), // "input"
QT_MOC_LITERAL(5, 52, 21), // "on_logout_but_clicked"
QT_MOC_LITERAL(6, 74, 13), // "handle_result"
QT_MOC_LITERAL(7, 88, 18), // "HttpRequestWorker*"
QT_MOC_LITERAL(8, 107, 6), // "worker"
QT_MOC_LITERAL(9, 114, 10), // "StatusCode"
QT_MOC_LITERAL(10, 125, 22) // "on_getfact_but_clicked"

    },
    "RandomFact\0SendHTTPRequest\0\0"
    "HttpRequestInput*\0input\0on_logout_but_clicked\0"
    "handle_result\0HttpRequestWorker*\0"
    "worker\0StatusCode\0on_getfact_but_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RandomFact[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   37,    2, 0x08 /* Private */,
       6,    2,   38,    2, 0x08 /* Private */,
      10,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, QMetaType::QString,    8,    9,
    QMetaType::Void,

       0        // eod
};

void RandomFact::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RandomFact *_t = static_cast<RandomFact *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendHTTPRequest((*reinterpret_cast< HttpRequestInput*(*)>(_a[1]))); break;
        case 1: _t->on_logout_but_clicked(); break;
        case 2: _t->handle_result((*reinterpret_cast< HttpRequestWorker*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->on_getfact_but_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< HttpRequestWorker* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RandomFact::*_t)(HttpRequestInput * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RandomFact::SendHTTPRequest)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject RandomFact::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RandomFact.data,
      qt_meta_data_RandomFact,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RandomFact::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RandomFact::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RandomFact.stringdata0))
        return static_cast<void*>(const_cast< RandomFact*>(this));
    return QWidget::qt_metacast(_clname);
}

int RandomFact::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void RandomFact::SendHTTPRequest(HttpRequestInput * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE