#include "main.h"

// ε-transition symbol
#define empty '%'
// Debug print, only available if ENV_VAR is available
#define printDebug(...) \
    do{ \
        char *isDebug; \
        isDebug = getenv("DEBUG"); \
        if(isDebug != NULL && !strcasecmp(isDebug, "true")) { \
            fprintf(stderr, __VA_ARGS__); \
        } \
    } while(0)

struct DynNFAArray {
    NFA *array;
    int used;
    int size;
} typedef DynNFAArray;


struct CharStack {
    char *array;
    int used;
    int size;
} typedef CharStack;

// Transitions Dynamic Array functions

void initTransitionArray(DynTransArray *, int);
void insertTransitionArray(DynTransArray *, transition);
void freeTransitionArray(DynTransArray *);
transition popTransition(DynTransArray *);
void pushTransition(DynTransArray *, transition);
transition topTransition(DynTransArray *);

// Vertices Dynamic Array functions

void initVertexArray(DynVertexArray *, int);
void insertVertexArray(DynVertexArray *, int);
void freeVertexArray(DynVertexArray *);
int popVertex(DynVertexArray *a);
void pushVertex(DynVertexArray *a, int element);
int topVertex(DynVertexArray *a);

// NFA Dynamic Array functions and stack operations

void initNfaArray(DynNFAArray *, int);
void insertNfaArray(DynNFAArray *, NFA);
void freeNfaArray(DynNFAArray *);
NFA popNFA(DynNFAArray *);
void pushNFA(DynNFAArray *, NFA);
NFA topNFA(DynNFAArray *);

// Char Dynamic Stack functions

void initCharArray(CharStack *a, int initialSize);
void freeCharArray(CharStack *a);
char popChar(CharStack *a);
void pushChar(CharStack *a, char element);
char topChar(CharStack *a);

// NFA inside operations

int getVertexCount(NFA *);
void setVertices(NFA *, int);
void setTransition(NFA *, int, int , char);
void setFinalState(NFA *, int);
int getFinalState(NFA *);

// NFA operations

// Initialize NFA
void initNFA(NFA *);
// f(E = E1E2)
NFA concatenate(NFA, NFA);
// f(E =(E1)*)
NFA kleene(NFA);
// f(E = (E1|E2|...|EN))
NFA or(DynNFAArray, int);