#ifndef _LISTA_ARTISTAS_H
#define _LISTA_ARTISTAS_H

#include "artista.h"

typedef struct artista_no {
    Artista *artista;
    struct artista_no *prox;
} Artista_No, Lista_Artistas;

Artista_No *novo_no_artista(Artista artista);

Lista_Artistas *nova_lista_artistas(void);

Artista_No *adicionar_artista(Artista *artista);

Artista_No *remover_artista(Artista *artista);

Artista_No *remover_artista_id(int id_artista);

Artista_No *encontrar_artista(int id);

Artista_No *apagar_no_artista(Artista_No *no_artista);

Lista_Artistas *apagar_lista_artistas(Lista_Artistas *artistas);

#endif