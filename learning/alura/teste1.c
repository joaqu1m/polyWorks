//
// Created by Joaqu on 8/19/2023.
//
#include <stdio.h>

int main() {
    int i = 1;
    int cont = 0;
    while (i <= 100) {
        cont += i;
        i++;
    }
    printf("%d", cont);
}
