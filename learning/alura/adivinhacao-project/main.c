//
// Created by Joaqu on 8/19/2023.
//
#include <stdio.h>

#define NUMERO_TENTATIVAS 10

int main() {

    printf("Voce tem um total de %d tentativas", NUMERO_TENTATIVAS);

    int numeroDesejado = 20;
    double pontuacao = 1000;

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