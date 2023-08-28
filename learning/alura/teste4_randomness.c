//
// Created by Joaqu on 8/20/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // após a compilação do programa, ele nunca muda
    int num = rand();

    // função time:
    // pega o tempo em segundos (pouco precisa)
    // tem base no localdate do sistema (previsível, pode gerar problemas caso o localdate
    // seja alterado)
    int tempo = time(0);

    // função clock_gettime:
    // pega o tempo em nanossegundos (muito preciso)
    // tem base na data de boot do sistema operacional (não gera problemas)
    struct timespec ts;
    tempo = clock_gettime(CLOCK_MONOTONIC, &ts);

    // mudando a semente de geração de números aleatórios com base em um valor
    // externamente variável (tanto time quanto clock_gettime iriam funcionar aqui)
    srand(tempo);

    // esse valor diferente todas as vezes
    printf("%d \r\n", rand());

    // utilizando o operador de resto de divisão para pegar apenas valores de 0 a 99
    while(1) {
        printf("%d \r\n", rand() % 100);
    }
}