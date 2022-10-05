#ifndef _LPLAYLISTS_H
#define _LPLAYLISTS_H

#include "playlist.h";

#define TAMANHO_NOME_LPLAYLIST 200

typedef struct lplaylist_no {
    int id;
    char nome[TAMANHO_NOME_LPLAYLIST];
    Playlist *musicas;
    struct lplaylist_no *prox;
} LPlaylist_No, Lista_Playlists;

LPlaylist_No *novo_no_lplaylist(Playlist *playlist);

Lista_Playlists *nova_lista_playlists(void);

LPlaylist_No *adicionar_playlist(Playlist *playlist);

LPlaylist_No *remover_playlist(Playlist *playlist);

LPlaylist_No *remover_playlist_id(int id_playlist);

Playlist *encontrar_playlist(int id);

LPLaylist_No *apagar_no_lplaylist(LPlaylist_No *no_lplaylist);

Lista_Playlists *apagar_lista_playlists(Lista_Playlists *lplaylist);

#endif