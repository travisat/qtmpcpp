/***************************************************************************
 *   Copyright (C) 2010 by Travis Thompson                                 *
 *   travisat@gmail.com			                                           *
 ***************************************************************************/
#include "qtmpcpp.h"

qtmpcpp::qtmpcpp(QWidget *parent, Qt::WindowFlags flags)
    :QMainWindow(parent,flags)
{
    handler = new MpdHandler("127.0.0.1");
    handler->connect();
    playlist = new Playlist(handler);
    searchButton = new QPushButton("Search");
    playButton = new QPushButton("Play");

    searchInput = new SearchInput(playlist,handler);
    searchInput->setFocus();

    status = new QStatusBar();
    setStatusBar(status);

    nowPlayingBar = new NowPlaying(handler);
    timer = new QTimer(this);
    status->addWidget(nowPlayingBar);

    connect(searchButton,SIGNAL(clicked()),searchInput,SLOT(search()));
    connect(playButton,SIGNAL(clicked()),playlist,SLOT(play()));
    connect(searchInput,SIGNAL(returnPressed()),searchInput,SLOT(search()));
    connect(playlist,SIGNAL(itemDoubleClicked(QListWidgetItem*)), playlist, SLOT(play(QListWidgetItem*)));
    connect(timer,SIGNAL(timeout()),nowPlayingBar,SLOT(update()));
    timer->start(100);

    panel = new QWidget();
    QHBoxLayout *playout = new QHBoxLayout();
    playout->addWidget(searchInput);
    playout->addWidget(searchButton);
    playout->addWidget(playButton);
    panel->setLayout(playout);

    layout = new QVBoxLayout();
    layout->addWidget(panel);
    layout->addWidget(playlist);

    main = new QWidget();
    main->setLayout(layout);
    
    
    setCentralWidget(main);
}

qtmpcpp::~qtmpcpp()
{
    delete playlist;
    delete searchButton;
    delete searchInput;
    delete handler;
    delete layout;
}
