#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "test.txt"
#define SIZE 101
#define WORDSIZE 10
#define BUFFSIZE 9000

char table[SIZE][WORDSIZE];

int match(char *correctWord, char *word, int length) {
    int mismatch = 0;
    //printf("TRY %s vs. %s\n", correctWord, word);
    for(int i = 0; i < length; i++){
        if(word[i] != correctWord[i]){
            if(mismatch){
                return 0;
            }
            mismatch = 1;
        }
    }
    return mismatch;
}


int processWord(char *word, int wordLength, int currentRes, char *res, int *corrections) {
    for(int i = 0; i < SIZE; i++) {
        if(strlen(table[i]) == wordLength && match(table[i], word, wordLength)){
            int putWord = currentRes - wordLength;
            for(int j = 0; putWord < currentRes; putWord++, j++) {
                res[putWord] = table[i][j];
            }
            *corrections = *corrections +1;
            return 1;
        }
    }
    return 0;
}

int cleanWord(char *word, int l) {
    for(int i = 0; i < l; i++) {
        word[i] = '\0';
    }
    return 0;
}

void printTable() {
    printf("\nTABLE----------------\n");
    for(int i = 0; i < SIZE; i++) {
        if(table[i][0] != '\0') {
            printf("%d, %s\n", i, table[i]);
        }
    }
    printf("---------------------\n\n");
}

int main() {
    
    char *line = NULL;
    char *lineOfWords = NULL;
    char word[8] = {'\0'};
    char response[BUFFSIZE] = {'\0'};
    int currInWord = 0;
    int currInRes = 0;
    int sizeRead = 0;
    int numberCorrections = 0;
    size_t len = 0;

    FILE *file = fopen("test.txt", "r");
    
    int wordsRead = 0;
    while(fgets(table[wordsRead], sizeof(table[0]), file)) {
        if(table[wordsRead][0] == '#') {
            printf("# WAS READ, NEXT PART\n");
            table[wordsRead][0] = '\0';
            table[wordsRead][1] = '\0';
            wordsRead--;
            break;
        }
        else {
            table[wordsRead][strlen(table[wordsRead])-1] = '\0';
            printf("Inserting to dictionary: %s\n", table[wordsRead]);
            wordsRead++;
        }
    }

    printTable();
    
    sizeRead = 0;
    while((sizeRead = getline(&lineOfWords, &len, file)) != -1){
        for(int i = 0; i < sizeRead; i++) {
            char currChar = lineOfWords[i];
            if(currChar >= 'a' && currChar <= 'z') {
                word[currInWord] = currChar;
                response[currInRes] = '-';
                currInRes++;
                currInWord++;
            }
            else {
                if(currInWord != 0 && !processWord(word, currInWord, currInRes, response, &numberCorrections)) {
                    printf("No corrections found for %.*s\n", currInWord, word);
                    int putWord = currInRes - currInWord;
                    for(int j = 0; putWord < currInRes; putWord++, j++) {
                        response[putWord] = word[j];
                    }
                }
                cleanWord(word, currInWord);
                response[currInRes] = currChar;
                currInWord = 0;
                currInRes++;
            }
        }
    }
    fclose(file);

    printf("\n%s%d\n", response, numberCorrections);

    free(file);
    free(line);
    free(lineOfWords);

    return 0;
}