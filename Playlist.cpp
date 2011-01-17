/***************************************************************************
 *   Copyright (C) 2010 by Travis Thompson                                 *
 *   travisat@gmail.com			                                           *
 ***************************************************************************/

#include "Playlist.h"
#include <iostream>

Playlist::Playlist(QWidget *parent)
    :QListWidget(parent)
{
    MpdHandler *handler = new MpdHandler("127.0.0.1");
    addItems(handler->playlist());
    delete handler;
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

    MpdHandler *handler = new MpdHandler("127.0.0.1");
    handler->clear();
    for (int i=0;i<count();i++) {
        handler->addSong(item(i)->text());
    }
    delete handler;
}

void Playlist::play()
{
    MpdHandler *handler = new MpdHandler("127.0.0.1");
    handler->play();
    delete handler;
}

void Playlist::play(QListWidgetItem *song)
{
   MpdHandler *handler = new MpdHandler("127.0.0.1"); 
   handler->play(row(song));
   delete handler;
}
