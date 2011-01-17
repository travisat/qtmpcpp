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
        
        QStringList search(QString query);
    private:
        const char *mpdhost;
        unsigned mpdport;
        unsigned mpdtimeout_ms;
};
