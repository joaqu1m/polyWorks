//
// Created by Joaqu on 8/27/2023.
//
#include <stdio.h>

void outraFunc(int* variavel) {
    // Tendo o endereço de memória de uma variável, podemos dar get e set seu valor remotamente

    printf("%d \r\n", (*variavel));

    // Incrementando na variável original da main
    (*variavel)++;

}

int main() {
    int variavel = 5;
    printf("%d \r\n", variavel);

    // Usamos o asterisco no final do nome de um tipo para dizer que será um endereço
    // na memória de um inteiro
    // Usamos o E comercial em uma variável para capturar seu endereço de memória
    int* enderecoMemoriaVariavel = &variavel;
    printf("%d \r\n", enderecoMemoriaVariavel);

    outraFunc(enderecoMemoriaVariavel);

    // Vendo se foi incrementado o valor
    printf("%d \r\n", variavel);
}