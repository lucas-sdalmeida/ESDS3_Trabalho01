#ifndef _ARTISTA_H
#define _ARTISTA_H

#define TAMANHO_NOME_ARTISA 200
#define TAMANHO_GENERO_ARTISTA 200

typedef struct artista {
    int id;
    char nome[TAMANHO_NOME_ARTISA];
    char genero[TAMANHO_GENERO_ARTISTA]
} Artista;

Artista *novo_artista(char *nome, char *titulo);

int compara_artista(Artista *artista1, Artista *artista2);

Artista *apagar_artista(Artista *artista);

#endif