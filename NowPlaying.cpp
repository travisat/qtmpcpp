/***************************************************************************
 *   Copyright (C) 2010 by Travis Thompson                                 *
 *   travisat@gmail.com			                                           *
 ***************************************************************************/
#include "NowPlaying.h"

NowPlaying::NowPlaying(MpdHandler *mpdhandler, QWidget *parent, Qt::WindowFlags f)
    : QLabel(parent,f)
{
    handler = mpdhandler;
}

NowPlaying::~NowPlaying()
{
}

void NowPlaying::update()
{
    setText(handler->getCurrentSong());
}
