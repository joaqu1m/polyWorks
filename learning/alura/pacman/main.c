//
// Created by Joaqu on 8/27/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "main.h"

MAPA m;

void alocarMapa() {
    FILE* f;
    f = fopen("pacman\\mapa.txt", "r");
    if(f == 0) {
        printf("Erro na leitura do mapa");
        exit(1);
    }

    fscanf(f, "%d %d", &(m.linhas), &(m.colunas));

    m.matriz = malloc(sizeof(char*) * m.linhas);

    for(int i = 0; i < m.linhas; i++) {
        m.matriz[i] = malloc(sizeof(char) * m.colunas + 1);
    }

    for(int i = 0; i < 5; i++) {
        fscanf(f, "%s", m.matriz[i]);
    }

    fclose(f);
}

void liberarMapa() {
    for(int i = 0; i < m.linhas; i++) {
        free(m.matriz[i]);
    }

    free(m.matriz);
}

void mover(char direcao) {

    int x, y;

    for(int i = 0; i < m.linhas; i++) {
        for(int j = 0; j < m.colunas; j++) {
            if (m.matriz[i][j] == '@') {
                x = i;
                y = j;
            }
        }
    }

    switch (direcao) {
        case 'w':
            m.matriz[x-1][y] = '@';
            m.matriz[x][y] = '.';
            break;
        case 'a':
            m.matriz[x][y-1] = '@';
            m.matriz[x][y] = '.';
            break;
        case 's':
            m.matriz[x+1][y] = '@';
            m.matriz[x][y] = '.';
            break;
        case 'd':
            m.matriz[x][y+1] = '@';
            m.matriz[x][y] = '.';
            break;
    }
}

int main() {

    alocarMapa();

    while (1) {
        for(int i = 0; i < m.linhas; i++) {
            printf("%s\n", m.matriz[i]);
        }

        char comando;
        scanf(" %c", &comando);
        mover(tolower(comando));

    }

    liberarMapa();
}