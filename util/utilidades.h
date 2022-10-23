#ifndef _UTILIDADES_H
#define _UTILIDADES_H

#include <string.h>
#include "../tdas/playlist.h"

int e_letra(char digito);

int cortar_espacos(char *string, char opcao);

int validar_nome(char *nome);

int formatar_nome(char *nome);

int formatar_hora(int tempo_em_segundos, char *destino);

int ler_vetor_int(char *origem, int tam_vetor, int *destino);

int shuffle(Playlist *playlist);

#endif
