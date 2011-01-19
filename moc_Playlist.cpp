/****************************************************************************
** Meta object code from reading C++ file 'Playlist.h'
**
** Created: Tue Jan 18 22:57:24 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Playlist.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Playlist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Playlist[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   10,    9,    9, 0x0a,
      42,    9,    9,    9, 0x0a,
      49,   10,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Playlist[] = {
    "Playlist\0\0song\0showSong(QListWidgetItem*)\0"
    "play()\0play(QListWidgetItem*)\0"
};

const QMetaObject Playlist::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_Playlist,
      qt_meta_data_Playlist, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Playlist::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Playlist::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Playlist::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Playlist))
        return static_cast<void*>(const_cast< Playlist*>(this));
    return QListWidget::qt_metacast(_clname);
}

int Playlist::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: showSong((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 1: play(); break;
        case 2: play((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
