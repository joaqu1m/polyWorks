#include <stdio.h>

int main() {
    printf("apenas compilando meu codigo com gcc 01.c -o 01.exe\n");

    int variavelTeste = 40;
    printf("variavelTeste e %d \n", variavelTeste);

    int numeroEscolhido;
    // 1. formatação 2. variavel
    scanf("%d", &numeroEscolhido);

    if (numeroEscolhido == variavelTeste) {
        printf("Voce acertou");
    } else {
        printf("Voce errou");
    }
    printf("\nvarTeste foi de %d e numeroEscolhido foi de %d \n", variavelTeste, numeroEscolhido);
}