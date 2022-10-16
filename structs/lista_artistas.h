#ifndef _LISTA_ARTISTAS_H
#define _LISTA_ARTISTAS_H

#include "artista.h"
#include <stdlib.h>

typedef struct artista_no {
    Artista *artista;
    struct artista_no *prox;
} Artista_No, Lista_Artistas;

Artista_No *novo_no_artista(Artista *artista);

Lista_Artistas *nova_lista_artistas(void);

Artista_No *adicionar_artista(Lista_Artista *artistas, Artista *artista);

void remover_artista(Lista_Artistas *artistas, Artista *artista);

void remover_artista_id(Lista_Artistas *artistas, int id_artista);

Artista_No *encontrar_artista(Lista_Artistas *artistas, int id);

void *apagar_no_artista(Artista_No *no_artista);

void *apagar_lista_artistas(Lista_Artistas *artistas);

#endif