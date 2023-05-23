/****************************************************************************
** Meta object code from reading C++ file 'vercarro.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FSIPLeiria/vercarro.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vercarro.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSVerCarroENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSVerCarroENDCLASS = QtMocHelpers::stringData(
    "VerCarro",
    "setNome",
    "",
    "nome",
    "setTipo",
    "tipo",
    "setObservacoes",
    "obs",
    "on_commandButtonVoltar_clicked",
    "on_btnDefinicoes_clicked",
    "on_btnEstatistica_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSVerCarroENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[9];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[8];
    char stringdata5[5];
    char stringdata6[15];
    char stringdata7[4];
    char stringdata8[31];
    char stringdata9[25];
    char stringdata10[26];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSVerCarroENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSVerCarroENDCLASS_t qt_meta_stringdata_CLASSVerCarroENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "VerCarro"
        QT_MOC_LITERAL(9, 7),  // "setNome"
        QT_MOC_LITERAL(17, 0),  // ""
        QT_MOC_LITERAL(18, 4),  // "nome"
        QT_MOC_LITERAL(23, 7),  // "setTipo"
        QT_MOC_LITERAL(31, 4),  // "tipo"
        QT_MOC_LITERAL(36, 14),  // "setObservacoes"
        QT_MOC_LITERAL(51, 3),  // "obs"
        QT_MOC_LITERAL(55, 30),  // "on_commandButtonVoltar_clicked"
        QT_MOC_LITERAL(86, 24),  // "on_btnDefinicoes_clicked"
        QT_MOC_LITERAL(111, 25)   // "on_btnEstatistica_clicked"
    },
    "VerCarro",
    "setNome",
    "",
    "nome",
    "setTipo",
    "tipo",
    "setObservacoes",
    "obs",
    "on_commandButtonVoltar_clicked",
    "on_btnDefinicoes_clicked",
    "on_btnEstatistica_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSVerCarroENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x0a,    1 /* Public */,
       4,    1,   53,    2, 0x0a,    3 /* Public */,
       6,    1,   56,    2, 0x0a,    5 /* Public */,
       8,    0,   59,    2, 0x08,    7 /* Private */,
       9,    0,   60,    2, 0x08,    8 /* Private */,
      10,    0,   61,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject VerCarro::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSVerCarroENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSVerCarroENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSVerCarroENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<VerCarro, std::true_type>,
        // method 'setNome'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'setTipo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'setObservacoes'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_commandButtonVoltar_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnDefinicoes_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnEstatistica_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void VerCarro::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VerCarro *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setNome((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->setTipo((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->setObservacoes((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->on_commandButtonVoltar_clicked(); break;
        case 4: _t->on_btnDefinicoes_clicked(); break;
        case 5: _t->on_btnEstatistica_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *VerCarro::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VerCarro::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSVerCarroENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int VerCarro::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
