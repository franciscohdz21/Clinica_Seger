/****************************************************************************
** Meta object code from reading C++ file 'agendarclienteviewdata.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../agendarclienteviewdata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'agendarclienteviewdata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AgendarClienteViewData_t {
    QByteArrayData data[17];
    char stringdata0[259];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AgendarClienteViewData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AgendarClienteViewData_t qt_meta_stringdata_AgendarClienteViewData = {
    {
QT_MOC_LITERAL(0, 0, 22), // "AgendarClienteViewData"
QT_MOC_LITERAL(1, 23, 13), // "nombreChanged"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 16), // "apellidosChanged"
QT_MOC_LITERAL(4, 55, 14), // "celularChanged"
QT_MOC_LITERAL(5, 70, 21), // "clienteEsNuevoChanged"
QT_MOC_LITERAL(6, 92, 30), // "tratamientoCurrentIndexChanged"
QT_MOC_LITERAL(7, 123, 27), // "clearNombreApellidosCelular"
QT_MOC_LITERAL(8, 151, 18), // "getHoraInicioForID"
QT_MOC_LITERAL(9, 170, 5), // "setID"
QT_MOC_LITERAL(10, 176, 3), // "row"
QT_MOC_LITERAL(11, 180, 14), // "isLastRowOfDay"
QT_MOC_LITERAL(12, 195, 6), // "nombre"
QT_MOC_LITERAL(13, 202, 9), // "apellidos"
QT_MOC_LITERAL(14, 212, 7), // "celular"
QT_MOC_LITERAL(15, 220, 14), // "clienteEsNuevo"
QT_MOC_LITERAL(16, 235, 23) // "tratamientoCurrentIndex"

    },
    "AgendarClienteViewData\0nombreChanged\0"
    "\0apellidosChanged\0celularChanged\0"
    "clienteEsNuevoChanged\0"
    "tratamientoCurrentIndexChanged\0"
    "clearNombreApellidosCelular\0"
    "getHoraInicioForID\0setID\0row\0"
    "isLastRowOfDay\0nombre\0apellidos\0celular\0"
    "clienteEsNuevo\0tratamientoCurrentIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AgendarClienteViewData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       5,   70, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,
       6,    0,   63,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       7,    0,   64,    2, 0x02 /* Public */,
       8,    0,   65,    2, 0x02 /* Public */,
       9,    1,   66,    2, 0x02 /* Public */,
      11,    0,   69,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Bool,

 // properties: name, type, flags
      12, QMetaType::QString, 0x00495103,
      13, QMetaType::QString, 0x00495103,
      14, QMetaType::QString, 0x00495103,
      15, QMetaType::Bool, 0x00495103,
      16, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,

       0        // eod
};

void AgendarClienteViewData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AgendarClienteViewData *_t = static_cast<AgendarClienteViewData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->nombreChanged(); break;
        case 1: _t->apellidosChanged(); break;
        case 2: _t->celularChanged(); break;
        case 3: _t->clienteEsNuevoChanged(); break;
        case 4: _t->tratamientoCurrentIndexChanged(); break;
        case 5: _t->clearNombreApellidosCelular(); break;
        case 6: { QString _r = _t->getHoraInicioForID();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->setID((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: { bool _r = _t->isLastRowOfDay();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (AgendarClienteViewData::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AgendarClienteViewData::nombreChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AgendarClienteViewData::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AgendarClienteViewData::apellidosChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (AgendarClienteViewData::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AgendarClienteViewData::celularChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (AgendarClienteViewData::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AgendarClienteViewData::clienteEsNuevoChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (AgendarClienteViewData::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AgendarClienteViewData::tratamientoCurrentIndexChanged)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        AgendarClienteViewData *_t = static_cast<AgendarClienteViewData *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->nombre(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->apellidos(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->celular(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->clienteEsNuevo(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->tratamientoCurrentIndex(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        AgendarClienteViewData *_t = static_cast<AgendarClienteViewData *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setNombre(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setApellidos(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setCelular(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setClienteEsNuevo(*reinterpret_cast< bool*>(_v)); break;
        case 4: _t->setTratamientoCurrentIndex(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject AgendarClienteViewData::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AgendarClienteViewData.data,
      qt_meta_data_AgendarClienteViewData,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AgendarClienteViewData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AgendarClienteViewData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AgendarClienteViewData.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AgendarClienteViewData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void AgendarClienteViewData::nombreChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AgendarClienteViewData::apellidosChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AgendarClienteViewData::celularChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void AgendarClienteViewData::clienteEsNuevoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void AgendarClienteViewData::tratamientoCurrentIndexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
