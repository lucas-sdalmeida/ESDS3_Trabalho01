#include "menus.h"

void linha(char *padrao, int comprimento) {
    int comprimento_padrao = strlen(padrao);
    char *trecho_linha = (char*)malloc((sizeof(char) * comprimento_padrao) + 1);

    trecho_linha[comprimento_padrao] = 0;
    strcpy(trecho_linha, padrao);

    while (comprimento > 0) {
        if (comprimento_padrao > comprimento)
            trecho_linha[comprimento] = 0;
        printf(trecho_linha);
        comprimento -= comprimento_padrao;
    }
    putchar(10);

    free(trecho_linha);
}

void centralizar(char *texto, int espaco) {
    int comprimento_texto = strlen(texto);
    int num_espacos = (espaco - comprimento_texto) / 2;

    int i = 0;
    for (; i<num_espacos; i++)
        putchar(' ');
    puts(texto);
}

void msg_erro(char *msg) {
    putchar(10);
    linha(BORDA_ERRO, COMPRIMENTO_BORDA_ERRO);
    centralizar("OOOps! Ocorreu um erro!", COMPRIMENTO_BORDA_ERRO);
    if (msg && strlen(msg) > 0)
        centralizar(msg, COMPRIMENTO_BORDA_ERRO);
    linha(BORDA_ERRO, COMPRIMENTO_BORDA_ERRO);
    putchar(10);
}

void mensagem(char *msg) {
    if (!msg || strlen(msg) == 0);
        return;
    linha(BORDA_TERCIARIA, COMPRIMENTO_BORDA_TERCIARIA);
    centralizar(msg, COMPRIMENTO_BORDA_TERCIARIA);
    linha(BORDA_TERCIARIA, COMPRIMENTO_BORDA_TERCIARIA);
}

int menu_opcoes(char *titulo, char *msg_leitura, int num_opcoes,...) {
    if (!titulo)
        return -1;
    if (!msg_leitura)
        return -2;
    if (num_opcoes <= 0)
        return -3;
    
    va_list opcoes;
    int opcao;

    va_start(opcoes, num_opcoes);
    
    putchar(10);
    linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);
    centralizar(titulo, COMPRIMENTO_BORDA_PRINCIPAL);
    linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);

    int i = 0;
    for (; i<num_opcoes; i++) {
        printf("%4d |", i + 1);
        centralizar(va_arg(opcoes, char*), COMPRIMENTO_BORDA_PRINCIPAL - 6);
        if (i < num_opcoes - 1)
            linha(BORDA_SECUNDARIA, COMPRIMENTO_BORDA_SECUNDARIA);
    }
    linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);
    opcao = ler_opcao(msg_leitura, num_opcoes);

    linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);
    putchar(10);

    va_end(opcoes);
    return 0;
}

int ler_opcao(char *msg, int num_opcoes) {
    if (num_opcoes <= 0)
        return -1;
    
    int opcao = 0;

    do {
        linha(BORDA_SECUNDARIA, COMPRIMENTO_BORDA_SECUNDARIA);
        if (msg && strlen(msg) > 0)
            printf(msg);
        scanf("%d", &opcao);
        getchar();
        linha(BORDA_SECUNDARIA, COMPRIMENTO_BORDA_SECUNDARIA);
        if (opcao <= 0 || opcao > num_opcoes)
            msg_erro("A opcao digitada e invalida!");
    } while (num_opcoes < opcao || opcao <= 0);

    return opcao;
}

int ler_confirmacao(char *msg, char char_confirma, char char_rejeita) {
    if (!char_confirma || !char_rejeita)
        return 0;
    if (e_letra(char_confirma) == 2)
        char_confirma += 32;
    if (e_letra(char_rejeita) == 2)
        char_rejeita += 32;
    
    char aux_opcao[TAMANHO_AUX_OPCAO];
    aux_opcao[0] = 0;

    do {
        linha(BORDA_SECUNDARIA, COMPRIMENTO_BORDA_SECUNDARIA);
        if (msg && strlen(msg) > 0)
            printf(msg);
        fgets(aux_opcao, TAMANHO_AUX_OPCAO, stdin);
        cortar_espacos(aux_opcao, 'e');
        linha(BORDA_SECUNDARIA, COMPRIMENTO_BORDA_SECUNDARIA);
        if (e_letra(aux_opcao[0]) > 2)
            aux_opcao[0] += 32;
        if (aux_opcao[0] != char_confirma && aux_opcao[0] != char_rejeita)
            msg_erro("Digite um opcao valida!");
    } while (aux_opcao[0] != char_confirma && aux_opcao[0] != char_rejeita);

    return (aux_opcao[0] == char_confirma) ? 1 : 0;
}

int ler_nome(char *msg, char *nome) {
    if (!nome)
        return -1;
    int nome_valido = 0;

    do {
        linha(BORDA_SECUNDARIA, COMPRIMENTO_BORDA_SECUNDARIA);
        if (msg && strlen(msg) > 0)
            printf(msg);
        fgets(nome, TAMANHO_NOME_ARTISTA, stdin);
        cortar_espacos(nome, 'a');
        linha(BORDA_SECUNDARIA, COMPRIMENTO_BORDA_SECUNDARIA);
        nome_valido = formatar_nome(nome);
        if (!nome_valido)
            msg_erro("Digite um nome valido ou confira e corriga o digitado");
    } while (!nome_valido);

    return 0;
}

int ler_genero_musica(char *msg, char *genero) {
    if (!genero)
        return -1;
    
    int genero_valido = 0;

    do {    
        linha(BORDA_SECUNDARIA, COMPRIMENTO_BORDA_SECUNDARIA);
        if (msg && strlen(msg) > 0)
            printf(msg);
        fgets(genero, TAMANHO_GENERO_ARTISTA, stdin);
        cortar_espacos(genero, 'a');
        genero_valido = formatar_nome(genero);
        if (!genero_valido)
            msg_erro("Digite um genero musical válido!");
        linha(BORDA_SECUNDARIA, COMPRIMENTO_BORDA_SECUNDARIA);
    } while (!genero_valido);

    return 0;
}

int ler_inteiro(char *msg, int min, int max) {
    int inteiro = 0;
    char txt_erro[44];

    while (1) {
        linha(BORDA_SECUNDARIA, COMPRIMENTO_BORDA_SECUNDARIA);
        if (msg && strlen(msg) > 0)
            printf(msg);
        scanf("%d", &inteiro);
        getchar();
        linha(BORDA_SECUNDARIA, COMPRIMENTO_BORDA_SECUNDARIA);
        if (inteiro > max) {
            sprintf(txt_erro, "O valor digitado excede o maximo de %d!", max);
            msg_erro(txt_erro);
            continue;
        }
        if (inteiro < min) {
            sprintf(txt_erro, "O valor digitado nao atinge o minimo de %d!", min);
            msg_erro(txt_erro);
            continue;
        }
        break;
    }

    return inteiro;
}

int ler_sequencia_ids(char *msg, Int_Queue *ids) {
    if (!ids)
        return -1;
    
    int opcao = 0;
    char sequencia[TAMANHO_SEQ_IDS_MUSICA];
    int num_ids = 0;

    do {
        linha(BORDA_SECUNDARIA, COMPRIMENTO_BORDA_SECUNDARIA);
        if (msg && strlen(msg) > 0)
            printf(msg);
        fgets(sequencia, TAMANHO_SEQ_IDS_MUSICA, stdin);
        cortar_espacos(sequencia, 'a');
        linha(BORDA_SECUNDARIA, COMPRIMENTO_BORDA_SECUNDARIA);
        
        num_ids = obter_seq_int(sequencia, ids);
        if (num_ids == 0) {
            msg_erro("Nenhum id lido corretamente!");
            opcao = !ler_confirmacao("Tentar outra sequencia? [S/N] ",
                                        's', 'n');
            continue;
        }
        opcao = ler_confirmacao("Buscar musicas com esses ids? [S/N] ",
                                    's', 'n');
    } while (!opcao);

    return num_ids;
}

int ler_sequencia_musicas(char *msg, Lista_Musicas *musicas, Lista_Musicas *destino, 
                            Lista_Artistas *artistas) {
    if (!musicas)
        return -1;
    if (!destino)
        return -2;
    if (!artistas)
        return -3;

    int opcao = 0;
    int num_musicas = 0;
    Int_Queue *ids_musicas = new_int_queue();

    do {
        num_musicas = ler_sequencia_ids(msg, ids_musicas);

        if (num_musicas == 0) {
            del_int_queue(ids_musicas);
            return 0;
        }

        num_musicas = copiar_musicas(musicas, destino, ids_musicas);

        if (num_musicas == 0) {
            msg_erro("Nao foi possivel encontrar nenhuma musica informada!");
            opcao = !ler_confirmacao("Deseja tentar outra sequencia? [S/N] ",
                                        's', 'n');
            continue;
        }

        exibir_musicas(NULL, artistas, destino);
        opcao = ler_confirmacao("Selecionar essas musicas? [S/N] ", 's', 'n');
        if (!opcao) {
            apagar_lista_musicas(destino->prox, 0);
            destino->prox = NULL;
        }
    } while (!opcao);

    del_int_queue(ids_musicas);
    return num_musicas;
}

int cadastrar_artista(Lista_Artistas *artistas) {
    if (!artistas)
        return -1;
    
    putchar(10);
    linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);

    char nome[TAMANHO_NOME_ARTISTA];
    ler_nome("Digite o nome do artista:\n\t>>> ", nome);
    char genero_musical[TAMANHO_GENERO_ARTISTA];
    ler_genero_musica("Digite o genero musical do artista:\n\t>>> ", 
                        genero_musical);
    Artista *artista = novo_artista(nome, genero_musical);

    linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);
    putchar(10);

    if (!adicionar_artista(artistas, artista)) {
        apagar_artista(artista);
        return -2;
    }

    return 0;
}

int cadastrar_musica(Lista_Musicas *musicas, Lista_Artistas *artistas) {
    if (!musicas)
        return -1;
    if (!artistas)
        return -2;

    Artista *artista_musica = selecionar_artista(artistas, 
                                "Escolha o artista da musica:\n\t>>> ");
    if (!artista_musica) {
        linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);
        putchar(10);
        return 1;
    }
    
    linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);

    char nome_musica[TAMANHO_TITULO_MUSICA];
    ler_nome("Informe o nome da musica:\n\t>>> ", nome_musica);

    int duracao_musica;
    duracao_musica = ler_inteiro("Digite a duracao, em segundos, da musica:\n\t>>> ",
                                    1, pow(2, (sizeof(int) * 8) - 1) - 1);
    Musica *musica = nova_musica(nome_musica, artista_musica, duracao_musica);

    linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);
    putchar(10);

    if (!adicionar_musica(musicas, musica)) {
        apagar_musica(musica);
        return -3;
    }

    return 0;
}

int exibir_musica(Lista_Artistas *artistas, Musica *musica, int fechar_borda) {
    if (!artistas)
        return -1;
    if (!musica)
        return -2;
    
    Artista *artista_musica = encontrar_artista(artistas, musica->id_artista);

    linha(BORDA_SECUNDARIA, COMPRIMENTO_BORDA_SECUNDARIA);

    printf("     |");
    centralizar(musica->titulo, COMPRIMENTO_BORDA_SECUNDARIA - 6);

    printf("%4d | Artista:", musica->id);
    centralizar(artista_musica->nome, COMPRIMENTO_BORDA_SECUNDARIA - 14);

    printf("     | Duracao:");
    char duracao[10];
    formatar_hora(musica->duracao_em_segundos, duracao);
    centralizar(duracao, COMPRIMENTO_BORDA_SECUNDARIA - 15);

    linha(BORDA_SECUNDARIA, COMPRIMENTO_BORDA_SECUNDARIA);

    return 0;
}

int exibir_musicas(char *titulo_menu, Lista_Artistas *artistas, Lista_Musicas *musicas) {
    if (!artistas)
        return -2;
    if (!musicas)
        return -3;

    Musica_No *no = musicas->prox;
    int fechar_borda = 0;

    putchar(10);
    linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);
    if (!no) {
        centralizar("Nenhuma musica foi cadastrada ainda!", 
                    COMPRIMENTO_BORDA_PRINCIPAL);
        linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);
        putchar(10);
        return 1;
    }
    if (titulo_menu && strlen(titulo_menu) > 0) {
        centralizar(titulo_menu, COMPRIMENTO_BORDA_PRINCIPAL);
        linha(BORDA_SECUNDARIA, COMPRIMENTO_BORDA_PRINCIPAL);
    }
    printf("  id |");
    centralizar("Dados da Musica", COMPRIMENTO_BORDA_PRINCIPAL - 6);
    linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);

    while (no) {
        if (!no->prox)
            fechar_borda = 1;
        exibir_musica(artistas, no->musica, fechar_borda);
        no = no->prox;
    }

    linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);
    putchar(10);

    return 0;
}

Musica *selecionar_musica(Lista_Artistas *artistas, Lista_Musicas *musicas, char *msg) {
    if (!artistas)
        return NULL;
    if (!musicas)
        return NULL;

    if (exibir_musicas("Musicas Cadastradas", artistas, musicas))
        return NULL;

    int maior_id = maior_id_musica(musicas);
    Musica *musica = NULL;
    int id_musica = 0;
    int opcao = 0;

    do {
        id_musica = ler_opcao(msg, maior_id);
        musica = encontrar_musica(musicas, id_musica);
        if (!musica) {
            msg_erro("Nao foi encontrada nenhuma musica com esse id|");
            opcao = !ler_confirmacao("Deseja procurar outra musica? [S/N]\n\t>>> ",
                                        's', 'n');
        }
        else {
            exibir_musica(artistas, musica, 0);
            opcao = ler_confirmacao("Deseja selecionar essa musica? [S/N]\n\t>>> ",
                                        's', 'n');
        }
    } while (!opcao);

    return musica;
}

int exibir_artista(Artista *artista, int fechar_borda) {
    if (!artista)
        return -1;

    linha(BORDA_SECUNDARIA, COMPRIMENTO_BORDA_SECUNDARIA);
    printf("%4d |", artista->id);
    centralizar(artista->nome, COMPRIMENTO_BORDA_SECUNDARIA - 6);
    printf("     |");
    centralizar(artista->genero, COMPRIMENTO_BORDA_SECUNDARIA - 6);
    if (fechar_borda)
        linha(BORDA_SECUNDARIA, COMPRIMENTO_BORDA_SECUNDARIA);
    
    return 0;
}

int exibir_artistas(Lista_Artistas *artistas) {
    if (!artistas)
        return -1;

    Artista_No *no = artistas->prox;
    int fechar_borda = 0;

    putchar(10);
    linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);
    if (!no) {
        centralizar("Ainda nAo cadastrado nenhum artista!",
                        COMPRIMENTO_BORDA_PRINCIPAL);
        linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);
        putchar(10);
        return 1;
    }
    centralizar("Artistas Cadastrados", COMPRIMENTO_BORDA_PRINCIPAL);
    linha(BORDA_SECUNDARIA, COMPRIMENTO_BORDA_PRINCIPAL);

    printf("  id |");
    centralizar("Nome / Genero Musical", COMPRIMENTO_BORDA_PRINCIPAL - 6);
    linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);

    while (no) {
        if (!no->prox)
            fechar_borda = 1;
        exibir_artista(no->artista, fechar_borda);
        no = no->prox;
    }

    linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);
    putchar(10);

    return 0;
}

int exibir_musicas_artista(Lista_Musicas *musicas, Lista_Artistas *artistas) {
    if (!musicas)
        return -1;
    if (!artistas)
        return -2;

    Artista *artista = selecionar_artista(artistas, 
                                    "Escolha o artista por seu id:\n\t>>> ");
    if (!artista) {
        linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);
        putchar(10);
        return 1;
    }

    Lista_Musicas *musicas_artista = nova_lista_musicas();
    encontrar_musica_artista(musicas, artista->id, musicas_artista);

    if (exibir_musicas("Musicas do Artista Selecionado", artistas, musicas)) {
        apagar_lista_musicas(musicas_artista, 0);
        return 2;
    }
    
    apagar_lista_musicas(musicas_artista, 0);
    return 0;
}

Artista *selecionar_artista(Lista_Artistas *artistas, char *msg) {
    if (!artistas)
        return NULL;

    if (exibir_artistas(artistas))
        return NULL;
    
    int maior_id = maior_id_artista(artistas);
    Artista *artista;
    int id_artista = 0;
    int opcao = 0;

    do {    
        int id_artista = ler_opcao(msg, maior_id);
        artista = encontrar_artista(artistas, id_artista);
        if (!artista) {
            msg_erro("Nao foi encontrado nenhum artista com esse id!");
            opcao = !ler_confirmacao("Procurar outro artista? [S/N]\n\t>>> ", 
                                        's', 'n');
        }
        else {
            exibir_artista(artista, 0);
            opcao = ler_confirmacao("Selecionar esse artista? [S/N]\n\t>>> ",
                                        's', 'n');
        }
    } while (!opcao);
    
    return artista;
}

int criar_playlist(Lista_Playlists *lista_playlists, Lista_Musicas *musicas, 
                    Lista_Artistas *artistas) {
    if (!lista_playlists)
        return -1;
    if (!musicas)
        return -2;
    if (!artistas)
        return -3;

    if (exibir_musicas("Musicas Cadastradas", artistas, musicas))
        return 1;

    putchar(10);
    linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);
    
    char nome_playlist[TAMANHO_NOME_LPLAYLIST];
    ler_nome("Escolha um nome para a playlist:\n\t>>> ", nome_playlist);

    Lista_Musicas *musicas_playlist = nova_lista_musicas();

    char msg[81];
    strcpy(msg, "Digite uma sequencia de ids para selecionar as musicas.\nEx.: ");
    strcat(msg, ">>> 1 2 3 4 5\n\t>>> ");

    if (!ler_sequencia_musicas(msg, musicas, musicas_playlist, artistas)) {
        mensagem("Nenhuma musica selecionada! Abortando Operacao!");
        linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);
        putchar(10);
        return 2;
    }

    Playlist *playlist = nova_playlist();
    adicionar_de_lista(playlist, musicas_playlist);
    apagar_lista_musicas(musicas_playlist, 0);

    linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);
    putchar(10);

    if (!adicionar_playlist(lista_playlists, nome_playlist, playlist)) {
        apagar_playlist(playlist);
        return -5;
    }

    return 0;
}

int exibir_playlist(LPlaylist_No *playlist) {
    if (!playlist)
        return -1;

    linha(BORDA_SECUNDARIA, COMPRIMENTO_BORDA_SECUNDARIA);
    printf("%4d |", playlist->id);
    centralizar(playlist->nome, COMPRIMENTO_BORDA_SECUNDARIA - 6);
    linha(BORDA_SECUNDARIA, COMPRIMENTO_BORDA_SECUNDARIA);

    return 0;
}

int exibir_playlists(Lista_Playlists *lista_playlists) {
    if (!lista_playlists)
        return -1;
    
    LPlaylist_No *no = lista_playlists->prox;

    putchar(10);
    linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);
    if (!no) {
        centralizar("Nenhuma playlist foi criada ainda!", COMPRIMENTO_BORDA_PRINCIPAL);
        linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);
        putchar(10);
        return 1;
    }
    centralizar("Playlists Cadastradas", COMPRIMENTO_BORDA_PRINCIPAL);
    linha(BORDA_SECUNDARIA, COMPRIMENTO_BORDA_PRINCIPAL);
    printf("  id |");
    centralizar("Nome da Playlist", COMPRIMENTO_BORDA_PRINCIPAL - 6);
    linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);

    while (no) {
        exibir_playlist(no);
        no = no->prox;
    }

    linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);
    putchar(10);

    return 0;
}

int exibir_musicas_playlist(Lista_Playlists *lista_playlists, Lista_Artistas *artistas) {
    if (!lista_playlists)
        return -1;

    Playlist *playlist = selecionar_playlist(lista_playlists);
    if (!playlist) {
        linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);
        putchar(10);
        return 1;
    }

    Lista_Musicas *musicas_playlist = nova_lista_musicas();
    if (!playlist_para_lista(musicas_playlist, playlist)) {
        msg_erro("Falha ao obter as musicas das playlists!");
        linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);
        putchar(10);
        return -1;
    }

    exibir_musicas("Musicas da Playlist", artistas, musicas_playlist);
    apagar_lista_musicas(musicas_playlist, 0);

    return 0;
}

Playlist *selecionar_playlist(Lista_Playlists *lista_playlists) {
    if (!lista_playlists)
        return NULL;

    if (exibir_playlists(lista_playlists))
        return NULL;
    
    int maior_id = maior_id_lplaylist(lista_playlists);
    int id_playlist = 0;
    LPlaylist_No *no_lplaylist = NULL;
    int opcao = 0;

    do {
        id_playlist = ler_opcao("Selecione a playlist pelo id:\n\t>>> ", maior_id);
        no_lplaylist = encontrar_playlist(lista_playlists, id_playlist);

        if (!no_lplaylist) {
            msg_erro("A playlist nao foi encontrada! Verifique o id digitado!");
            opcao = !ler_confirmacao("Tentar novamente? [S/N] ", 's', 'n');
            continue;
        }
        
        exibir_playlist(no_lplaylist);
        opcao = ler_confirmacao("Selecionar essa musica? [S/N] ", 's', 'n');
    } while (!opcao);

    return no_lplaylist->musicas;
}

int esquecer_musica(Lista_Musicas *musicas, Lista_Playlists *lista_playlists);

int esquecer_artista(Lista_Artistas *artisas, Lista_Musicas *musicas,
                        Lista_Playlists *lista_playlists);
