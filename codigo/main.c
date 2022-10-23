/*
Lucas Silva de Almeida

Trabalho Pratico 01 de ESDS3

Descricao:
    1. O programa deve manter um cadastro de uma coleção de músicas e artistas 
       em listas encadeadas.

    2. Deve haver uma função que cadastra novos artistas e os insere na lista 
       encadeada.

    3. Deve haver uma função que cadastra novas músicas e as insere na lista en-
       cadeada.

    4. Deve haver uma função que imprime todas as músicas com todos seus dados, 
       incluindo o nome do artista. O formato para a impressão da duração deve 
       converter segundos para o formato horas, minutos e segundos: HH:MM:SS.

    5. Deve haver uma função que imprime todos os artistas.

    6. Deve haver uma função que imprime todas as músicas de um artista

    7. Deve haver uma função para a criação de playlists em que o usuário indica 
       pelo teclado de uma string contendo os ids das músicas ex: “1 5 10 13 8 9
       15”, na forma de listas circulares de músicas.

    8. As playlists são cadastradas em uma lista simplesmente encadeada
    
    9. Deve haver uma função shuffle que altera aleatoriamente a ordem das músi-
       cas dentro de uma playlist.

    10. Deve haver uma função que imprime uma playlist.

    11. Deve haver uma função que remove as músicas da lista encadeada e de to-
    das as playlists e em que participa.
    
    12. Deve haver uma função que apaga artistas e todas as suas músicas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../tdas/musica.h"
#include "../tdas/artista.h"
#include "../tdas/lista_musicas.h"
#include "../tdas/lista_artistas.h"
#include "../tdas/playlist.h"
#include "../tdas/lplaylists.h"
#include "../util/menus.h"
#include "../util/utilidades.h"

int main(void) {
   Lista_Musicas *musicas = nova_lista_musicas();
   Lista_Artistas *artistas = nova_lista_artistas();
   Lista_Playlists *lista_playlists = nova_lista_playlists();

   /*int opcao = menu_opcoes("Menu Principal", "\t>>> ", 11, "Cadastrar Artista",
                  "Cadastrar Musica",
                  "Exibir Dados de Artista",
                  "Exibir Musica",
                  "Exibir Musicas de Artista",
                  "Criar Playlist",
                  "Exibir Musicas de Playlist",
                  "Apagar Musica",
                  "Apagar Artista",
                  "Apagar Playlist",
                  "Sair");
   printf("%d\n", opcao);*/

   apagar_lista_musicas(musicas);
   apagar_lista_artistas(artistas);
   apagar_lista_playlists(lista_playlists);

   getchar();

   return 0;
}       
