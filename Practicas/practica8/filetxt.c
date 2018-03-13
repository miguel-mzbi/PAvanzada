#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define printDebug(...) \
    do{ \
        char *isDebug; \
        isDebug = getenv("DEBUG"); \
        if(isDebug != NULL && !strcasecmp(isDebug, "y")) { \
            fprintf(stderr, __VA_ARGS__); \
        } \
    } while(0)

int main() {
    char *fileName = "output.txt";
    FILE *output;
    output = fopen(fileName, "a");
    printDebug("output = %p\n", output);

    int character;
    while(1) {
        character = fgetc(stdin);
        if(feof(stdin)) break;
        fputc(character, output);
    }

    fclose(output);
    return 0;
}