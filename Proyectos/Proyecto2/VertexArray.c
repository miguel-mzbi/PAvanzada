#include "Thompson.h"

void initVertexArray(DynVertexArray *a, int initialSize) {
    a->array = (int *) malloc(initialSize * sizeof(int));
    a->used = 0;
    a->size = 100;
}

void insertVertexArray(DynVertexArray *a, int element) {
    if(a->used == a->size) {
        a->size *= 2;
        int *newT = (int *) malloc(a->size * sizeof(int));
        for(int i = 0; i < a->used; i++) {
            newT[i] = a->array[i];
        }
        a->array = newT;
    }
    a->array[a->used] = element;
    a->used++;
}

void freeVertexArray(DynVertexArray *a) {
    free(a->array);
    a->array = NULL;
    a->used = 0;
    a->size = 0;
}

int popVertex(DynVertexArray *a) {
    int popIndex = a->used -1;
    a->used -= 1;
    return a->array[popIndex];
}

void pushVertex(DynVertexArray *a, int element) {
    if(a->used == a->size) {
        a->size *= 2;
        int *newT = (int *) malloc(a->size * sizeof(int));
        for(int i = 0; i < a->used; i++) {
            newT[i] = a->array[i];
        }
        a->array = newT;
    }
    a->array[a->used] = element;
    a->used++;
}

int topVertex(DynVertexArray *a) {
    return a->array[a->used -1];
}