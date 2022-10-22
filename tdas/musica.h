#ifndef _MUSICA_H
#define _MUSICA_H 

#include "artista.h"
#include <string.h>
#include <stdlib.h>

#define TAMANHO_TITULO_MUSICA 200

typedef struct musica {
    int id;
    char titulo[TAMANHO_TITULO_MUSICA];
    int id_artista;
    int duracao_em_segundos;
} Musica;

Musica *nova_musica(char *titulo, Artista *artista, int duracao_em_segundos);

int compara_musica(Musica *musica1, Musica *musica2);

int apagar_musica(Musica *musica);

#endif