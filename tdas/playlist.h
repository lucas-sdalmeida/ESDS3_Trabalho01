#ifndef _PLAYLIST_H
#define _PLAYLIST_H

#include "musica.h"
#include <stdlib.h>

typedef struct playlist_no {
    Musica *musica;
    struct playlist_no *prox;
} Playlist_No, Playlist;

Playlist_No *novo_no_playlist(Musica *musica);

Playlist *nova_playlist(void);

Playlist_No *adicionar_musica_playlist(Playlist *playlist, Musica *musica);

int remover_musica_playlist(Playlist *playlist, Musica *musica);

int remover_musica_id_playlist(Playlist *playlist, int id_musica);

Musica *encontrar_musica_playlist(Playlist *playlist, int id);

int apagar_no_playlist(Playlist_No *no_playlist);

int compara_playlists(Playlist *playlist1, Playlist *playlist2);

int apagar_playlist(Playlist *playlist);

#endif