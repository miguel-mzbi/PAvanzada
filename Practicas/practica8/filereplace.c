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
    char *filename = "input.txt";
    char *search = "mundo";
    char *replace = "Hola Mundo!";
    char word[255];
    long searchPos = 0;
    int character;
    FILE *input = fopen(filename, "r");

    while(1) {
        fscanf(input, "%s", word);
        if(feof(input)) break;
        if(strcmp(word, search) == 0) {
            printDebug("Found %s", word);
            fseek(input, -1*strlen(search), SEEK_CUR);
            searchPos = ftell(input);
            printDebug(" at %ld\n", searchPos);
            rewind(input);
            while(ftell(input) != searchPos) {
                character = fgetc(input);
                fputc(character, stdout);
            }
            break;
        }
    }

    return 0;
}