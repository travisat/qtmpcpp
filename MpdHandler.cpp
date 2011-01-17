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

QStringList MpdHandler::search(QString query)
{
    QStringList results;
    mpd_connection *conn = mpd_connection_new(mpdhost,mpdport,mpdtimeout_ms);

    mpd_search_db_songs(conn,0);
    mpd_search_add_any_tag_constraint(conn, MPD_OPERATOR_DEFAULT, (query.toStdString().c_str()));

    if (!mpd_search_commit(conn)) {
        results.append("No Results Found");
        mpd_connection_free(conn);
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
    mpd_connection_free(conn);
    return results;
}

QStringList MpdHandler::playlist()
{
    QStringList list;
    mpd_song *song;
    mpd_connection *conn = mpd_connection_new(mpdhost,mpdport,mpdtimeout_ms);
    if (!mpd_send_list_queue_meta(conn))
        return list;
    while ((song = mpd_recv_song(conn)) != NULL ) {
        list.append(mpd_song_get_uri(song));
    }
    mpd_connection_free(conn);
    return list;
}

void MpdHandler::clear()
{
    mpd_connection *conn = mpd_connection_new(mpdhost,mpdport,mpdtimeout_ms);
    mpd_run_clear(conn);
    mpd_connection_free(conn);
}

void MpdHandler::addSong(QString song)
{
    mpd_connection *conn = mpd_connection_new(mpdhost,mpdport,mpdtimeout_ms);
    mpd_send_add(conn, song.toStdString().c_str());
    mpd_connection_free(conn);
}

void MpdHandler::play()
{
    mpd_connection *conn = mpd_connection_new(mpdhost,mpdport,mpdtimeout_ms);
    mpd_status *status = mpd_run_status(conn);
    if (mpd_status_get_state(status) == MPD_STATE_PLAY) {
        mpd_send_pause(conn,true);
    } else {
        mpd_run_play(conn);
    }
    mpd_connection_free(conn);
}

void MpdHandler::play(int i)
{
    mpd_connection *conn = mpd_connection_new(mpdhost,mpdport,mpdtimeout_ms);
    mpd_run_play_pos(conn, i);
    mpd_connection_free(conn);
}
