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

int cadastrar_artista(Lista_Artistas *artistas) {
    if (!artistas)
        return -1;
    
    putchar(10);
    linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);
    centralizar("Cadastrar Artista", COMPRIMENTO_BORDA_PRINCIPAL);
    linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);

    char nome[TAMANHO_NOME_ARTISTA];
    ler_nome("Digite o nome do artista:\n\t>>> ", nome);
    char genero_musical[TAMANHO_GENERO_ARTISTA];
    ler_genero_musica("Digite o genero musical do artista:\n\t>>> ", 
                        genero_musical);
    Artista *artista = novo_artista(nome, genero_musical);

    linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);
    putchar(10);

    return (!adicionar_artista(artistas, artista)) ? -2 : 0;
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

    return (!adicionar_musica(musicas, musica)) ? -3 : 0;
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
    if (!titulo_menu)
        return -1;
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
    centralizar(titulo_menu, COMPRIMENTO_BORDA_PRINCIPAL);
    linha(BORDA_SECUNDARIA, COMPRIMENTO_BORDA_PRINCIPAL);

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
        apagar_lista_musicas(musicas_artista);
        return 2;
    }
    
    apagar_lista_musicas(musicas_artista);
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

int criar_playlist(Lista_Playlists *lista_playlists);

int exibir_playlist(Playlist_No *playlist);

int exibir_playlists(Lista_Playlists *lista_playlists);

int exibir_musicas_playlist(Lista_Playlists *lista_playlists);

Playlist *selecionar_playlist(Lista_Playlists *lista_playlists);

int esquecer_musica(Lista_Musicas *musicas, Lista_Playlists *lista_playlists);

int esquecer_artista(Lista_Artistas *artisas, Lista_Musicas *musicas,
                        Lista_Playlists *lista_playlists);
