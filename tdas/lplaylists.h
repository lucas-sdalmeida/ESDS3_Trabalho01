#ifndef _LPLAYLISTS_H
#define _LPLAYLISTS_H

#include "playlist.h"
#include <stdlib.h>
#include <string.h>

#define TAMANHO_NOME_LPLAYLIST 200

typedef struct lplaylist_no {
    int id;
    char nome[TAMANHO_NOME_LPLAYLIST];
    Playlist *musicas;
    struct lplaylist_no *prox;
} LPlaylist_No, Lista_Playlists;

LPlaylist_No *novo_no_lplaylist(char *nome_playlist, Playlist *playlist);

Lista_Playlists *nova_lista_playlists(void);

LPlaylist_No *adicionar_playlist(Lista_Playlists *lista_playlists, char *nome_playlist, Playlist *playlist);

int remover_playlist(Lista_Playlists *lista_playlists, Playlist *playlist);

int remover_playlist_id(Lista_Playlists *lista_playlists, int id_playlist);

LPlaylist_No *encontrar_playlist(Lista_Playlists *lista_playlists, int id);

int maior_id_lplaylist(Lista_Playlists *lista_playlists);

int apagar_no_lplaylist(LPlaylist_No *no_lplaylist);

int apagar_lista_playlists(Lista_Playlists *lista_playlists);

#endif
