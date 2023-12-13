/****************************************************************************
** Meta object code from reading C++ file 'pausewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../snake_3/pausewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pausewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PauseWindow_t {
    QByteArrayData data[8];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PauseWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PauseWindow_t qt_meta_stringdata_PauseWindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "PauseWindow"
QT_MOC_LITERAL(1, 12, 12), // "continueGame"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "openSettings"
QT_MOC_LITERAL(4, 39, 10), // "exitToMenu"
QT_MOC_LITERAL(5, 50, 23), // "onContinueButtonClicked"
QT_MOC_LITERAL(6, 74, 23), // "onSettingsButtonClicked"
QT_MOC_LITERAL(7, 98, 19) // "onExitButtonClicked"

    },
    "PauseWindow\0continueGame\0\0openSettings\0"
    "exitToMenu\0onContinueButtonClicked\0"
    "onSettingsButtonClicked\0onExitButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PauseWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PauseWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PauseWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->continueGame(); break;
        case 1: _t->openSettings(); break;
        case 2: _t->exitToMenu(); break;
        case 3: _t->onContinueButtonClicked(); break;
        case 4: _t->onSettingsButtonClicked(); break;
        case 5: _t->onExitButtonClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PauseWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PauseWindow::continueGame)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PauseWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PauseWindow::openSettings)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PauseWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PauseWindow::exitToMenu)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject PauseWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_PauseWindow.data,
    qt_meta_data_PauseWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PauseWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PauseWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PauseWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PauseWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void PauseWindow::continueGame()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PauseWindow::openSettings()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void PauseWindow::exitToMenu()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
