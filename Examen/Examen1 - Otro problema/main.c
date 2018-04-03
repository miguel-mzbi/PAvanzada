#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "sample-Reverse.1.in"

void insert(char *string, char *insert, int pos) {
    char buf[256] = {};
    strncpy(buf, string, pos);
    int len = strlen(buf);
    strcpy(buf+len, insert);
    // len += strlen(insert);
    // strcpy(buf+len, string+pos);
    strcpy(string, buf);
}

void reverseWord(char *originalWord, char *reversedWord) {
    int len = strlen(originalWord);
    int end = len -1;
    for(int i = 0; i < len; i++) {
        reversedWord[i] = originalWord[end];
        end--;
    }
    reversedWord[len] = '\0';
}

int main(int argc, char **argv) {

    FILE *fileInput = fopen(FILENAME, "r");

    char *buffer;
    size_t bufsize = 2048;
    buffer = (char *) malloc(bufsize * sizeof(char));

    getline(&buffer, &bufsize, fileInput);
    char *ptr;
    int numCase = strtol(buffer, &ptr, 10);

    printf("Cases: %i\n", numCase);

    for(int i = 0; i < numCase; i++) {

        getline(&buffer, &bufsize, fileInput);
        char reversedLine[2048];
        int n = strcspn(buffer, "\n");
        buffer[n] = '\0';

        // printf("Read: %s\n", buffer);

        if(buffer != NULL) {
            char *substr;
            int pos = 0;
            while((substr = strsep(&buffer, " ")) != NULL) {
                // printf("\tWord: %s\n", substr);
                char reversedWord[strlen(substr)+1];
                reverseWord(substr, reversedWord);
                // printf("\tWord REV: %s\n", reversedWord);
                insert(reversedLine, reversedWord, pos);
                pos += strlen(substr);
                insert(reversedLine, " ", pos);
                pos++;
            }
            reversedLine[pos] = '\0';
            printf("%s\n", reversedLine);
        }
    }

    return 0;
}