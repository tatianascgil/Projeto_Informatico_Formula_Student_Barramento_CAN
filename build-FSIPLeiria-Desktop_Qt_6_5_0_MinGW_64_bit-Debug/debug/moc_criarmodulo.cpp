/****************************************************************************
** Meta object code from reading C++ file 'criarmodulo.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Senna/criarmodulo.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'criarmodulo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.0. It"
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
struct qt_meta_stringdata_CLASSCriarModuloENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSCriarModuloENDCLASS = QtMocHelpers::stringData(
    "CriarModulo",
    "setNome",
    "",
    "nome",
    "on_btnCriarModulo_clicked",
    "on_commandButtonVoltar_clicked",
    "previousWindow"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSCriarModuloENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[12];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[26];
    char stringdata5[31];
    char stringdata6[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSCriarModuloENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSCriarModuloENDCLASS_t qt_meta_stringdata_CLASSCriarModuloENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "CriarModulo"
        QT_MOC_LITERAL(12, 7),  // "setNome"
        QT_MOC_LITERAL(20, 0),  // ""
        QT_MOC_LITERAL(21, 4),  // "nome"
        QT_MOC_LITERAL(26, 25),  // "on_btnCriarModulo_clicked"
        QT_MOC_LITERAL(52, 30),  // "on_commandButtonVoltar_clicked"
        QT_MOC_LITERAL(83, 14)   // "previousWindow"
    },
    "CriarModulo",
    "setNome",
    "",
    "nome",
    "on_btnCriarModulo_clicked",
    "on_commandButtonVoltar_clicked",
    "previousWindow"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCriarModuloENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x0a,    1 /* Public */,
       4,    0,   41,    2, 0x08,    3 /* Private */,
       5,    0,   42,    2, 0x08,    4 /* Private */,
       6,    0,   43,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject CriarModulo::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSCriarModuloENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCriarModuloENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCriarModuloENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CriarModulo, std::true_type>,
        // method 'setNome'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_btnCriarModulo_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_commandButtonVoltar_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'previousWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void CriarModulo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CriarModulo *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setNome((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->on_btnCriarModulo_clicked(); break;
        case 2: _t->on_commandButtonVoltar_clicked(); break;
        case 3: _t->previousWindow(); break;
        default: ;
        }
    }
}

const QMetaObject *CriarModulo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CriarModulo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCriarModuloENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CriarModulo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
