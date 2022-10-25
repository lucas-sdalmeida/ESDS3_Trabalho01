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

Artista_No *adicionar_artista(Lista_Artistas *artistas, Artista *artista);

int remover_artista(Lista_Artistas *artistas, Artista *artista);

int remover_artista_id(Lista_Artistas *artistas, int id_artista);

int quantidade_artistas(Lista_Artistas *artistas);

Artista *encontrar_artista(Lista_Artistas *artistas, int id);

int maior_id_artista(Lista_Artistas *artistas);

int apagar_no_artista(Artista_No *no_artista, int remover_artista);

int apagar_lista_artistas(Lista_Artistas *artistas, int remover_artista);

#endif