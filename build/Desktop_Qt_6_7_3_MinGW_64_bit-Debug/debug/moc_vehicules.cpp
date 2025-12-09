/****************************************************************************
** Meta object code from reading C++ file 'vehicules.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../vehicules.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vehicules.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSVehiculesENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSVehiculesENDCLASS = QtMocHelpers::stringData(
    "Vehicules",
    "ajouterVehicule",
    "",
    "modifierVehicule",
    "supprimerVehicule",
    "rechercherVehicule",
    "selectionnerVehicule",
    "QModelIndex",
    "index",
    "onAjouterButtonClicked",
    "onModifierButtonClicked",
    "onSupprimerButtonClicked",
    "onRechercherButtonClicked",
    "onTableViewClicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSVehiculesENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x0a,    1 /* Public */,
       3,    0,   81,    2, 0x0a,    2 /* Public */,
       4,    0,   82,    2, 0x0a,    3 /* Public */,
       5,    0,   83,    2, 0x0a,    4 /* Public */,
       6,    1,   84,    2, 0x0a,    5 /* Public */,
       6,    0,   87,    2, 0x2a,    7 /* Public | MethodCloned */,
       9,    0,   88,    2, 0x08,    8 /* Private */,
      10,    0,   89,    2, 0x08,    9 /* Private */,
      11,    0,   90,    2, 0x08,   10 /* Private */,
      12,    0,   91,    2, 0x08,   11 /* Private */,
      13,    1,   92,    2, 0x08,   12 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

Q_CONSTINIT const QMetaObject Vehicules::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSVehiculesENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSVehiculesENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSVehiculesENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Vehicules, std::true_type>,
        // method 'ajouterVehicule'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'modifierVehicule'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'supprimerVehicule'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'rechercherVehicule'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'selectionnerVehicule'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'selectionnerVehicule'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAjouterButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onModifierButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSupprimerButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRechercherButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onTableViewClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>
    >,
    nullptr
} };

void Vehicules::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Vehicules *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ajouterVehicule(); break;
        case 1: _t->modifierVehicule(); break;
        case 2: _t->supprimerVehicule(); break;
        case 3: _t->rechercherVehicule(); break;
        case 4: _t->selectionnerVehicule((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 5: _t->selectionnerVehicule(); break;
        case 6: _t->onAjouterButtonClicked(); break;
        case 7: _t->onModifierButtonClicked(); break;
        case 8: _t->onSupprimerButtonClicked(); break;
        case 9: _t->onRechercherButtonClicked(); break;
        case 10: _t->onTableViewClicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *Vehicules::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Vehicules::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSVehiculesENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Vehicules::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
