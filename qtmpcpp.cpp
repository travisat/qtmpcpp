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
    searchInput = new SearchInput(playlist);

    connect(searchButton,SIGNAL(clicked()),searchInput,SLOT(search()));

    layout = new QVBoxLayout();
    layout->addWidget(playlist);
    layout->addWidget(searchButton);
    layout->addWidget(searchInput);

    setLayout(layout);
}

qtmpcpp::~qtmpcpp()
{
    delete playlist;
    delete searchButton;
    delete searchInput;
    delete layout;
}
