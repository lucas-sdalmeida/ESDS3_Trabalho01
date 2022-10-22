#ifndef _UTILIDADES_H
#define _UTILIDADES_H

#include "../tdas/playlist.h"

int formatar_hora(int tempo_em_segundos, char *destino);

int ler_vetor_int(char *origem, int tam_vetor, int *destino);

int shuffle(Playlist *playlist);

#endif