/****************************************************************************
** Meta object code from reading C++ file 'Threadrec1.h'
**
** Created: Tue Nov 17 11:38:33 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Threadrec1.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Threadrec1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ThreadRec1[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      30,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ThreadRec1[] = {
    "ThreadRec1\0\0mesRecv1(QString)\0stop()\0"
};

void ThreadRec1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ThreadRec1 *_t = static_cast<ThreadRec1 *>(_o);
        switch (_id) {
        case 0: _t->mesRecv1((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->stop(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ThreadRec1::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ThreadRec1::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ThreadRec1,
      qt_meta_data_ThreadRec1, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ThreadRec1::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ThreadRec1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ThreadRec1::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadRec1))
        return static_cast<void*>(const_cast< ThreadRec1*>(this));
    return QThread::qt_metacast(_clname);
}

int ThreadRec1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ThreadRec1::mesRecv1(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
