/****************************************************************************
** Meta object code from reading C++ file 'sourcewindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Uc1GUI/sourcewindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sourcewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SourceWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      35,   13,   13,   13, 0x08,
      57,   13,   13,   13, 0x08,
      79,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SourceWindow[] = {
    "SourceWindow\0\0on_exitBut_clicked()\0"
    "on_scoreBut_clicked()\0on_startBut_clicked()\0"
    "on_testBut_clicked()\0"
};

void SourceWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SourceWindow *_t = static_cast<SourceWindow *>(_o);
        switch (_id) {
        case 0: _t->on_exitBut_clicked(); break;
        case 1: _t->on_scoreBut_clicked(); break;
        case 2: _t->on_startBut_clicked(); break;
        case 3: _t->on_testBut_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData SourceWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SourceWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SourceWindow,
      qt_meta_data_SourceWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SourceWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SourceWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SourceWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SourceWindow))
        return static_cast<void*>(const_cast< SourceWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SourceWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
