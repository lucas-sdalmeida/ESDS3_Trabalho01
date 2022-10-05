#ifndef _PLAYLIST_H
#define _PLAYLIST_H

#include "musica.h";

typedef struct playlist_no {
    Musica *musica;
    struct playlist_no *prox;
} Playlist_No, Playlist;

Playlist_No *novo_no_playlist(Musica *musica);

Playlist *nova_playlist(void);

Playlist_No *adicionar_musica_playlist(Musica *musica);

Playlist_No *remover_musica_playlist(Musica *musica);

Playlist_No *remover_musica_id_playlist(int id_musica);

Playlist_No *encontrar_musica_playlist(int id);

Playlist_No *apagar_no_playlist(Playlist_No *no_playlist);

int compara_playlists(Playlist *playlist1, Playlist *playlist2);

Playlist *apagar_playlist(Playlist *playlist);

#endif