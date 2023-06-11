/****************************************************************************
** Meta object code from reading C++ file 'tabeladados.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FSIPLeiria/tabeladados.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tabeladados.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSTabelaDadosENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSTabelaDadosENDCLASS = QtMocHelpers::stringData(
    "TabelaDados",
    "loadMensagens",
    "",
    "setNome",
    "nome",
    "setModulos",
    "setCodigosHex",
    "setCampos",
    "setOperador",
    "on_btnFiltrar_clicked",
    "on_commandButtonVoltar_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSTabelaDadosENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[12];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[5];
    char stringdata5[11];
    char stringdata6[14];
    char stringdata7[10];
    char stringdata8[12];
    char stringdata9[22];
    char stringdata10[31];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSTabelaDadosENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSTabelaDadosENDCLASS_t qt_meta_stringdata_CLASSTabelaDadosENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "TabelaDados"
        QT_MOC_LITERAL(12, 13),  // "loadMensagens"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 7),  // "setNome"
        QT_MOC_LITERAL(35, 4),  // "nome"
        QT_MOC_LITERAL(40, 10),  // "setModulos"
        QT_MOC_LITERAL(51, 13),  // "setCodigosHex"
        QT_MOC_LITERAL(65, 9),  // "setCampos"
        QT_MOC_LITERAL(75, 11),  // "setOperador"
        QT_MOC_LITERAL(87, 21),  // "on_btnFiltrar_clicked"
        QT_MOC_LITERAL(109, 30)   // "on_commandButtonVoltar_clicked"
    },
    "TabelaDados",
    "loadMensagens",
    "",
    "setNome",
    "nome",
    "setModulos",
    "setCodigosHex",
    "setCampos",
    "setOperador",
    "on_btnFiltrar_clicked",
    "on_commandButtonVoltar_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTabelaDadosENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x0a,    1 /* Public */,
       3,    1,   63,    2, 0x0a,    2 /* Public */,
       5,    1,   66,    2, 0x0a,    4 /* Public */,
       6,    1,   69,    2, 0x0a,    6 /* Public */,
       7,    1,   72,    2, 0x0a,    8 /* Public */,
       8,    0,   75,    2, 0x0a,   10 /* Public */,
       9,    0,   76,    2, 0x08,   11 /* Private */,
      10,    0,   77,    2, 0x08,   12 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject TabelaDados::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSTabelaDadosENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTabelaDadosENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTabelaDadosENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TabelaDados, std::true_type>,
        // method 'loadMensagens'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setNome'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'setModulos'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'setCodigosHex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'setCampos'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'setOperador'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnFiltrar_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_commandButtonVoltar_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void TabelaDados::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TabelaDados *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->loadMensagens(); break;
        case 1: _t->setNome((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->setModulos((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->setCodigosHex((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->setCampos((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->setOperador(); break;
        case 6: _t->on_btnFiltrar_clicked(); break;
        case 7: _t->on_commandButtonVoltar_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *TabelaDados::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TabelaDados::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTabelaDadosENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int TabelaDados::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
