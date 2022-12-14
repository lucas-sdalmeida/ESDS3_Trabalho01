#include "utilidades.h"

int e_letra(char digito) {
    if ('A' <= digito && digito <= 'Z')
        return 2;
    if ('a' <= digito && digito <= 'z')
        return 1;
    return 0;
}

int cortar_espacos(char *string, char opcao) {
    if (!string)
        return -1;
    if (opcao != 'e' && opcao != 'd' && opcao != 'a')
        return -2;

    int comeco_string = 0;
    int fim_string = strlen(string) - 1;

    if (opcao == 'e' || opcao == 'a') {
        while (comeco_string <= fim_string && 
                (string[comeco_string] == ' ' || string[comeco_string] == '\n'))
            comeco_string++;
        int i = comeco_string;
        for (; comeco_string > 0 && i <= fim_string; i++)
            string[i - comeco_string] = string[i];
        if (comeco_string > 0) {
            string[i - comeco_string] = 0;
            fim_string = i - comeco_string - 1;
        }
    }
    if (opcao == 'd' || opcao == 'a') {
        while (fim_string >= comeco_string && 
                (string[fim_string] == ' ' || string[fim_string] == '\n'))
            fim_string--;
        string[fim_string + 1] = 0;
    }

    return 0;
}

int validar_nome(char *nome) {
    if (!nome)
        return 0;

    int comprimento_nome = strlen(nome);
    if (comprimento_nome < 1)
        return 0;

    int letra = 1;
    char digito;
    int i=0;

    for (; i<comprimento_nome; i++) {
        digito = nome[i];
        if (letra && !e_letra(digito))
            return 0;
        letra = 0;
        if (digito == ' ' || digito == '-' || digito == '\'') {
            letra = 1;
            continue;
        }
        if (digito == '\n')
            return 1;
        if (!e_letra(digito))
            return 0;
    }

    return 1;
}

int formatar_nome(char *nome) {
    if (!nome)
        return 0;
    if (!validar_nome(nome))
        return 0;

    int comprimento_nome = strlen(nome);
    int primeira = 1;

    int i=0;
    for (; i<comprimento_nome; i++) {
        if (primeira && e_letra(nome[i]) == 1) {
            nome[i] -= 32;
            primeira = 0;
        }
        if (!primeira && e_letra(nome[i]) == 2)
            nome[i] += 32;
        if (nome[i] == ' ')
            primeira = 1;
    }

    return 1;
}

int formatar_hora(int tempo_em_segundos, char *destino) {
    if (!destino)
        return -1;

    int minutos = tempo_em_segundos / 60;
    tempo_em_segundos %= 60;
    int horas = minutos / 60;
    minutos %= 60;

    return sprintf(destino, "%02d:%02d:%02d", horas, minutos, tempo_em_segundos);
}

int obter_seq_int(char *origem, Int_Queue *queue) {
    if (!origem)
        return -1;
    if (!queue)
        return -2;
    
    char *prox_numero = strtok(origem, " ");
    int numero = 0;
    int qtdd_numeros = 0;

    while (prox_numero) {
        numero = atoi(prox_numero);
        if (numero == 0)
            return qtdd_numeros;
        if (int_queue_insert(queue, numero))
            return qtdd_numeros;
        qtdd_numeros++;
        prox_numero = strtok(NULL, " ");
    }

    return qtdd_numeros;
}

int playlist_para_lista(Lista_Musicas *musicas, Playlist *origem) {
    if (!musicas)
        return -1;
    if (!origem)
        return -2;

    Playlist_No *no_playlist = origem->prox;
    int num_musicas = 0;

    while (no_playlist != origem) {
        if (adicionar_musica(musicas, no_playlist->musica))
            num_musicas++;
        no_playlist = no_playlist->prox;
    }

    return num_musicas;
}

int shuffle(Playlist *playlist) {
    return 0;
}
