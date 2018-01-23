#include <stdio.h>
#include <string.h>
#include "operations.h"

#define MAX_STRING_LENGTH 100

int main() {
    char operation[MAX_STRING_LENGTH];
    int operatorOne, operatorTwo;
    char *operationMessage = "What is the operation?";

    printf("%s\n", operationMessage);
    scanf("%s", operation);
    scanf("%d %d", &operatorOne, &operatorTwo);

    if(!strcmp(operation, "add")) {
        printf("Result: %d\n", add(operatorOne, operatorTwo));
    }
    else if(!strcmp(operation, "substract")){
        printf("Result: %d\n", substract(operatorOne, operatorTwo));
    }
    else {
        printf("%s\n", "Operation not implemented");  
    }
    return 0;
}