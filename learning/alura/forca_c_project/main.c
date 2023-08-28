//
// Created by Joaqu on 8/20/2023.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"

#define MAX_WORD_SIZE 100

char palavrasecreta[MAX_WORD_SIZE];
char chutes[26];
int tentativas = 0;

void chutar() {
    char chute;
    printf("Qual letra?\r\n");
    scanf(" %c", &chute);

    chutes[tentativas] = chute;
    tentativas++;
}

int jaChutou(char letra) {
    int achou = 0;
    for (int j = 0; j < tentativas; j++) {
        if (tolower(chutes[j]) == tolower(letra)) {
            achou = 1;
            break;
        }
    }

    return achou;
}

void desenharForca() {

    printf("Voce ja deu %d chutes\n", tentativas);

    for (int i = 0; i < strlen(palavrasecreta); i++) {

        if (jaChutou(palavrasecreta[i])) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }

    }
    printf("\n");

}

int main() {

    int acertou = 0;
    int enforcou = 0;

    FILE *f;

    f = fopen("forca_c_project\\palavras.txt", "r");

    int qntPalavras = -1;
    while (!feof(f)) {
        char c;
        fscanf(f, "%c", &c);
        if (c == '\n') {
            qntPalavras++;
        }
    }

    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    srand(ts.tv_nsec);

    int numeroRandomico = rand() % qntPalavras;

    rewind(f);
    int barraEnesVistos = 0;
    int i = 0;
    while (!feof(f)) {
        char c;
        fscanf(f, "%c", &c);
        if (c == '\n') {
            barraEnesVistos++;
        } else {
            if (barraEnesVistos == numeroRandomico) {

                palavrasecreta[i] = c;

                i++;
            }
        }
    }

    printf("%s", palavrasecreta);


    fclose(f);

//    char novapalavra[MAX_WORD_SIZE];
//
//    printf("Digite a nova palavra, em letras maiúsculas: ");
//    scanf("%s", novapalavra);
//
//    FILE *f;
//
//    f = fopen("palavras.txt", "r+");
//    if (f == 0) {
//        printf("Banco de dados de palavras não disponível\n\n");
//        exit(1);
//    }
//
//    int qtd;
//    fscanf(f, "%d", &qtd);
//    qtd++;
//    fseek(f, 0, SEEK_SET);
//    fprintf(f, "%d", qtd);
//
//    fseek(f, 0, SEEK_END);
//    fprintf(f, "\n%s", novapalavra);
//
//    fclose(f);

    do {
        desenharForca();
        chutar();
    } while (!acertou && !enforcou);

}