#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "sample-Reverse.1.in"

void insert(char *string, char *insert, int pos) {
    char buf[256] = {};
    strncpy(buf, string, pos);
    int len = strlen(buf);
    strcpy(buf+len, insert);
    len += strlen(insert);
    strcpy(buf+len, string+pos);
    strcpy(string, buf);
}

int main(int argc, char **argv) {

    FILE *fileInput = fopen(FILENAME, "r");

    char *buffer;
    size_t bufsize = 2048;
    buffer = (char *) malloc(bufsize * sizeof(char));

    getline(&buffer, &bufsize, fileInput);
    char *ptr;
    int numCase = strtol(buffer, &ptr, 10);

    for(int i = 0; i < numCase; i++) {

        getline(&buffer, &bufsize, fileInput);
        int n = strcspn(buffer, "\n");
        buffer[n] = '\0';

        char *reversedLine = (char *) malloc(2048 * sizeof(char));

        // printf("Read: %s\n", buffer);

        if(buffer != NULL) {
            char *substr;
            while((substr = strsep(&buffer, " ")) != NULL) {
                // printf("\tWord: %s\n", substr);
                insert(reversedLine, substr, 0);
                insert(reversedLine, " ", 0);
            }
            reversedLine = &reversedLine[1];
            printf("%s\n", reversedLine);
        }
    }

    return 0;
}