/****************************************************************************
** Meta object code from reading C++ file 'game.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../snake_3/game.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameField_t {
    QByteArrayData data[9];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameField_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameField_t qt_meta_stringdata_GameField = {
    {
QT_MOC_LITERAL(0, 0, 9), // "GameField"
QT_MOC_LITERAL(1, 10, 16), // "ChangeTextSignal"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 4), // "text"
QT_MOC_LITERAL(4, 33, 10), // "altPressed"
QT_MOC_LITERAL(5, 44, 13), // "MoveSnakeSlot"
QT_MOC_LITERAL(6, 58, 11), // "RemoveBonus"
QT_MOC_LITERAL(7, 70, 16), // "changeSnakeColor"
QT_MOC_LITERAL(8, 87, 5) // "color"

    },
    "GameField\0ChangeTextSignal\0\0text\0"
    "altPressed\0MoveSnakeSlot\0RemoveBonus\0"
    "changeSnakeColor\0color"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameField[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    0,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   43,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    1,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void GameField::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameField *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ChangeTextSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->altPressed(); break;
        case 2: _t->MoveSnakeSlot(); break;
        case 3: _t->RemoveBonus(); break;
        case 4: _t->changeSnakeColor((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GameField::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameField::ChangeTextSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GameField::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameField::altPressed)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GameField::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_GameField.data,
    qt_meta_data_GameField,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GameField::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameField::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameField.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GameField::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void GameField::ChangeTextSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GameField::altPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
