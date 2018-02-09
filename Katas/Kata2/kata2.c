#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFSIZE 1024
#define FILENAME "test.txt"


int anagramMap(char *password, int n) {

    int hasNumber = 0;
    int hasLower = 0;
    int hasUpper = 0;
    int hasMin = 0;
    int hasMax = 0;
    int tripleRepeatPos[BUFFSIZE] = {-1};
    int tripleRepeatPosSize = 0;
    int basicNumber = -1;
    int basicUpper = -1;
    int basicLower = -1;
    int lastTriple = -1;

    if(n >= 6) {
        hasMin = 1;
    }
    else if(n <= 20) {
        hasMax = 1;
    }
    
    // Setting up flags
    char prevChar = '\0', prevPrevChar = '\0';
    for(int i = 0; i < n; i++) {
        char currentChar = password[i];
        if(!hasLower && currentChar >= 'a' && currentChar <= 'z') {
            hasLower = 1;
            basicLower = i;
        }
        else if(!hasUpper && currentChar >= 'A' && currentChar <= 'Z') {
            hasUpper = 1;
            basicUpper = i;
        }
        else if(!hasNumber && currentChar >= '0' && currentChar <= '9') {
            hasNumber = 1;
            basicNumber = i;
        }
        if(currentChar == prevChar && prevChar == prevPrevChar) {
            if(i-lastTriple >= 3 || lastTriple == -1) {
                tripleRepeatPos[tripleRepeatPosSize] = i;
                tripleRepeatPosSize++;
                lastTriple = i;
            }
        }
        prevPrevChar = prevChar;
        prevChar = currentChar;
    }

    // Fixing basic flags
    if(!hasLower) {
        password[n] = 'a';
        basicLower = n;
        n++;
        hasLower = 1;
    }
    if(!hasUpper) {
        password[n] = 'A';
        basicUpper = n;
        n++;
        hasUpper = 1;
    }
    if(!hasNumber) {
        password[n] = '0';
        basicNumber = n;
        n++;
        hasNumber = 1;
    }  
    if(n >= 6) {
        hasMin = 1;
    }

    // Fixing min length
    while(!hasMin) {
        if(password[n-1] == '\0') {
            password[n] = 'a';
            n++;
        }
        else {
            if(password[n-1] +1 < '9') {
                password[n] = password[n-1] +1;
            }
            else {
                password[n] = '0';
            }
            n++;
        }
        if(n >= 6) {
            hasMin = 1;
        }
    }
    hasMin = 1;

    // Fixing sequences
    for(int i = 0; i < tripleRepeatPosSize; i++) {
        if(password[tripleRepeatPos[i]] != 'a' && password[tripleRepeatPos[i]+1] != 'a') {
            password[tripleRepeatPos[i]] = 'a';
        }
        else if(password[tripleRepeatPos[i]] != 'b' && password[tripleRepeatPos[i]+1] != 'b') {
            password[tripleRepeatPos[i]] = 'b';
        }
        else {
            password[tripleRepeatPos[i]] = 'c';
        }
    }

    // Fixing long
    for(int i = 0; i < n; i++) {
        if(n <= 20) {
            break;
        }
        else {
            if((i == basicLower || i == basicNumber || i== basicUpper) || 
            ((password[i-2] == password[i-1] && password[i-1] == password[i+1]) || 
            (password[i-1] == password[i+1] && password[i+1] == password[i+2]))) {
                printf("%c at %d\n", password[i], i);
                continue;
            }
            else {
                memmove(&password[i], &password[i+1], n-i);
                n--;
                i--;
            }
        }
    }
    printf("Suggested new password:\n%.*s with length %d\n", n, password, n);


    return 0;
}

int main() {
    
    char password[BUFFSIZE];

    FILE *f = fopen("test.txt", "r");
    fgets(password, BUFFSIZE, f);
    fclose(f);

    int n = strcspn(password, "\n");
    password[n] = 0;
    printf("String read: %s\nWith length of: %d\n", password, n);

    anagramMap(password, n);
    free(f);

    return 0;
}