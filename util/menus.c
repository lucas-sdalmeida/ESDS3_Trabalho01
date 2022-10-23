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
        centralizar(va_arg(opcoes, char*), 54);
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

int ler_opcao_de(char *msg, int num_possiveis_valores,...);

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
        if (nome_valido)
            msg_erro("Digite um nome valido ou confira e corriga o digitado");
    } while (nome_valido);

    return 0;
}

int cadastrar_artista(Lista_Artistas *artistas) {
    if (!artistas)
        return -1;
    
    putchar(10);
    linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);
    centralizar("Cadastrar Artista", COMPRIMENTO_BORDA_PRINCIPAL);
    linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);

    linha(BORDA_PRINCIPAL, COMPRIMENTO_BORDA_PRINCIPAL);
    putchar(10);

    return 0;
}

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
