#include "lplaylists.h"

LPlaylist_No *novo_no_lplaylist(char *nome_playlist, Playlist *playlist) {
    LPlaylist_No *novo_no = (LPlaylist_No*)malloc(sizeof(LPlaylist_No));

    if (!novo_no)
        return NULL;
    
    static int gerador_id = 0;
    novo_no->id = gerador_id++;
    novo_no->nome[0] = 0;
    if (nome_playlist)
        strcpy(novo_no->nome, nome_playlist);
    novo_no->musicas = playlist;
    novo_no->prox = NULL;

    return novo_no;
}

Lista_Playlists *nova_lista_playlists(void) {
    return novo_no_lplaylist(NULL, NULL);
}

LPlaylist_No *adicionar_playlist(Lista_Playlists *lista_playlists, char *nome_playlist, Playlist *playlist) {
    if (!lista_playlists)
        return NULL;
    if (!playlist)
        return NULL;
    
    LPlaylist_No *no = lista_playlists;

    while (no->prox)
        no = no->prox;
    no->prox = novo_no_lplaylist(nome_playlist, playlist);

    return no->prox;
}

int remover_playlist(Lista_Playlists *lista_playlists, Playlist *playlist) {
    if (!lista_playlists)
        return -1;
    if (!playlist)
        return 1;
    
    LPlaylist_No *no = lista_playlists;
    LPlaylist_No *a_remover = NULL;

    while (no && no->prox->musicas != playlist)
        no = no->prox;
    if (!no)
        return 2;
    
    a_remover = no->prox;
    no->prox = a_remover->prox;
    apagar_no_lplaylist(a_remover);

    return 0;
}

int remover_playlist_id(Lista_Playlists *lista_playlists, int id_playlist) {
    Playlist *playlist = encontrar_playlist(lista_playlists, id_playlist);

    return remover_playlist(lista_playlists, playlist);
}

Playlist *encontrar_playlist(Lista_Playlists *lista_playlists, int id) {
    if (!lista_playlists)
        return NULL;
    if (id <= 0)
        return NULL;

    LPlaylist_No *no = lista_playlists->prox;

    while (no && no->id != id)
        no = no->prox;
    if (!no)
        return NULL;
    
    return no->musicas;
}

int apagar_no_lplaylist(LPlaylist_No *no_lplaylist) {
    if (!no_lplaylist)
        return 1;
    
    apagar_playlist(no_lplaylist->musicas);
    free(no_lplaylist);

    return 0;
}

int apagar_lista_playlists(Lista_Playlists *lista_playlists) {
    if (!lista_playlists)
        return 1;

    LPlaylist_No *prox = lista_playlists->prox;

    while (lista_playlists) {
        apagar_no_lplaylist(lista_playlists);
        lista_playlists = prox;
        if (lista_playlists)
            prox = lista_playlists->prox;
    }

    return 0;
}
