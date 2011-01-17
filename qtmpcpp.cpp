/***************************************************************************
 *   Copyright (C) 2010 by Travis Thompson                                 *
 *   travisat@gmail.com			                                           *
 ***************************************************************************/
#include "qtmpcpp.h"

qtmpcpp::qtmpcpp(QWidget *parent)
    :QWidget(parent)
{
    playlist = new Playlist();
    searchButton = new QPushButton("Search");
    playButton = new QPushButton("Play");

    searchInput = new SearchInput(playlist);
    searchInput->setFocus();

    connect(searchButton,SIGNAL(clicked()),searchInput,SLOT(search()));
    connect(playButton,SIGNAL(clicked()),playlist,SLOT(play()));
    connect(searchInput,SIGNAL(returnPressed()),searchInput,SLOT(search()));
    connect(playlist,SIGNAL(itemDoubleClicked(QListWidgetItem*)), playlist, SLOT(play(QListWidgetItem*)));

    panel = new QWidget();
    QHBoxLayout *playout = new QHBoxLayout();
    playout->addWidget(searchInput);
    playout->addWidget(searchButton);
    playout->addWidget(playButton);
    panel->setLayout(playout);

    layout = new QVBoxLayout();
    layout->addWidget(panel);
    layout->addWidget(playlist);

    setLayout(layout);

}

qtmpcpp::~qtmpcpp()
{
    delete playlist;
    delete searchButton;
    delete searchInput;
    delete layout;
}
