/****************************************************************************
** Meta object code from reading C++ file 'gerircarro.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FSIPLeiria/gerircarro.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gerircarro.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSGerirCarroENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSGerirCarroENDCLASS = QtMocHelpers::stringData(
    "GerirCarro",
    "setNome",
    "",
    "nome",
    "lerDadosCarro",
    "openGerirModuloWindow",
    "QModelIndex",
    "index",
    "on_commandButtonVoltar_clicked",
    "on_btnCriarModulo_clicked",
    "on_btnApagarCarro_clicked",
    "on_btnGuardarCarro_clicked",
    "updateButtonVisibility"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSGerirCarroENDCLASS_t {
    uint offsetsAndSizes[20];
    uint offsetsAndSizes[24];
    char stringdata0[11];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[14];
    char stringdata5[22];
    char stringdata6[12];
    char stringdata7[6];
    char stringdata8[31];
    char stringdata9[26];
    char stringdata10[26];
    char stringdata11[27];
    char stringdata9[23];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSGerirCarroENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSGerirCarroENDCLASS_t qt_meta_stringdata_CLASSGerirCarroENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "GerirCarro"
        QT_MOC_LITERAL(11, 7),  // "setNome"
        QT_MOC_LITERAL(19, 0),  // ""
        QT_MOC_LITERAL(20, 4),  // "nome"
        QT_MOC_LITERAL(25, 13),  // "lerDadosCarro"
        QT_MOC_LITERAL(39, 21),  // "openGerirModuloWindow"
        QT_MOC_LITERAL(61, 11),  // "QModelIndex"
        QT_MOC_LITERAL(73, 5),  // "index"
        QT_MOC_LITERAL(79, 30),  // "on_commandButtonVoltar_clicked"
        QT_MOC_LITERAL(110, 25),  // "on_btnCriarModulo_clicked"
        QT_MOC_LITERAL(136, 25),  // "on_btnApagarCarro_clicked"
        QT_MOC_LITERAL(162, 26)   // "on_btnGuardarCarro_clicked"
        QT_MOC_LITERAL(149, 22)   // "updateButtonVisibility"
    },
    "GerirCarro",
    "setNome",
    "",
    "nome",
    "lerDadosCarro",
    "openGerirModuloWindow",
    "QModelIndex",
    "index",
    "on_commandButtonVoltar_clicked",
    "on_btnCriarModulo_clicked",
    "on_btnApagarCarro_clicked",
    "on_btnGuardarCarro_clicked",
    "updateButtonVisibility"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGerirCarroENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x0a,    1 /* Public */,
       4,    1,   59,    2, 0x0a,    3 /* Public */,
       5,    1,   62,    2, 0x0a,    5 /* Public */,
       8,    0,   65,    2, 0x08,    7 /* Private */,
       9,    0,   66,    2, 0x08,    8 /* Private */,
      10,    0,   67,    2, 0x08,    9 /* Private */,
      11,    0,   68,    2, 0x08,   10 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject GerirCarro::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSGerirCarroENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSGerirCarroENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSGerirCarroENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GerirCarro, std::true_type>,
        // method 'setNome'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'lerDadosCarro'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'openGerirModuloWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'on_commandButtonVoltar_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnCriarModulo_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnApagarCarro_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnGuardarCarro_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateButtonVisibility'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void GerirCarro::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GerirCarro *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setNome((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->lerDadosCarro((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->openGerirModuloWindow((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 3: _t->on_commandButtonVoltar_clicked(); break;
        case 4: _t->on_btnCriarModulo_clicked(); break;
        case 5: _t->on_btnApagarCarro_clicked(); break;
        case 6: _t->on_btnGuardarCarro_clicked(); break;
        case 7: _t->updateButtonVisibility(); break;
        default: ;
        }
    }
}

const QMetaObject *GerirCarro::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GerirCarro::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSGerirCarroENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GerirCarro::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
