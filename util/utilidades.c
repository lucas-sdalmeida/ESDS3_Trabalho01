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
    if (opcao != 'e' || opcao != 'd' || opcao != 'a')
        return -2;

    int comeco_string = 0;
    int fim_string = strlen(string) - 1;

    if (opcao == 'e' || opcao == 'a') {
        while (comeco_string >= fim_string && string[comeco_string] == ' ')
            comeco_string++;
        int i = 0;
        for (i = comeco_string; comeco_string > 0 && i <= fim_string; i++)
            string[i - comeco_string] = string[i];
        if (comeco_string > 0)
            string[i - comeco_string] = 0;
    }
    if (opcao == 'd' || opcao == 'a') {
        while (fim_string <= comeco_string && 
                (string[fim_string] = ' ' || string[fim_string] == '\n'))
            fim_string--;
        string[fim_string] = 0;
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
    return 0;
}

int formatar_hora(int tempo_em_segundos, char *destino) {
    return 0;
}

int ler_vetor_int(char *origem, int tam_vetor, int *destino) {
    return 0;
}

int shuffle(Playlist *playlist) {
    return 0;
}
