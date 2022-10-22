#include "artista.h"

Artista *novo_artista(char *nome, char *genero) {
    if (!nome || strlen(nome) == 0)
        return NULL;
    if (!genero || strlen(genero) == 0)
        return NULL;
    
    static int gerador_id = 0;
    Artista *artista_novo = (Artista*)malloc(sizeof(Artista));

    if (!artista_novo)
        return NULL;

    artista_novo->id = gerador_id++;
    strcpy(artista_novo->nome, nome);
    strcpy(artista_novo->genero, genero);

    return artista_novo;
}

int compara_artista(Artista *artista1, Artista *artista2) {
    if (!artista1)
        return -2;
    if (!artista2)
        return -3;
    if (artista1->id > artista2->id)
        return 1;
    if (artista1->id < artista2->id)
        return -1;
    return 0;
}

int apagar_artista(Artista *artista) {
    if (!artista)
        return 1;

    free(artista);
    return 0;
}
