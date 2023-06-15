/****************************************************************************
** Meta object code from reading C++ file 'criarcarro.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FSIPLeiria/criarcarro.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'criarcarro.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSCriarCarroENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSCriarCarroENDCLASS = QtMocHelpers::stringData(
    "CriarCarro",
    "loadTiposCarro",
    "",
    "on_btnCriarCarro_clicked",
    "on_commandButtonVoltar_clicked",
    "previousWindow"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSCriarCarroENDCLASS_t {
    uint offsetsAndSizes[12];
    char stringdata0[11];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[25];
    char stringdata4[31];
    char stringdata5[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSCriarCarroENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSCriarCarroENDCLASS_t qt_meta_stringdata_CLASSCriarCarroENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "CriarCarro"
        QT_MOC_LITERAL(11, 14),  // "loadTiposCarro"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 24),  // "on_btnCriarCarro_clicked"
        QT_MOC_LITERAL(52, 30),  // "on_commandButtonVoltar_clicked"
        QT_MOC_LITERAL(83, 14)   // "previousWindow"
    },
    "CriarCarro",
    "loadTiposCarro",
    "",
    "on_btnCriarCarro_clicked",
    "on_commandButtonVoltar_clicked",
    "previousWindow"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCriarCarroENDCLASS[] = {

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
       1,    0,   38,    2, 0x0a,    1 /* Public */,
       3,    0,   39,    2, 0x08,    2 /* Private */,
       4,    0,   40,    2, 0x08,    3 /* Private */,
       5,    0,   41,    2, 0x08,    4 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject CriarCarro::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSCriarCarroENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCriarCarroENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCriarCarroENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CriarCarro, std::true_type>,
        // method 'loadTiposCarro'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnCriarCarro_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_commandButtonVoltar_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'previousWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void CriarCarro::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CriarCarro *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->loadTiposCarro(); break;
        case 1: _t->on_btnCriarCarro_clicked(); break;
        case 2: _t->on_commandButtonVoltar_clicked(); break;
        case 3: _t->previousWindow(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *CriarCarro::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CriarCarro::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCriarCarroENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CriarCarro::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
