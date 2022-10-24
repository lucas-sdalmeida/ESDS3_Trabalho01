#ifndef _UTILIDADES_H
#define _UTILIDADES_H

#include <stdio.h>
#include <string.h>
#include "../tdas/playlist.h"
#include "../tdas/int_queue.h"

int e_letra(char digito);

int cortar_espacos(char *string, char opcao);

int validar_nome(char *nome);

int formatar_nome(char *nome);

int formatar_hora(int tempo_em_segundos, char *destino);

int ler_seq_int(char *origem, Int_Queue *queue);

int shuffle(Playlist *playlist);

#endif
