#ifndef _LISTA_MUSICAS_H
#define _LISTA_MUSICAS_H

#include <stdlib.h>
#include "musica.h"
#include "artista.h"

typedef struct musica_no {
    Musica *musica;
    struct musica_no *prox;
} Musica_No, Lista_Musicas;

Musica_No *novo_no_musica(Musica *musica);

Lista_Musicas *nova_lista_musicas(void);

Musica_No *adicionar_musica(Lista_Musicas *musicas, Musica *musica);

int remover_musica(Lista_Musicas *musicas, Musica *musica);

int remover_musica_id(Lista_Musicas *musicas, int id_musica);

Musica *encontrar_musica(Lista_Musicas *musicas, int id);

int encontrar_musica_artista(Lista_Musicas *musicas, int id_artista, Lista_Musicas *aux_musicas_artista);

int apagar_no_musica(Musica_No *no_musica);

int apagar_lista_musicas(Lista_Musicas *musicas);

#endif