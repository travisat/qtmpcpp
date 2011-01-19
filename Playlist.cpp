/***************************************************************************
 *   Copyright (C) 2010 by Travis Thompson                                 *
 *   travisat@gmail.com			                                           *
 ***************************************************************************/

#include "Playlist.h"
#include <iostream>

Playlist::Playlist(MpdHandler *mpdhandler, QWidget *parent)
    :QListWidget(parent)
{
    handler = mpdhandler; 
    addItems(handler->playlist());
    int selected = handler->getSelectedIndex();
    setCurrentRow(selected);
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

    handler->clear();
    for (int i=0;i<count();i++) {
        handler->addSong(item(i)->text());
    }
}

void Playlist::play()
{
    handler->play();
}

void Playlist::play(QListWidgetItem *song)
{
   handler->play(row(song));
}
