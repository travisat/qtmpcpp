/***************************************************************************
 *   Copyright (C) 2010 by Travis Thompson                                 *
 *   travisat@gmail.com			                                           *
 ***************************************************************************/
#include "MpdHandler.h"
#include <iostream>

MpdHandler::MpdHandler(const char* host, unsigned port, unsigned timeout_ms)
{
    mpdhost = host;
    mpdport = port;
    mpdtimeout_ms = timeout_ms;
}

bool MpdHandler::connect()
{
    if (!(conn = mpd_connection_new(mpdhost,mpdport,mpdtimeout_ms))) {
        return false;
    }
    return true;
}

void MpdHandler::disconnect()
{
    mpd_connection_free(conn);
}

bool MpdHandler::reconnect()
{
    disconnect();
    return connect();
}

MpdHandler::~MpdHandler()
{
    disconnect();
}

QStringList MpdHandler::search(QString query)
{
    reconnect();
    
    QStringList results;

    mpd_search_db_songs(conn,0);
    mpd_search_add_any_tag_constraint(conn, MPD_OPERATOR_DEFAULT, (query.toStdString().c_str()));

    if (!mpd_search_commit(conn)) {
        results.append("No Results Found");
        return results;
    }

    struct mpd_song *song;
    while ((song = mpd_recv_song(conn)) != NULL) {
        results.append((mpd_song_get_uri(song)));
        mpd_song_free(song);
    }

    if (mpd_connection_get_error(conn) != MPD_ERROR_SUCCESS) {
        results.append("Error");
    }
    return results;
}

QStringList MpdHandler::playlist()
{
    reconnect();

    QStringList list;
    mpd_song *song;
    if (!mpd_send_list_queue_meta(conn))
        return list;
    while ((song = mpd_recv_song(conn)) != NULL ) {
        list.append(mpd_song_get_uri(song));
    }
    return list;
}

const QString MpdHandler::getCurrentSong()
{
    reconnect();
    mpd_song *song;
    song = mpd_run_current_song(conn);
    if (!song) {
        return QString("No song selected");
    }
    return QString(mpd_song_get_uri(song));
}

void MpdHandler::clear()
{
    reconnect();
    mpd_run_clear(conn);
}

void MpdHandler::addSong(QString song)
{
    reconnect();
    mpd_send_add(conn, song.toStdString().c_str());
}

void MpdHandler::play()
{
    //purge conn
    reconnect();
    mpd_status *status = mpd_run_status(conn);
    if (mpd_status_get_state(status) == MPD_STATE_PLAY) {
        mpd_send_pause(conn,true);
    } else {
        mpd_run_play(conn);
    }
    mpd_status_free(status);
}

void MpdHandler::play(int i)
{
    //purge conn
    reconnect();
    mpd_run_play_pos(conn, i);
}

int MpdHandler::getSelectedIndex()
{
    //purge conn
    reconnect();

    mpd_status *status = mpd_run_status(conn);
    int selected = mpd_status_get_song_pos(status);
    mpd_status_free(status);
    return selected;
}
