/****************************************************************************
** Meta object code from reading C++ file 'gerirtipomensagem.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FSIPLeiria/gerirtipomensagem.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gerirtipomensagem.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSGerirTipoMensagemENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSGerirTipoMensagemENDCLASS = QtMocHelpers::stringData(
    "GerirTipoMensagem",
    "setNome",
    "",
    "nome",
    "setNomeModulo",
    "setCodigoHexadecimal",
    "codHex",
    "setObservacoes",
    "obs",
    "on_spinBox_valueChanged",
    "arg1",
    "on_commandButtonVoltar_clicked",
    "on_btnGuardarCarro_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSGerirTipoMensagemENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[18];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[14];
    char stringdata5[21];
    char stringdata6[7];
    char stringdata7[15];
    char stringdata8[4];
    char stringdata9[24];
    char stringdata10[5];
    char stringdata11[31];
    char stringdata12[27];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSGerirTipoMensagemENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSGerirTipoMensagemENDCLASS_t qt_meta_stringdata_CLASSGerirTipoMensagemENDCLASS = {
    {
        QT_MOC_LITERAL(0, 17),  // "GerirTipoMensagem"
        QT_MOC_LITERAL(18, 7),  // "setNome"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 4),  // "nome"
        QT_MOC_LITERAL(32, 13),  // "setNomeModulo"
        QT_MOC_LITERAL(46, 20),  // "setCodigoHexadecimal"
        QT_MOC_LITERAL(67, 6),  // "codHex"
        QT_MOC_LITERAL(74, 14),  // "setObservacoes"
        QT_MOC_LITERAL(89, 3),  // "obs"
        QT_MOC_LITERAL(93, 23),  // "on_spinBox_valueChanged"
        QT_MOC_LITERAL(117, 4),  // "arg1"
        QT_MOC_LITERAL(122, 30),  // "on_commandButtonVoltar_clicked"
        QT_MOC_LITERAL(153, 26)   // "on_btnGuardarCarro_clicked"
    },
    "GerirTipoMensagem",
    "setNome",
    "",
    "nome",
    "setNomeModulo",
    "setCodigoHexadecimal",
    "codHex",
    "setObservacoes",
    "obs",
    "on_spinBox_valueChanged",
    "arg1",
    "on_commandButtonVoltar_clicked",
    "on_btnGuardarCarro_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGerirTipoMensagemENDCLASS[] = {

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
       7,    1,   65,    2, 0x0a,    7 /* Public */,
       9,    1,   68,    2, 0x08,    9 /* Private */,
      11,    0,   71,    2, 0x08,   11 /* Private */,
      12,    0,   72,    2, 0x08,   12 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject GerirTipoMensagem::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSGerirTipoMensagemENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSGerirTipoMensagemENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSGerirTipoMensagemENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GerirTipoMensagem, std::true_type>,
        // method 'setNome'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'setNomeModulo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'setCodigoHexadecimal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'setObservacoes'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_spinBox_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_commandButtonVoltar_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnGuardarCarro_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void GerirTipoMensagem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GerirTipoMensagem *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setNome((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->setNomeModulo((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->setCodigoHexadecimal((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->setObservacoes((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->on_spinBox_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->on_commandButtonVoltar_clicked(); break;
        case 6: _t->on_btnGuardarCarro_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *GerirTipoMensagem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GerirTipoMensagem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSGerirTipoMensagemENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int GerirTipoMensagem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
