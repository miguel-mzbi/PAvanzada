#include "main.h"
#define r "((788)(5|1|5|0)(417))*5(2)*"
#define FILENAME "MyTest.in"

int main(int argc, char **argv) {

    FILE *file = fopen(FILENAME, "r");

    char *buffer;
    size_t bufsize = 256;
    buffer = (char *) malloc(bufsize * sizeof(char));

    char *ptr;
    getline(&buffer, &bufsize, file);

    int noCase = strtol(buffer, &ptr, 10);

    for(int i = 0; i < 5; i++) {
        getline(&buffer, &bufsize, file);
        char *substr;
        char *range1;
        char *range2;
        if(buffer != NULL) {
            int i = 0;
            while((substr = strsep(&buffer, " ")) != NULL) {
                if(i == 0) range1 = substr;
                else range2 = substr;
                i++;
            }
        }
        long r1 = strtol(range1, &ptr, 10);
        long r2 = strtol(range2, &ptr, 10);
        getline(&buffer, &bufsize, file);
        char *regex = buffer;
        regex[strlen(regex)-1] = '\0';

        NFA nfa = REGEXtoNFA(regex);

        int accepted = 0;
        for(long i = r1; i <= r2; i++) {
            char testCase[255];
            sprintf(testCase, "%ld", i);
            if(executeNFA(nfa, testCase)) accepted++;
        }
        printf("Was accepted %i times", accepted);
    }

    
    // NFA nfa = REGEXtoNFA(regex);

    // // executeNFA(nfa, "7666633837426333333");
    // // executeNFA(nfa, "34343493493339");
    // // executeNFA(nfa, "36789");
    // // executeNFA(nfa, "34545456789999");
    // // executeNFA(nfa, "345555416789");
    // fclose(file);
    return 0;
}
