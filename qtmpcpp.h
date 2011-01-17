/***************************************************************************
 *   Copyright (C) 2010 by Travis Thompson                                 *
 *   travisat@gmail.com			                                           *
 ***************************************************************************/
#pragma once
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include "Playlist.h"
#include "MpdHandler.h"
#include "SearchInput.h"

class qtmpcpp : public QWidget
{
    Q_OBJECT
    public:
        qtmpcpp(QWidget *parent = 0);
        ~qtmpcpp();
    private:
        Playlist *playlist;
        QPushButton *searchButton;
        SearchInput *searchInput;
        QVBoxLayout *layout;
};
