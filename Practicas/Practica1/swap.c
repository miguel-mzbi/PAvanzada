#include <stdio.h>

int swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}

int swap_no(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    return 0;
}

int main() {
    int j = 27, k = 34;
    swap_no(j, k);
    printf("j = %d, k = %d\n", j, k);
    swap(&j, &k);
    printf("j = %d, k = %d\n", j, k);
    return 0;
}