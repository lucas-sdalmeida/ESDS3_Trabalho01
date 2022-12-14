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

int main(void) {
   Lista_Musicas *musicas = nova_lista_musicas();
   Lista_Artistas *artistas = nova_lista_artistas();
   Lista_Playlists *lista_playlists = nova_lista_playlists();
   int opcao;

   // Para facilitar os testes
   
   Artista *ptart = adicionar_artista(artistas, novo_artista("AC DC", "METAL"))->artista;
   adicionar_musica(musicas, nova_musica("Black In Black", ptart, 255));
   adicionar_musica(musicas, nova_musica("Highway To Hell", ptart, 208));
   adicionar_musica(musicas, nova_musica("TNT", ptart, 214));

   ptart = adicionar_artista(artistas, novo_artista("Metallica", "METAL"))->artista;
   adicionar_musica(musicas, nova_musica("Master Of Puppets", ptart, 515));

   ptart = adicionar_artista(artistas, novo_artista("Linkin Park", "Rock"))->artista;
   adicionar_musica(musicas, nova_musica("Numb", ptart, 185));

   do {
      opcao = menu_opcoes("Menu Principal", "\t>>> ", 11, 
                  "Cadastrar Artista",
                  "Cadastrar Musica",
                  "Exibir Dados de Artistas",
                  "Exibir Musicas",
                  "Exibir Musicas de Artista",
                  "Criar Playlist",
                  "Exibir Musicas de Playlist",
                  "Apagar Musica",
                  "Apagar Artista",
                  "Embaralhar Playlist",
                  "Sair");

      switch (opcao) {
         case 1:
            cadastrar_artista(artistas);
            break;
         case 2:
            cadastrar_musica(musicas, artistas);
            break;
         case 3:
            exibir_artistas(artistas);
            break;
         case 4:
            exibir_musicas("Musicas Cadastradas", artistas, musicas);
            break;
         case 5:
            exibir_musicas_artista(musicas, artistas);
            break;
         case 6:
            criar_playlist(lista_playlists, musicas, artistas);
            break;
         case 7:
            exibir_musicas_playlist(lista_playlists, artistas);
            break;
         case 8:
            esquecer_musica(musicas, artistas, lista_playlists);
            break;
         case 9:
            esquecer_artista(artistas, musicas, lista_playlists);
            break;
         case 10:
            putchar(10);
            mensagem("Ainda Nao Implementada!");
            putchar(10);
            break;
         default:
            putchar(10);
            mensagem("Encerrando...");
      }
   } while (opcao < 11);

   apagar_lista_playlists(lista_playlists);
   apagar_lista_artistas(artistas, 1);
   apagar_lista_musicas(musicas, 1);

   getchar();

   return 0;
}
