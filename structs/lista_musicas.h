#ifndef _LISTA_MUSICAS_H
#define _LISTA_MUSICAS_H

#include "musica.h"
#include "artista.h"

typedef struct musica_no {
    Musica *musica;
    struct musica_no *prox;
} Musica_No, Lista_Musicas;

Musica_No *novo_no_musica(Musica *musica);

Lista_Musicas *nova_lista_musicas(void);

Musica_No *adicionar_musica(Musica *musica);

Musica_No *remover_musica(Musica *musica);

Musica_No *remover_musica_id(int id_musica);

Musica *encontrar_musica(int id);

Lista_Musicas *encontrar_musica_artista(int id_artista);

Musica_No *apagar_no_musica(Musica_No *no_musica);

Musica_No *apagar_lista_musicas(Lista_Musicas *musicas);

#endif