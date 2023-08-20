#include <stdio.h>
#include <stdlib.h>

int main() {

    int var1 = 5;
    int var2 = 10;

    printf("%d \r\n", var1 / var2);
    // 0
    printf("%f \r\n", var1 / var2);
    // 0.000000 || -1.#QNAN0
    printf("%d \r\n", var1 / (double)var2);
    // 0
    printf("%f \r\n", var1 / (double)var2);
    // 0.500000
    printf("%f \r\n", (double)var1 / var2);
    // 0.500000
    printf("%f \r\n", (double)var1 / (double)var2);
    // 0.500000

    double pi = 3.14;

    printf("%d \r\n", (int)pi);
    // 3
    printf("%f \r\n", pi);
    // 3.140000
    printf("%.2f \r\n", pi);
    // 3.14

    printf("%d \r\n", 3);
    // 3
    printf("%d \r\n", abs(3));
    // 3
    printf("%d \r\n", 3 * -1);
    // -3

    printf("%d \r\n", -3);
    // -3
    printf("%d \r\n", abs(-3));
    // 3
    printf("%d \r\n", -3 * -1);
    // 3

    return 0;
}
