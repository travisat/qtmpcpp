/***************************************************************************
 *   Copyright (C) 2010 by Travis Thompson                                 *
 *   travisat@gmail.com			                                           *
 ***************************************************************************/
#pragma once

#include <QListWidget>
#include "MpdHandler.h"

class Playlist: public QListWidget
{
    Q_OBJECT
    public: 
        Playlist(MpdHandler *mpdhandler, QWidget *parent = 0);
        void addSong(QString song);
        void reload(QStringList songs);

    public slots:
        void showSong(QListWidgetItem *song);
        void play();
        void play(QListWidgetItem *song);
    private:
        MpdHandler *handler;
};
