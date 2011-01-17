/***************************************************************************
 *   Copyright (C) 2010 by Travis Thompson                                 *
 *   travisat@gmail.com			                                           *
 ***************************************************************************/
#pragma once

#include <QListWidget>

class Playlist: public QListWidget
{
    Q_OBJECT
    public: 
        Playlist(QWidget *parent = 0);
        void addSong(QString song);
        void reload(QStringList songs);

    public slots:
        void showSong(QListWidgetItem *song);
};
