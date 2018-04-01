#include "Thompson.h"

transition nullTransition = { .vertexFrom = 0, .vertexTo = 0, .transitionSymbol = '\0' };

void initTransitionArray(DynTransArray *a, int initialSize) {
    a->array = (transition *) malloc(initialSize * sizeof(transition));
    a->used = 0;
    a->size = initialSize;
}

void insertTransitionArray(DynTransArray *a, transition element) {
    if(a->used == a->size) {
        a->size *= 2;
        transition *newT = (transition *) malloc(a->size * sizeof(transition));
        for(int i = 0; i < a->used; i++) {
            newT[i] = a->array[i];
        }
        a->array = newT;
        //a->array = (transition *) realloc(a->array, a->size * sizeof(transition));
    }
    a->array[a->used++] = element;
}

void freeTransitionArray(DynTransArray *a) {
    free(a->array);
    a->array = NULL;
    a->used = 0;
    a->size = 0;
}

transition popTransition(DynTransArray *a) {
    int popIndex = a->used -1;
    a->used -= 1;
    return a->array[popIndex];
}

void pushTransition(DynTransArray *a, transition element) {
    if(a->used == a->size) {
        a->size *= 2;
        transition *newT = (transition *) malloc(a->size * sizeof(transition));
        for(int i = 0; i < a->used; i++) {
            newT[i] = a->array[i];
        }
        a->array = newT;
    }
    a->array[a->used] = element;
    a->used++;
}

transition topTransition(DynTransArray *a) {
    return a->array[a->used -1];
}