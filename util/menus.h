#ifndef _MENUS_H
#define _MENUS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include "utilidades.h"
#include "../tdas/musica.h"
#include "../tdas/artista.h"
#include "../tdas/lista_musicas.h"
#include "../tdas/lista_artistas.h"
#include "../tdas/playlist.h"
#include "../tdas/lplaylists.h"
#include "../tdas/int_queue.h"

#define BORDA_PRINCIPAL "=\0"
#define BORDA_SECUNDARIA "-\0"
#define BORDA_TERCIARIA "-\0"
#define BORDA_ERRO "__/\0"
#define COMPRIMENTO_BORDA_PRINCIPAL 60
#define COMPRIMENTO_BORDA_SECUNDARIA 60
#define COMPRIMENTO_BORDA_TERCIARIA 30
#define COMPRIMENTO_BORDA_ERRO 60
#define TAMANHO_AUX_OPCAO 10
#define TAMANHO_SEQ_IDS_MUSICA 50

void linha(char *padrao, int comprimento);

void centralizar(char *texto, int espaco);

void msg_erro(char *msg);

void mensagem(char *msg);

int menu_opcoes(char *titulo, char *msg_leitura, int num_opcoes,...);

int ler_opcao(char *msg, int num_opcoes);

int ler_confirmacao(char *msg, char char_confirma, char char_rejeita);

int ler_nome(char *msg, char *nome);

int ler_genero_musica(char *msg, char *genero);

int ler_inteiro(char *msg, int min, int max);

int ler_sequencia_ids(char *msg, Int_Queue *ids);

int ler_sequencia_musicas(char *msg, Lista_Musicas *musicas, Lista_Musicas *destino, 
                            Lista_Artistas *artistas);

int cadastrar_artista(Lista_Artistas *artistas);

int cadastrar_musica(Lista_Musicas *musicas, Lista_Artistas *artistas);

int exibir_musica(Lista_Artistas *artistas, Musica *musica, int fechar_borda);

int exibir_musicas(char *titulo_menu, Lista_Artistas *artistas, Lista_Musicas *musicas);

Musica *selecionar_musica(Lista_Artistas *artistas, Lista_Musicas *musicas, char *msg);

int exibir_artista(Artista *artista, int fechar_borda);

int exibir_artistas(Lista_Artistas *artistas);

int exibir_musicas_artista(Lista_Musicas *musicas, Lista_Artistas *artistas);

Artista *selecionar_artista(Lista_Artistas *artistas, char *msg);

int criar_playlist(Lista_Playlists *lista_playlists, Lista_Musicas *musicas, 
                    Lista_Artistas *artistas);

int exibir_playlist(LPlaylist_No *playlist);

int exibir_playlists(Lista_Playlists *lista_playlists);

int exibir_musicas_playlist(Lista_Playlists *lista_playlists, Lista_Artistas *artistas);

Playlist *selecionar_playlist(Lista_Playlists *lista_playlists);

int esquecer_musica(Lista_Musicas *musicas, Lista_Artistas *artistas, Lista_Playlists *lista_playlists);

int esquecer_musica_selecionada(Lista_Musicas *musicas, Lista_Playlists *lista_playlists,
                                Musica *musica);

int esquecer_artista(Lista_Artistas *artistas, Lista_Musicas *musicas,
                        Lista_Playlists *lista_playlists);

#endif