#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "hash.h"

#define BUFFSIZE 1024
#define FILENAME "test.txt"

unsigned hash(void *key, unsigned size) {
    unsigned char *str = (unsigned char *)key;
    unsigned hash = 5381;
    int c;
    while((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % size;
}

void * copyKey(void *element) {
    char *realVal = (char *)element;
    return (void *)strdup(realVal);
}

int * copyVal(int *value) {
    int *x;
    *x = *value;
    return x;
}

int cmpKeys(void *e1, void *e2) {
    return strcmp((char *)e1, (char *)e2);
}

char *getWord(FILE *fp) {
    char word[100];
    int ch;
    int i = 0;
    while(EOF != (ch = fgetc(fp)) && !isalpha(ch)); // Skip start
    if(ch == EOF) return NULL;

    do {
        word[i++] = tolower(ch);
    }
    while(EOF != (ch = fgetc(fp)) && isalpha(ch));

    word[i] = '\0';
    return strdup(word);
}

void readFile(FILE *fp, Hash myHash){
    char *word;
    while((word = getWord(fp))) {
        int value = 1;
        insert(&myHash, word, &value);
    }
    fclose(fp);
}

int main() {
    Hash myHash;
    unsigned size = 20;
    initHash(&myHash, size, hash, cmpKeys, copyKey, copyVal);
    FILE *file = fopen(FILENAME, "r");
    readFile(file, myHash);
    printTable(&myHash);
    // void * pal = (void *)"hola";
    // int *t = (int *)malloc(sizeof(int));
    // t = getVal(&myHash, pal);
    // if(t == NULL) {
    //     printf("NOT FOUND\n");
    // }
    // else {
    //     printf("FOUND %i INSTANCES\n", *t);
    // }
}