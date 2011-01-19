/***************************************************************************
 *   Copyright (C) 2010 by Travis Thompson                                 *
 *   travisat@gmail.com			                                           *
 ***************************************************************************/

#pragma once

#include <mpd/client.h>
#include <QStringList>

class MpdHandler
{
    public:
        MpdHandler(const char* host, unsigned port=6600, unsigned timeout_ms=0);
        ~MpdHandler();
        bool connect();
        void disconnect();
        bool reconnect();
        
        QStringList search(QString query);
        QStringList playlist();
        void clear();
        void addSong(QString song);
        void play();
        void play(int i);
        int getSelectedIndex();
        const QString getCurrentSong();
    private:
        mpd_connection *conn;
        const char *mpdhost;
        unsigned mpdport;
        unsigned mpdtimeout_ms;
};
