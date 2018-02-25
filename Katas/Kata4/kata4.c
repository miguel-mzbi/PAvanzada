#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFSIZE 1024
#define FILENAME "test.txt"

int isNumber(char x) {
    if(x >= 48 && x <= 57) return 1;
    else return 0;
}

int isNumberNotZero(char x) {
    if(x >= 49 && x <= 57) return 1;
    else return 0;
}

int isZero(char x) {
    if(x == '0') return 1;
    else return 0;
}

int isPeriod(char x) {
    if(x == '.') return 1;
    else return 0;
}

int isComma(char x) {
    if(x == ',') return 1;
    else return 0;
}

int isE(char x) {
    if(x == 'e') return 1;
    else return 0;
}

int isEnd(char x) {
    if(x == '\0') return 1;
    else return 0;
}

int numberReader(char *string, int n) {
    int lastPosInt = -1;
    int lastPosDec = -1;
    int hasCommas = 0;
    int lastComma = -1;
    int currentStep = 0; // 0 => integer step, 1 => decimal step, 2 => exponential step
    for(int i = 0; i <= n; i++) {
        if(currentStep == 0) {
            if(isComma(string[i])) {
                if(i == 0) return 0;
                else if(hasCommas) {
                    if(i-lastComma == 4) {
                        lastComma = i;
                        continue;
                    }
                    else return 0;
                }
                else {
                    if(i > 3) return 0;
                    hasCommas = 1;
                    lastComma = i;
                    lastPosInt++;
                    continue;
                }
            }
            else if(isNumberNotZero(string[i])) {
                lastPosInt++;
                continue;
            }
            else if(isZero(string[i])) {
                if(n == 1 && i == 0) return 1;
                else if(n > 1) continue;
                else return 0;
            }
            else if(isPeriod(string[i]) && i > 0 && i-lastComma == 4) {
                lastPosInt++;
                lastPosDec = lastPosInt;
                currentStep = 1;
                continue;
            }
            else if(isEnd(string[i]) && i > 0 && i-lastComma == 4) {
                return 1;
            }
            else {
                return 0;
            }
        }
        else if(currentStep == 1) {
            if(isNumber(string[i])) {
                lastPosDec++;
                continue;
            }
            else if(isE(string[i]) && i > lastPosInt+1) {
                lastPosDec++;
                currentStep = 2;
                continue;
            }
            else if(isEnd(string[i]) && i > lastPosInt+1) {
                return 1;
            }
            else {
                return 0;
            }
        }
        else if(currentStep == 2) {
            if(isNumber(string[i])) {
                continue;
            }
            else if(isEnd(string[i]) && i > lastPosDec+1) {
                return 1;
            }
            else {
                return 0;
            }
        }
    }
    return 0;
}

int main() {
    
    char string[BUFFSIZE];

    FILE *f = fopen("test.txt", "r");
    fgets(string, BUFFSIZE, f);
    fclose(f);

    int n = strcspn(string, "\n");
    string[n] = '\0';
    printf("String read: %s\nWith length of: %d\n", string, n);

    int isANumber = numberReader(string, n);
    if(isANumber) {
        printf("String '%s' is a valid number\n", string);
    }
    else {
        printf("String '%s' isn't a valid number\n", string);
    }

    free(f);

    return 0;
}