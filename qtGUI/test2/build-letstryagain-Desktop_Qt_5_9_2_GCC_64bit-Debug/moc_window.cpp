/****************************************************************************
** Meta object code from reading C++ file 'window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../letstryagain/window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Window_t {
    QByteArrayData data[18];
    char stringdata0[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Window_t qt_meta_stringdata_Window = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Window"
QT_MOC_LITERAL(1, 7, 12), // "startRunning"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 15), // "parallelRunning"
QT_MOC_LITERAL(4, 37, 12), // "pauseRunning"
QT_MOC_LITERAL(5, 50, 11), // "updateShape"
QT_MOC_LITERAL(6, 62, 11), // "updateSides"
QT_MOC_LITERAL(7, 74, 11), // "updateSpeed"
QT_MOC_LITERAL(8, 86, 13), // "updateWeights"
QT_MOC_LITERAL(9, 100, 13), // "resetControls"
QT_MOC_LITERAL(10, 114, 13), // "startRunning2"
QT_MOC_LITERAL(11, 128, 16), // "parallelRunning2"
QT_MOC_LITERAL(12, 145, 13), // "pauseRunning2"
QT_MOC_LITERAL(13, 159, 12), // "updateShape2"
QT_MOC_LITERAL(14, 172, 12), // "updateSides2"
QT_MOC_LITERAL(15, 185, 12), // "updateSpeed2"
QT_MOC_LITERAL(16, 198, 14), // "updateWeights2"
QT_MOC_LITERAL(17, 213, 14) // "resetControls2"

    },
    "Window\0startRunning\0\0parallelRunning\0"
    "pauseRunning\0updateShape\0updateSides\0"
    "updateSpeed\0updateWeights\0resetControls\0"
    "startRunning2\0parallelRunning2\0"
    "pauseRunning2\0updateShape2\0updateSides2\0"
    "updateSpeed2\0updateWeights2\0resetControls2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Window[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x0a /* Public */,
       3,    0,   95,    2, 0x0a /* Public */,
       4,    0,   96,    2, 0x0a /* Public */,
       5,    0,   97,    2, 0x0a /* Public */,
       6,    0,   98,    2, 0x0a /* Public */,
       7,    0,   99,    2, 0x0a /* Public */,
       8,    0,  100,    2, 0x0a /* Public */,
       9,    0,  101,    2, 0x0a /* Public */,
      10,    0,  102,    2, 0x0a /* Public */,
      11,    0,  103,    2, 0x0a /* Public */,
      12,    0,  104,    2, 0x0a /* Public */,
      13,    0,  105,    2, 0x0a /* Public */,
      14,    0,  106,    2, 0x0a /* Public */,
      15,    0,  107,    2, 0x0a /* Public */,
      16,    0,  108,    2, 0x0a /* Public */,
      17,    0,  109,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Window *_t = static_cast<Window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startRunning(); break;
        case 1: _t->parallelRunning(); break;
        case 2: _t->pauseRunning(); break;
        case 3: _t->updateShape(); break;
        case 4: _t->updateSides(); break;
        case 5: _t->updateSpeed(); break;
        case 6: _t->updateWeights(); break;
        case 7: _t->resetControls(); break;
        case 8: _t->startRunning2(); break;
        case 9: _t->parallelRunning2(); break;
        case 10: _t->pauseRunning2(); break;
        case 11: _t->updateShape2(); break;
        case 12: _t->updateSides2(); break;
        case 13: _t->updateSpeed2(); break;
        case 14: _t->updateWeights2(); break;
        case 15: _t->resetControls2(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Window::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Window.data,
      qt_meta_data_Window,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Window.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
