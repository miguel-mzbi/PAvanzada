#include "Thompson.h"

void initNfaArray(DynNFAArray *a, int initialSize) {
    a->array = (NFA *) malloc(initialSize * sizeof(NFA));
    a->used = 0;
    a->size = initialSize;
}

void insertNfaArray(DynNFAArray *a, NFA element) {
    if(a->used == a->size) {
        a->size *= 2;
        a->array = (NFA *) realloc(a->array, a->size * sizeof(NFA));
    }
    a->array[a->used++] = element;
}

void freeNfaArray(DynNFAArray *a) {
    free(a->array);
    a->array = NULL;
    a->used = 0;
    a->size = 0;
}

NFA popNFA(DynNFAArray *a) {
    int popIndex = a->used -1;
    a->used -= 1;
    return a->array[popIndex];
}

void pushNFA(DynNFAArray *a, NFA element) {
    if(a->used == a->size) {
        a->size *= 2;
        a->array = (NFA *) realloc(a->array, a->size * sizeof(NFA));
    }
    a->array[a->used++] = element;
}

NFA topNFA(DynNFAArray *a) {
    return a->array[a->used -1];
}