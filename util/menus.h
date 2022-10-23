#ifndef _MENUS_H
#define _MENUS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "utilidades.h"
#include "../tdas/musica.h"
#include "../tdas/artista.h"
#include "../tdas/lista_musicas.h"
#include "../tdas/lista_artistas.h"
#include "../tdas/playlist.h"
#include "../tdas/lplaylists.h"

#define BORDA_PRINCIPAL "=\0"
#define BORDA_SECUNDARIA "-\0"
#define BORDA_TERCIARIA "-\0"
#define BORDA_ERRO "__/\0"
#define COMPRIMENTO_BORDA_PRINCIPAL 60
#define COMPRIMENTO_BORDA_SECUNDARIA 60
#define COMPRIMENTO_BORDA_TERCIARIA 30
#define COMPRIMENTO_BORDA_ERRO 60

void linha(char *padrao, int comprimento);

void centralizar(char *texto, int espaco);

void msg_erro(char *msg);

int menu_opcoes(char *titulo, char *msg_leitura, int num_opcoes,...);

int ler_opcao(char *msg, int num_opcoes);

int ler_opcao_de(char *msg, int num_possiveis_valores,...);

int ler_nome(char *msg, char *nome);

int cadastrar_artista(Lista_Artistas *artistas);

int cadastrar_musica(Lista_Musicas *musicas);

int exibir_musica(Musica musica, int fechar_borda);

int exibir_musicas(char *titulo_menu, Lista_Musicas *musicas);

Musica *selecionar_musica(Lista_Musicas *musicas);

int exibir_artista(Artista *artista, int fechar_borda);

int exibir_artistas(Lista_Artistas *artistas);

Artista *selecionar_artista(Lista_Artistas *artistas);

int criar_playlist(Lista_Playlists *lista_playlists);

int exibir_musicas_playlist(Lista_Musicas *musicas);

int esquecer_musica(Lista_Musicas *musicas, Lista_Playlists *lista_playlists);

int esquecer_artista(Lista_Artistas *artisas, Lista_Musicas *musicas,
                        Lista_Playlists *lista_playlists);

#endif