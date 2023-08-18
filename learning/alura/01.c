#include <stdio.h>

#define NUMERO_TENTATIVAS 10

int main() {

    printf("Voce tem um total de %d tentativas", NUMERO_TENTATIVAS);

    int numeroDesejado = 20;

    int i = 0;
    while (i < NUMERO_TENTATIVAS) {
        i++;
        printf("\r\nTentativa numero %d:\r\n", i);

        int numeroEscolhido;
        // 1. formatação 2. variavel
        scanf("%d", &numeroEscolhido);

        if(numeroEscolhido < 0) {
            printf("\r\nSem numeros negativos");
            i--;
        } else if(numeroEscolhido > numeroDesejado) {
            printf("\r\nChutou alto");
        } else if (numeroEscolhido < numeroDesejado) {
            printf("\r\nChutou baixo");
        } else {
            printf("\r\nVoce venceu o jogo");
            break;
        }
    }
}