SOURCES += main.cpp

SOURCES += Playlist.cpp
HEADERS += Playlist.h

SOURCES += MpdHandler.cpp
HEADERS += MpdHandler.h

TARGET = qtmpcpp 

CONFIG += qt
CONFIG += link_pkgconfig
PKGCONFIG += libmpdclient
