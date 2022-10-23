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

int remover_musica(Lista_Musicas *musicas, Musica *musica) {
    if (!musicas)
        return -1;
    if (!musica)
        return 1;

    Musica_No *no = musicas;
    Musica_No *a_remover = NULL;

    while (no->prox && compara_musica(no->prox->musica, musica))
        no = no->prox;
    if (!no->prox)
        return 2;
    a_remover = no->prox;
    no = a_remover->prox;
    apagar_no_musica(a_remover);

    return 0;
}

int remover_musica_id(Lista_Musicas *musicas, int id_musica) {
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

int maior_id_musica(Lista_Musicas *musicas) {
    if (!musicas)
        return -1;
    if (!musicas->prox)
        return 0;

    Musica_No *no = musicas->prox;
    int maior_id = no->musica->id;
    no = no->prox;

    while (no) {
        if (no->musica->id > maior_id)
            maior_id = no->musica->id;
        no = no->prox;
    }
    
    return maior_id;
}

int encontrar_musica_artista(Lista_Musicas *musicas, 
                                        int id_artista, 
                                        Lista_Musicas *aux_musicas_artista) {
    if (!musicas)
        return -1;
    if (id_artista <= 0)
        return -2;
    if (!aux_musicas_artista)
        return -3;

    int numero_musicas = 0;
    Musica_No *no = musicas->prox;

    while (no) {
        if (no->musica->id_artista == id_artista) {
            adicionar_musica(aux_musicas_artista, no->musica);
            numero_musicas++;
        }
        no = no->prox;
    }

    return numero_musicas;
}

int apagar_no_musica(Musica_No *no_musica) {
    if (!no_musica)
        return 1;
    
    apagar_musica(no_musica->musica);
    free(no_musica);

    return 0;
}

int apagar_lista_musicas(Lista_Musicas *musicas) {
    if (!musicas)
        return 1;

    Musica_No *prox = musicas->prox;

    while (musicas) {
        apagar_no_musica(musicas);
        musicas = prox;
        if (musicas)
            prox = musicas->prox;
    }

    return 0;
}
