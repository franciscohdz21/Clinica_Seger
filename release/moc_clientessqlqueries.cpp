/****************************************************************************
** Meta object code from reading C++ file 'clientessqlqueries.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../clientessqlqueries.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientessqlqueries.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ClientesSQLQueries_t {
    QByteArrayData data[23];
    char stringdata0[315];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClientesSQLQueries_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClientesSQLQueries_t qt_meta_stringdata_ClientesSQLQueries = {
    {
QT_MOC_LITERAL(0, 0, 18), // "ClientesSQLQueries"
QT_MOC_LITERAL(1, 19, 11), // "updateQuery"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 22), // "filterQueryByCellphone"
QT_MOC_LITERAL(4, 55, 7), // "celular"
QT_MOC_LITERAL(5, 63, 21), // "filterQueryByLastName"
QT_MOC_LITERAL(6, 85, 9), // "apellidos"
QT_MOC_LITERAL(7, 95, 14), // "updatePaciente"
QT_MOC_LITERAL(8, 110, 6), // "nombre"
QT_MOC_LITERAL(9, 117, 8), // "telefono"
QT_MOC_LITERAL(10, 126, 6), // "correo"
QT_MOC_LITERAL(11, 133, 25), // "diaFechaDeNacimientoIndex"
QT_MOC_LITERAL(12, 159, 25), // "mesFechaDeNacimientoIndex"
QT_MOC_LITERAL(13, 185, 20), // "anoFechaDeNacimiento"
QT_MOC_LITERAL(14, 206, 12), // "calleYNumero"
QT_MOC_LITERAL(15, 219, 7), // "colonia"
QT_MOC_LITERAL(16, 227, 6), // "ciudad"
QT_MOC_LITERAL(17, 234, 6), // "estado"
QT_MOC_LITERAL(18, 241, 15), // "sesionesPagadas"
QT_MOC_LITERAL(19, 257, 11), // "saldoAFavor"
QT_MOC_LITERAL(20, 269, 18), // "sesionesDeGarantia"
QT_MOC_LITERAL(21, 288, 14), // "currentCelular"
QT_MOC_LITERAL(22, 303, 11) // "addPaciente"

    },
    "ClientesSQLQueries\0updateQuery\0\0"
    "filterQueryByCellphone\0celular\0"
    "filterQueryByLastName\0apellidos\0"
    "updatePaciente\0nombre\0telefono\0correo\0"
    "diaFechaDeNacimientoIndex\0"
    "mesFechaDeNacimientoIndex\0"
    "anoFechaDeNacimiento\0calleYNumero\0"
    "colonia\0ciudad\0estado\0sesionesPagadas\0"
    "saldoAFavor\0sesionesDeGarantia\0"
    "currentCelular\0addPaciente"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientesSQLQueries[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x02 /* Public */,
       3,    1,   40,    2, 0x02 /* Public */,
       5,    1,   43,    2, 0x02 /* Public */,
       7,   16,   46,    2, 0x02 /* Public */,
      22,    3,   79,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    8,    6,    4,    9,   10,   11,   12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    8,    6,    4,

       0        // eod
};

void ClientesSQLQueries::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClientesSQLQueries *_t = static_cast<ClientesSQLQueries *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateQuery(); break;
        case 1: _t->filterQueryByCellphone((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->filterQueryByLastName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->updatePaciente((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< QString(*)>(_a[9])),(*reinterpret_cast< QString(*)>(_a[10])),(*reinterpret_cast< QString(*)>(_a[11])),(*reinterpret_cast< QString(*)>(_a[12])),(*reinterpret_cast< QString(*)>(_a[13])),(*reinterpret_cast< QString(*)>(_a[14])),(*reinterpret_cast< QString(*)>(_a[15])),(*reinterpret_cast< QString(*)>(_a[16]))); break;
        case 4: _t->addPaciente((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject ClientesSQLQueries::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ClientesSQLQueries.data,
      qt_meta_data_ClientesSQLQueries,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ClientesSQLQueries::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientesSQLQueries::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ClientesSQLQueries.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ClientesSQLQueries::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
