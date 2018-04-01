#include "Thompson.h"

void initCharArray(CharStack *a, int initialSize) {
    a->array = (char *) malloc(initialSize * sizeof(char));
    a->used = 0;
    a->size = initialSize;
}

void freeCharArray(CharStack *a) {
    free(a->array);
    a->array = NULL;
    a->used = 0;
    a->size = 0;
}

char popChar(CharStack *a) {
    int popIndex = a->used -1;
    a->used -= 1;
    return a->array[popIndex];
}

void pushChar(CharStack *a, char element) {
    if(a->used == a->size) {
        a->size *= 2;
        a->array = (char *) realloc(a->array, a->size * sizeof(char));
    }
    a->array[a->used++] = element;
}

char topChar(CharStack *a) {
    return a->array[a->used -1];
}