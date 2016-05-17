/****************************************************************************
** Meta object code from reading C++ file 'systemtester.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Uc1GUI/systemtester.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'systemtester.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_systemtester[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      39,   13,   13,   13, 0x08,
      61,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_systemtester[] = {
    "systemtester\0\0on_activateBut_clicked()\0"
    "on_clearBut_clicked()\0on_exitBut_clicked()\0"
};

void systemtester::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        systemtester *_t = static_cast<systemtester *>(_o);
        switch (_id) {
        case 0: _t->on_activateBut_clicked(); break;
        case 1: _t->on_clearBut_clicked(); break;
        case 2: _t->on_exitBut_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData systemtester::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject systemtester::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_systemtester,
      qt_meta_data_systemtester, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &systemtester::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *systemtester::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *systemtester::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_systemtester))
        return static_cast<void*>(const_cast< systemtester*>(this));
    return QDialog::qt_metacast(_clname);
}

int systemtester::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
