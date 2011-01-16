/***************************************************************************
 *   Copyright (C) 2010 by Travis Thompson                                 *
 *   travisat@gmail.com			                                           *
 ***************************************************************************/
#pragma once

#include <Qt/QWidget>

class Playlist: public QListBox
{
    public: 
        Playlist(QWidget *parent = 0, const char *name = 0);
        ~Playlist();
        void addSong(QString song);

    signals:
        void picked(const QString &song);

    private slots:
        void itemHighlighted(int index);
        void itemSelected(int index);

    private:
        QList<QString> *songs;
};
