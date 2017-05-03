/****************************************************************************
** Meta object code from reading C++ file 'randomfact.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DesktopAppIntegrationTest/randomfact.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'randomfact.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RandomFact_t {
    QByteArrayData data[15];
    char stringdata0[186];
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
QT_MOC_LITERAL(5, 52, 15), // "FactWindowClose"
QT_MOC_LITERAL(6, 68, 21), // "on_logout_but_clicked"
QT_MOC_LITERAL(7, 90, 13), // "handle_result"
QT_MOC_LITERAL(8, 104, 18), // "HttpRequestWorker*"
QT_MOC_LITERAL(9, 123, 6), // "worker"
QT_MOC_LITERAL(10, 130, 10), // "StatusCode"
QT_MOC_LITERAL(11, 141, 11), // "AcceptToken"
QT_MOC_LITERAL(12, 153, 3), // "uid"
QT_MOC_LITERAL(13, 157, 5), // "token"
QT_MOC_LITERAL(14, 163, 22) // "on_getfact_but_clicked"

    },
    "RandomFact\0SendHTTPRequest\0\0"
    "HttpRequestInput*\0input\0FactWindowClose\0"
    "on_logout_but_clicked\0handle_result\0"
    "HttpRequestWorker*\0worker\0StatusCode\0"
    "AcceptToken\0uid\0token\0on_getfact_but_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RandomFact[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       5,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   48,    2, 0x08 /* Private */,
       7,    2,   49,    2, 0x08 /* Private */,
      11,    2,   54,    2, 0x08 /* Private */,
      14,    0,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8, QMetaType::QString,    9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QByteArray,   12,   13,
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
        case 1: _t->FactWindowClose(); break;
        case 2: _t->on_logout_but_clicked(); break;
        case 3: _t->handle_result((*reinterpret_cast< HttpRequestWorker*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->AcceptToken((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 5: _t->on_getfact_but_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
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
        {
            typedef void (RandomFact::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RandomFact::FactWindowClose)) {
                *result = 1;
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
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void RandomFact::SendHTTPRequest(HttpRequestInput * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RandomFact::FactWindowClose()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
