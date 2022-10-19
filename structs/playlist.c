#include "playlist.h"

Playlist_No *novo_no_playlist(Musica *musica) {
    Playlist_No *novo_no = (Playlist_No*)malloc(sizeof(Playlist_No));

    if (!novo_no)
        return NULL;
    
    novo_no->musica = musica;
    novo_no->prox = novo_no;
}

Playlist *nova_playlist(void) {
    return novo_no_playlist(NULL);
}

Playlist_No *adicionar_musica_playlist(Playlist *playlist, Musica *musica) {
    if (!playlist)
        return NULL;
    if (!musica)
        return NULL;

    Playlist_No *no = playlist;

    while (no->prox != playlist)
        no = no->prox;
    no->prox = novo_no_playlist(musica);
    no = no->prox;
    no->prox = playlist;

    return no;
}

int remover_musica_playlist(Playlist *playlist, Musica *musica) {
    if (!playlist)
        return -1;
    if (!musica)
        return 1;
    
    Playlist_No *no = playlist;
    Playlist_No *a_remover;

    while (no->prox != playlist && no->prox->musica != musica)
        no = no->prox;
    if (no->prox == playlist)
        return 2;
    a_remover = no->prox;
    no->prox = a_remover->prox;
    apagar_no_playlist(a_remover);

    return 0;
}

int remover_musica_id_playlist(Playlist *playlist, int id_musica);

Musica *encontrar_musica_playlist(Playlist *playlist, int id);

int apagar_no_playlist(Playlist_No *no_playlist);

int compara_playlists(Playlist *playlist1, Playlist *playlist2);

int apagar_playlist(Playlist *playlist);
