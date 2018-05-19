/****************************************************************************
** Meta object code from reading C++ file 'datemanipulation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../datemanipulation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datemanipulation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DateManipulation_t {
    QByteArrayData data[18];
    char stringdata0[250];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DateManipulation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DateManipulation_t qt_meta_stringdata_DateManipulation = {
    {
QT_MOC_LITERAL(0, 0, 16), // "DateManipulation"
QT_MOC_LITERAL(1, 17, 21), // "lowerBoundDateChanged"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 21), // "upperBoundDateChanged"
QT_MOC_LITERAL(4, 62, 15), // "buildDateBounds"
QT_MOC_LITERAL(5, 78, 4), // "year"
QT_MOC_LITERAL(6, 83, 15), // "daysToSelection"
QT_MOC_LITERAL(7, 99, 4), // "date"
QT_MOC_LITERAL(8, 104, 10), // "generateID"
QT_MOC_LITERAL(9, 115, 10), // "horaInicio"
QT_MOC_LITERAL(10, 126, 12), // "getCurrentID"
QT_MOC_LITERAL(11, 139, 13), // "long long int"
QT_MOC_LITERAL(12, 153, 14), // "clearIDsQueued"
QT_MOC_LITERAL(13, 168, 23), // "addCurrentIDToIDsQueued"
QT_MOC_LITERAL(14, 192, 12), // "getYearRange"
QT_MOC_LITERAL(15, 205, 14), // "buildYearRange"
QT_MOC_LITERAL(16, 220, 14), // "lowerBoundDate"
QT_MOC_LITERAL(17, 235, 14) // "upperBoundDate"

    },
    "DateManipulation\0lowerBoundDateChanged\0"
    "\0upperBoundDateChanged\0buildDateBounds\0"
    "year\0daysToSelection\0date\0generateID\0"
    "horaInicio\0getCurrentID\0long long int\0"
    "clearIDsQueued\0addCurrentIDToIDsQueued\0"
    "getYearRange\0buildYearRange\0lowerBoundDate\0"
    "upperBoundDate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DateManipulation[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       2,   82, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       4,    1,   66,    2, 0x02 /* Public */,
       6,    1,   69,    2, 0x02 /* Public */,
       8,    2,   72,    2, 0x02 /* Public */,
      10,    0,   77,    2, 0x02 /* Public */,
      12,    0,   78,    2, 0x02 /* Public */,
      13,    0,   79,    2, 0x02 /* Public */,
      14,    0,   80,    2, 0x02 /* Public */,
      15,    0,   81,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Int, QMetaType::QDate,    7,
    QMetaType::Void, QMetaType::QDate, QMetaType::QString,    7,    9,
    0x80000000 | 11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QStringList,
    QMetaType::Void,

 // properties: name, type, flags
      16, QMetaType::QDate, 0x00495103,
      17, QMetaType::QDate, 0x00495103,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void DateManipulation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DateManipulation *_t = static_cast<DateManipulation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->lowerBoundDateChanged(); break;
        case 1: _t->upperBoundDateChanged(); break;
        case 2: _t->buildDateBounds((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: { int _r = _t->daysToSelection((*reinterpret_cast< QDate(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->generateID((*reinterpret_cast< QDate(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: { long long int _r = _t->getCurrentID();
            if (_a[0]) *reinterpret_cast< long long int*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->clearIDsQueued(); break;
        case 7: _t->addCurrentIDToIDsQueued(); break;
        case 8: { QStringList _r = _t->getYearRange();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->buildYearRange(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (DateManipulation::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DateManipulation::lowerBoundDateChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DateManipulation::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DateManipulation::upperBoundDateChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        DateManipulation *_t = static_cast<DateManipulation *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QDate*>(_v) = _t->lowerBoundDate(); break;
        case 1: *reinterpret_cast< QDate*>(_v) = _t->upperBoundDate(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        DateManipulation *_t = static_cast<DateManipulation *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setLowerBoundDate(*reinterpret_cast< QDate*>(_v)); break;
        case 1: _t->setUpperBoundDate(*reinterpret_cast< QDate*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject DateManipulation::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DateManipulation.data,
      qt_meta_data_DateManipulation,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DateManipulation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DateManipulation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DateManipulation.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DateManipulation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void DateManipulation::lowerBoundDateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DateManipulation::upperBoundDateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
