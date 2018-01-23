#include <stdio.h>
#include <string.h>
#include "operations.h"
#include "messages.h"

#define MAX_STRING_LENGTH 100
#define LANG "en"

typedef struct {
    char *operationName;
    int(* operation) (int, int);
} Operation;

int main() {
    char operation[MAX_STRING_LENGTH];
    int operatorOne, operatorTwo;
    const char **messages;

    if(!strcmp(LANG, "en")) {
        messages = message_ENG;
    }
    else if(!strcmp(LANG, "es")) {
        messages = message_ESP;
    }

    printf("%s\n", messages[0]);
    scanf("%s", operation);
    scanf("%d %d", &operatorOne, &operatorTwo);

    if(!strcmp(operation, "add")) {
        printf("%s: %d\n", messages[2], add(operatorOne, operatorTwo));
    }
    else if(!strcmp(operation, "substract")){
        printf("%s: %d\n", messages[2], substract(operatorOne, operatorTwo));
    }
    else {
        printf("%s\n", messages[1]);  
    }

    return 0;
}