#include "lista_artistas.h"

Artista_No *novo_no_artista(Artista *artista) {
    Artista_No* novo_no = (Artista_No*)malloc(sizeof(Artista_No));

    if (!novo_no)
        return NULL;
    
    novo_no->artista = artista;
    novo_no->prox = NULL;

    return novo_no;
}

Lista_Artistas *nova_lista_artistas(void) {
    return novo_no_artista(NULL);
}

Artista_No *adicionar_artista(Lista_Artistas *artistas, Artista *artista) {
    if (!artistas)
        return NULL;
    if (!artista)
        return NULL;

    Artista_No *no = artistas;

    while (no->prox)
        no = no->prox;
    no->prox = novo_no_artista(artista);

    return no->prox;
}

int remover_artista(Lista_Artistas *artistas, Artista *artista) {
    if (!artistas)
        return -1;
    if (!artista)
        return 1;
    
    Artista_No *no = artistas;
    Artista_No *a_remover = NULL;

    while (no->prox && compara_artista(no->prox->artista, artista))
        no = no->prox;
    if (!no)
        return 2;
    a_remover = no->prox;
    no->prox = a_remover->prox;
    apagar_no_artista(a_remover);
    return 0;
}

int remover_artista_id(Lista_Artistas *artistas, int id_artista) {
    Artista *artista = encontrar_artista(artistas, id_artista);

    return remover_artista(artistas, artista);
}

Artista *encontrar_artista(Lista_Artistas *artistas, int id) {
    if (!artistas)
        return NULL;
    if (id <= 0)
        return NULL;

    Artista_No *no = artistas->prox;

    while (no && no->artista->id != id)
        no = no->prox;
    if (!no)
        return NULL;
    
    return no->artista;
}

int apagar_no_artista(Artista_No *no_artista) {
    if (!no_artista)
        return 1;
    
    apagar_artista(no_artista->artista);
    free(no_artista);
}

int apagar_lista_artistas(Lista_Artistas *artistas) {
    if (!artistas)
        return 1;

    Artista_No *prox = artistas->prox;

    while (artistas) {
        apagar_no_artista(artistas);
        artistas = prox;
        if (artistas)
            prox = artistas->prox;
    }

    return 0;
}
