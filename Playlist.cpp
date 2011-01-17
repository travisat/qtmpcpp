/***************************************************************************
 *   Copyright (C) 2010 by Travis Thompson                                 *
 *   travisat@gmail.com			                                           *
 ***************************************************************************/

#include "Playlist.h"
#include <iostream>

Playlist::Playlist(QWidget *parent)
    :QListWidget(parent)
{
    connect(this, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(showSong(QListWidgetItem*)));
}

void Playlist::addSong(QString song)
{
    addItem( new QListWidgetItem(song,this) );
}

void Playlist::showSong(QListWidgetItem *song)
{
    std::cout << "Song: " << song->text().toStdString() << std::endl;
}

void Playlist::reload(QStringList songs)
{
    while (count() > 0) {
        takeItem(0);
    }

    addItems(songs);
}
