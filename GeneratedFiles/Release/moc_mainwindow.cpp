/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../inc/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[221];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 10), // "openCamera"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 11), // "closeCamera"
QT_MOC_LITERAL(4, 35, 11), // "pauseCamera"
QT_MOC_LITERAL(5, 47, 10), // "beginVideo"
QT_MOC_LITERAL(6, 58, 11), // "finishVideo"
QT_MOC_LITERAL(7, 70, 11), // "updateImage"
QT_MOC_LITERAL(8, 82, 5), // "image"
QT_MOC_LITERAL(9, 88, 17), // "changeToGrayImage"
QT_MOC_LITERAL(10, 106, 4), // "flag"
QT_MOC_LITERAL(11, 111, 24), // "changeToGrayInverseImage"
QT_MOC_LITERAL(12, 136, 18), // "changeToColorImage"
QT_MOC_LITERAL(13, 155, 20), // "changeToRainbowImage"
QT_MOC_LITERAL(14, 176, 8), // "saveData"
QT_MOC_LITERAL(15, 185, 16), // "chooseSavingPath"
QT_MOC_LITERAL(16, 202, 9), // "takeImage"
QT_MOC_LITERAL(17, 212, 8) // "openFile"

    },
    "MainWindow\0openCamera\0\0closeCamera\0"
    "pauseCamera\0beginVideo\0finishVideo\0"
    "updateImage\0image\0changeToGrayImage\0"
    "flag\0changeToGrayInverseImage\0"
    "changeToColorImage\0changeToRainbowImage\0"
    "saveData\0chooseSavingPath\0takeImage\0"
    "openFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    0,   85,    2, 0x0a /* Public */,
       4,    0,   86,    2, 0x0a /* Public */,
       5,    0,   87,    2, 0x0a /* Public */,
       6,    0,   88,    2, 0x0a /* Public */,
       7,    1,   89,    2, 0x0a /* Public */,
       9,    1,   92,    2, 0x0a /* Public */,
      11,    1,   95,    2, 0x0a /* Public */,
      12,    1,   98,    2, 0x0a /* Public */,
      13,    1,  101,    2, 0x0a /* Public */,
      14,    0,  104,    2, 0x0a /* Public */,
      15,    0,  105,    2, 0x0a /* Public */,
      16,    0,  106,    2, 0x0a /* Public */,
      17,    0,  107,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPixmap,    8,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openCamera(); break;
        case 1: _t->closeCamera(); break;
        case 2: _t->pauseCamera(); break;
        case 3: _t->beginVideo(); break;
        case 4: _t->finishVideo(); break;
        case 5: _t->updateImage((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 6: _t->changeToGrayImage((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->changeToGrayInverseImage((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->changeToColorImage((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->changeToRainbowImage((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->saveData(); break;
        case 11: _t->chooseSavingPath(); break;
        case 12: _t->takeImage(); break;
        case 13: _t->openFile(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
