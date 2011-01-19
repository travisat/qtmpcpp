SOURCES += main.cpp

SOURCES += Playlist.cpp
HEADERS += Playlist.h

SOURCES += MpdHandler.cpp
HEADERS += MpdHandler.h

SOURCES += SearchInput.cpp
HEADERS += SearchInput.h

SOURCES += NowPlaying.cpp
HEADERS += NowPlaying.h

SOURCES += qtmpcpp.cpp
HEADERS += qtmpcpp.h

TARGET = qtmpcpp 

CONFIG += qt
CONFIG += link_pkgconfig
PKGCONFIG += libmpdclient
