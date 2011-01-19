/***************************************************************************
 *   Copyright (C) 2010 by Travis Thompson                                 *
 *   travisat@gmail.com			                                           *
 ***************************************************************************/
#pragma once
#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QStatusBar>
#include <QTimer>
#include "Playlist.h"
#include "MpdHandler.h"
#include "SearchInput.h"
#include "NowPlaying.h"

class qtmpcpp : public QMainWindow
{
    public:
        qtmpcpp(QWidget *parent = 0, Qt::WindowFlags flags = 0);
        ~qtmpcpp();
    private:
        Playlist *playlist;
        QPushButton *searchButton;
        QPushButton *playButton;
        SearchInput *searchInput;
        NowPlaying *nowPlayingBar;
        QTimer *timer;
        QVBoxLayout *layout;
        QWidget *main;
        QWidget *panel;
        QStatusBar* status;
        MpdHandler *handler;
};
