#include <stdio.h>
#include "operations.h"

int printTestMessage(int, char*, char*);
int testAdd(void);
int testSub(void);

int printTestMessage(int condition, char *messagePassed, char *messageFailed) {
    if(condition) {
        printf("%s\n", messagePassed);
    }
    else {
        printf("%s\n", messageFailed);
    }
    return 0;
}

int testAdd(void) {
    // Test add
    int a = 5;
    int b = 4;

    int resultAdd = add(a, b);
    int expectedAdd = a + b;
    
    return resultAdd == expectedAdd;
} 

int testSub(void) {
    // Test substraction
    int a = 5;
    int b = 4;

    int resultSub = substract(a, b);
    int expectedSub = a - b;

    return resultSub == expectedSub;
} 

int main() {
    
    printTestMessage(testAdd(),
                    "ADD test passed.",
                    "ADD test failed.");
    printTestMessage(testSub(), 
                    "SUBTRACT test passed.",
                    "SUBTRACT test failed.");

    return 0;
}