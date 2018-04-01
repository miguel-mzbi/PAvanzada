#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct transition {
    int vertexFrom;
    int vertexTo;
    char transitionSymbol;
} typedef transition;

struct DynTransArray {
    transition *array;
    int used;
    int size;
} typedef DynTransArray;

struct DynVertexArray {
    int *array;
    int used;
    int size;
} typedef DynVertexArray;

struct NFA {
    DynVertexArray vertices;
    DynTransArray transitions;
    int finalState;
} typedef NFA;

// Transforms a REGEX into an NFA.
NFA REGEXtoNFA(char *);

// Returns 1 if the string is valid to the given NFA
int executeNFA(NFA, char*);