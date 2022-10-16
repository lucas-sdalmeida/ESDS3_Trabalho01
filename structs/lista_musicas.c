#include "lista_musicas.h"

Musica_No *novo_no_musica(Musica *musica) {
    Musica_No *novo_no = (Musica_No*)malloc(sizeof(Musica_No));

    if (!novo_no)
        return NULL;
    
    novo_no->musica = musica;
    novo_no->prox = NULL;

    return novo_no;
}

Lista_Musicas *nova_lista_musicas(void) {
    return novo_no_musica(NULL);
}

Musica_No *adicionar_musica(Lista_Musicas *musicas, Musica *musica) {
    if (!musicas)
        return NULL;
    if (!musica)
        return NULL;

    Musica_No *no = musicas;
    
    while (no->prox)
        no = no->prox;
    no->prox = novo_no_musica(musica);

    return no->prox;
}

Musica_No *remover_musica(Lista_Musicas *musicas, Musica *musica) {
    if (!musicas)
        return -1;
    if (!musica)
        return -1;

    Musica_No *no = musicas;
    Musica_No *a_remover = NULL;

    while (no->prox && compara_musica(no->prox->musica, musica))
        no = no->prox;
    if (!no->prox)
        return NULL;
    a_remover = no->prox;
    no = a_remover->prox;
    apagar_no_musica(a_remover);

    return a_remover;
}

Musica_No *remover_musica_id(Lista_Musicas *musicas, int id_musica) {
    Musica *musica = encontrar_musica(musicas, id_musica);

    return remover_musica(musicas, musica);
}

Musica *encontrar_musica(Lista_Musicas *musicas, int id) {
    if (!musicas) 
        return NULL;
    if (id <= 0)
        return NULL;

    Musica_No *no = musicas->prox;

    while (no && no->musica->id != id)
        no = no->prox;
    if (!no)
        return NULL;

    return no->musica;
}

Lista_Musicas *encontrar_musica_artista(Lista_Musicas *musicas, 
                                        int id_artista) {
    if (!musicas)
        return NULL;
    if (id_artista <= 0)
        return NULL;

    Lista_Musicas *musicas_artista = nova_lista_musicas();
    Musica_No *no = musicas->prox;

    if (!musicas_artista)
        return NULL;
    while (no) {
        if (no->musica->id == id_artista)
            adicionar_musica(musicas_artista, no->musica);
        no = no->prox;
    }
    if (!musicas_artista->prox)
        return NULL;
    
    return musicas_artista;
}

Musica_No *apagar_no_musica(Musica_No *no_musica) {
    if (!no_musica)
        return NULL;
    
    apagar_musica(no_musica->musica);
    free(no_musica);

    return no_musica;
}

Lista_Musicas *apagar_lista_musicas(Lista_Musicas *musicas) {
    Musica_No *prox = musicas->prox;

    while (musicas) {
        apagar_no_musica(musicas);
        musicas = prox;
        if (musicas)
            prox = musicas->prox;
    }

    return musicas;
}
