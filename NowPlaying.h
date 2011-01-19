/***************************************************************************
 *   Copyright (C) 2010 by Travis Thompson                                 *
 *   travisat@gmail.com			                                           *
 ***************************************************************************/
#pragma once

#include <QLabel>
#include "MpdHandler.h"

class NowPlaying : public QLabel
{
    Q_OBJECT
    public:
        NowPlaying(MpdHandler *mpdhandler, QWidget *parent=0, Qt::WindowFlags f = 0);
        ~NowPlaying();
    public slots:
        void update();
    private:
        MpdHandler *handler;
};
