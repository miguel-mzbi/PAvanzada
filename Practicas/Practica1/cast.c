#include <stdio.h>

int main() {
    int a = 4;
    int j;
    int* p;
    float f = 7.4;
    int max = 2147483647;
    long int d;
    int b = a + f;
    float c = a * f;
    d = (long)max * max + 3;
    p = &a;
    *p = 7;
    p++;
    *p = 8;

    int arreglo[5] = {0, 2};
    int itemsArreglo = sizeof(arreglo)/sizeof(arreglo[0]);

    printf("p = %p, a = %d, j = %d, b = %d, d = %ld\n", p, a, j, b, d);
    printf("f = %f, c = %f\n", f, c);
    printf("long int size: %d\n", (int) sizeof(long int));

    return 0;
}