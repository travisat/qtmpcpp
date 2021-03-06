/***************************************************************************
 *   Copyright (C) 2010 by Travis Thompson                                 *
 *   travisat@gmail.com			                                           *
 ***************************************************************************/
#include "SearchInput.h"

SearchInput::SearchInput(Playlist *playlist, MpdHandler *mpdhandler, QWidget *parent)
    : QLineEdit(parent)
{
    list = playlist;
    handler = mpdhandler;
}

void SearchInput::search()
{
    list->reload(handler->search(text()));
}
