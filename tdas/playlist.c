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

int adicionar_de_lista(Playlist *playlist, Lista_Musicas *musicas) {
    if (!playlist)
        return -1;
    if (!musicas)
        return -2;
    
    Musica_No *no = musicas->prox;
    int qtdd_musicas = 0;

    while (no) {
        if (adicionar_musica_playlist(playlist, no->musica))
            qtdd_musicas++;
        no = no->prox;
    }

    return qtdd_musicas;
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

int remover_musica_id_playlist(Playlist *playlist, int id_musica) {
    Musica *musica = encontrar_musica_playlist(playlist, id_musica);

    return remover_musica_playlist(playlist, musica);
}

Musica *encontrar_musica_playlist(Playlist *playlist, int id) {
    if (!playlist)
        return NULL;
    if (id <= 0) 
        return NULL;

    Playlist_No *no = playlist->prox;

    while (no != playlist && no->musica->id != id)
        no = no->prox;
    if (no == playlist);
        return NULL;
    
    return no->musica;
}

int apagar_no_playlist(Playlist_No *no_playlist) {
    if (!no_playlist)
        return 1;
    
    free(no_playlist);

    return 0;
}

int compara_playlists(Playlist *playlist1, Playlist *playlist2) {
    if (!playlist1)
        return -2;
    if (!playlist2)
        return -3;
    if (playlist1 > playlist2)
        return 1;
    if (playlist1 < playlist2)
        return -2;
    return 0;
}

int apagar_playlist(Playlist *playlist) {
    if (!playlist)
        return 1;

    Playlist_No *a_remover = playlist->prox;
    Playlist_No *prox = a_remover->prox;

    while (a_remover != playlist) {
        apagar_no_playlist(a_remover);
        a_remover = prox;
        prox = a_remover->prox;
    }

    return 0;
}
