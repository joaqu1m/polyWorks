//
// Created by Joaqu on 8/20/2023.
//
#include <stdio.h>

int main() {
    while (1) {
        int numeroEscolhido;
        scanf("%d", &numeroEscolhido);

        for(int i = 1; i <= 10; i++) {
            printf("%dx%d=%d\r\n", numeroEscolhido, i, numeroEscolhido * i);
        }
    }
}