#include "musica.h"

Musica *nova_musica(char *titulo, Artista *artista, int duracao_em_segundos) {
    if (!titulo || strlen(titulo) == 0)
        return NULL;
    if (!artista)
        return NULL;
    if (duracao_em_segundos <= 0)
        return NULL;

    static int gerador_id = 0;
    Musica *musica_nova = (Musica*)malloc(sizeof(Musica));

    if (!musica_nova)
        return NULL;
    
    musica_nova->id = ++gerador_id;
    strcpy(musica_nova->titulo, titulo);
    musica_nova->id_artista = artista->id;
    musica_nova->duracao_em_segundos = duracao_em_segundos;
    return musica_nova;
}

int compara_musica(Musica *musica1, Musica *musica2) {
    if (!musica1)
        return -2;
    if (!musica2)
        return -3;
    if (musica1->id > musica2->id)
        return 1;
    if (musica1->id < musica2->id)
        return -2;
    return 0;
}

Musica *apagar_musica(Musica *musica) {
    free(musica);
    return musica;
}