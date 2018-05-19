/****************************************************************************
** Meta object code from reading C++ file 'cabinasqlqueries.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cabinasqlqueries.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cabinasqlqueries.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CabinaSQLQueries_t {
    QByteArrayData data[28];
    char stringdata0[330];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CabinaSQLQueries_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CabinaSQLQueries_t qt_meta_stringdata_CabinaSQLQueries = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CabinaSQLQueries"
QT_MOC_LITERAL(1, 17, 16), // "initCitaDeletion"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 3), // "row"
QT_MOC_LITERAL(4, 39, 22), // "filterQueryByCellphone"
QT_MOC_LITERAL(5, 62, 7), // "celular"
QT_MOC_LITERAL(6, 70, 21), // "filterQueryByLastName"
QT_MOC_LITERAL(7, 92, 9), // "apellidos"
QT_MOC_LITERAL(8, 102, 11), // "updateQuery"
QT_MOC_LITERAL(9, 114, 6), // "cabina"
QT_MOC_LITERAL(10, 121, 8), // "updateID"
QT_MOC_LITERAL(11, 130, 16), // "updateRowInTable"
QT_MOC_LITERAL(12, 147, 6), // "nombre"
QT_MOC_LITERAL(13, 154, 11), // "tratamiento"
QT_MOC_LITERAL(14, 166, 8), // "servicio"
QT_MOC_LITERAL(15, 175, 5), // "zonas"
QT_MOC_LITERAL(16, 181, 6), // "precio"
QT_MOC_LITERAL(17, 188, 6), // "sesion"
QT_MOC_LITERAL(18, 195, 15), // "sesionesPagadas"
QT_MOC_LITERAL(19, 211, 11), // "totalPagado"
QT_MOC_LITERAL(20, 223, 13), // "estatusDeCita"
QT_MOC_LITERAL(21, 237, 13), // "observaciones"
QT_MOC_LITERAL(22, 251, 14), // "importeCobrado"
QT_MOC_LITERAL(23, 266, 13), // "duracionIndex"
QT_MOC_LITERAL(24, 280, 21), // "clearRowsDueToBusyRow"
QT_MOC_LITERAL(25, 302, 10), // "deleteCita"
QT_MOC_LITERAL(26, 313, 5), // "fecha"
QT_MOC_LITERAL(27, 319, 10) // "rowIsEmpty"

    },
    "CabinaSQLQueries\0initCitaDeletion\0\0"
    "row\0filterQueryByCellphone\0celular\0"
    "filterQueryByLastName\0apellidos\0"
    "updateQuery\0cabina\0updateID\0"
    "updateRowInTable\0nombre\0tratamiento\0"
    "servicio\0zonas\0precio\0sesion\0"
    "sesionesPagadas\0totalPagado\0estatusDeCita\0"
    "observaciones\0importeCobrado\0duracionIndex\0"
    "clearRowsDueToBusyRow\0deleteCita\0fecha\0"
    "rowIsEmpty"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CabinaSQLQueries[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x02 /* Public */,
       4,    1,   62,    2, 0x02 /* Public */,
       6,    1,   65,    2, 0x02 /* Public */,
       8,    1,   68,    2, 0x02 /* Public */,
      10,    0,   71,    2, 0x02 /* Public */,
      11,   14,   72,    2, 0x02 /* Public */,
      24,    0,  101,    2, 0x02 /* Public */,
      25,    3,  102,    2, 0x02 /* Public */,
      27,    0,  109,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,   12,    7,    5,   13,   14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   26,    5,   14,
    QMetaType::Bool,

       0        // eod
};

void CabinaSQLQueries::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CabinaSQLQueries *_t = static_cast<CabinaSQLQueries *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initCitaDeletion((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->filterQueryByCellphone((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->filterQueryByLastName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->updateQuery((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->updateID(); break;
        case 5: _t->updateRowInTable((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< QString(*)>(_a[9])),(*reinterpret_cast< QString(*)>(_a[10])),(*reinterpret_cast< QString(*)>(_a[11])),(*reinterpret_cast< QString(*)>(_a[12])),(*reinterpret_cast< QString(*)>(_a[13])),(*reinterpret_cast< int(*)>(_a[14]))); break;
        case 6: _t->clearRowsDueToBusyRow(); break;
        case 7: _t->deleteCita((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 8: { bool _r = _t->rowIsEmpty();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject CabinaSQLQueries::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CabinaSQLQueries.data,
      qt_meta_data_CabinaSQLQueries,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CabinaSQLQueries::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CabinaSQLQueries::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CabinaSQLQueries.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CabinaSQLQueries::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
