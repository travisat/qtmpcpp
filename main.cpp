/***************************************************************************
 *   Copyright (C) 2010 by Travis Thompson                                 *
 *   travisat@gmail.com			                                           *
 ***************************************************************************/

#include <QWidget>
#include <QApplication>
#include <QVBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QListWidgetItem>
#include "Playlist.h"
#include "MpdHandler.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Playlist *playlist = new Playlist();

    MpdHandler *handler = new MpdHandler("127.0.0.1");
    playlist->addItems(handler->search(argv[1]));

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(playlist);

    QPushButton *button = new QPushButton("reload");
    layout->addWidget(button);

    QTextEdit *text = new QTextEdit();
    layout->addWidget(text);

    QWidget w;
    w.setLayout(layout);
    w.showNormal();

    return a.exec();

}
