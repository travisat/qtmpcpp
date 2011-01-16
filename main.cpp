/***************************************************************************
 *   Copyright (C) 2010 by Travis Thompson                                 *
 *   travisat@gmail.com			                                           *
 ***************************************************************************/

#include <QWidget>
#include <QApplication>
#include <QHBoxLayout>
#include <QListWidget>
#include <QListWidgetItem>
#include "Playlist.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Playlist *playlist = new Playlist();
    playlist->addSong("test 1");
    playlist->addSong("test 2");
    playlist->addSong("test 3");

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(playlist);

    QWidget w;
    w.setStyleSheet("* { background-color:rgb(199,147,88); padding 7px; color:rgb(0,0,0)}");
    w.setLayout(layout);
    w.showNormal();

    return a.exec();

}
