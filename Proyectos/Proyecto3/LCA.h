#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WHITE 0
#define BLACK 1

#define printDebug(...) \
    do{ \
        char *isDebug; \
        isDebug = getenv("DEBUG"); \
        if(isDebug != NULL && !strcasecmp(isDebug, "y")) { \
            fprintf(stderr, __VA_ARGS__); \
        } \
    } while(0)

void buildConnections(FILE *, unsigned int, unsigned int **);
void BFS(unsigned int, unsigned int, unsigned int **, unsigned int *, unsigned int *);
unsigned int tryLCA(unsigned int, unsigned int, unsigned int, unsigned int *, unsigned int *, unsigned int);