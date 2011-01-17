/***************************************************************************
 *   Copyright (C) 2010 by Travis Thompson                                 *
 *   travisat@gmail.com			                                           *
 ***************************************************************************/
#pragma once
#include <QLineEdit>
#include "MpdHandler.h"
#include "Playlist.h"

class SearchInput : public QLineEdit
{
    Q_OBJECT
    public:
        SearchInput(Playlist *playlist, QWidget *parent = 0);
    public slots:
        void search();
    private:
        Playlist *list;
};
