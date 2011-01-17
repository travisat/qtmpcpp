/***************************************************************************
 *   Copyright (C) 2010 by Travis Thompson                                 *
 *   travisat@gmail.com			                                           *
 ***************************************************************************/
#include "SearchInput.h"

SearchInput::SearchInput(Playlist *playlist, QWidget *parent)
    : QLineEdit(parent)
{
    list = playlist;
}

void SearchInput::search()
{
    MpdHandler *handler = new MpdHandler("127.0.0.1");
    list->reload(handler->search(text()));
    delete handler;
}
