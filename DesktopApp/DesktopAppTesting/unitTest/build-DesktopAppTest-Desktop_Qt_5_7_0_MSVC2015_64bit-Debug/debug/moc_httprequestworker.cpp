/****************************************************************************
** Meta object code from reading C++ file 'httprequestworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DesktopAppTest/httprequestworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'httprequestworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HttpRequestWorker_t {
    QByteArrayData data[12];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HttpRequestWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HttpRequestWorker_t qt_meta_stringdata_HttpRequestWorker = {
    {
QT_MOC_LITERAL(0, 0, 17), // "HttpRequestWorker"
QT_MOC_LITERAL(1, 18, 21), // "on_execution_finished"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 18), // "HttpRequestWorker*"
QT_MOC_LITERAL(4, 60, 6), // "worker"
QT_MOC_LITERAL(5, 67, 10), // "StatusCode"
QT_MOC_LITERAL(6, 78, 7), // "execute"
QT_MOC_LITERAL(7, 86, 17), // "HttpRequestInput*"
QT_MOC_LITERAL(8, 104, 5), // "input"
QT_MOC_LITERAL(9, 110, 19), // "on_manager_finished"
QT_MOC_LITERAL(10, 130, 14), // "QNetworkReply*"
QT_MOC_LITERAL(11, 145, 5) // "reply"

    },
    "HttpRequestWorker\0on_execution_finished\0"
    "\0HttpRequestWorker*\0worker\0StatusCode\0"
    "execute\0HttpRequestInput*\0input\0"
    "on_manager_finished\0QNetworkReply*\0"
    "reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HttpRequestWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   34,    2, 0x0a /* Public */,
       9,    1,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void HttpRequestWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HttpRequestWorker *_t = static_cast<HttpRequestWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_execution_finished((*reinterpret_cast< HttpRequestWorker*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->execute((*reinterpret_cast< HttpRequestInput*(*)>(_a[1]))); break;
        case 2: _t->on_manager_finished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< HttpRequestWorker* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (HttpRequestWorker::*_t)(HttpRequestWorker * , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HttpRequestWorker::on_execution_finished)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject HttpRequestWorker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_HttpRequestWorker.data,
      qt_meta_data_HttpRequestWorker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HttpRequestWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HttpRequestWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HttpRequestWorker.stringdata0))
        return static_cast<void*>(const_cast< HttpRequestWorker*>(this));
    return QObject::qt_metacast(_clname);
}

int HttpRequestWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void HttpRequestWorker::on_execution_finished(HttpRequestWorker * _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
