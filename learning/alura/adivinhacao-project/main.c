//
// Created by Joaqu on 8/19/2023.
//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUMERO_TENTATIVAS 10

int main() {

    printf("Voce tem um total de %d tentativas para acertar o numero secreto de 1 a 100", NUMERO_TENTATIVAS);

    double pontuacao = 1000;

    srand(time(0));
    int numeroDesejado = (rand() % 100) + 1;

    int i = 0;
    while (i < NUMERO_TENTATIVAS) {
        i++;
        printf("\r\nTentativa numero %d:\r\n", i);

        int numeroEscolhido;
        // 1. formatação 2. variavel
        scanf("%d", &numeroEscolhido);

        printf("\r\n");
        if(numeroEscolhido < 0) {
            printf("Sem numeros negativos");
            i--;
        } else if(numeroEscolhido > numeroDesejado) {
            pontuacao -= (numeroEscolhido - numeroDesejado) / 2.0;
            printf("Chutou alto");
        } else if (numeroEscolhido < numeroDesejado) {
            pontuacao -= (numeroDesejado - numeroEscolhido) / 2.0;
            printf("Chutou baixo");
        } else {
            printf("Voce venceu o jogo com a pontuacao de %.2f", pontuacao);
            break;
        }
    }
}