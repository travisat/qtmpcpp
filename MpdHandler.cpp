/***************************************************************************
 *   Copyright (C) 2010 by Travis Thompson                                 *
 *   travisat@gmail.com			                                           *
 ***************************************************************************/
#include "MpdHandler.h"

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
