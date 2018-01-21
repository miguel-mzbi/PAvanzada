#include <stdlib.h>
#include <stdio.h>

#define SIZE 101
#define FILENAME "test.txt"

typedef struct Item {
    int index;
    int value;
    struct Item *next;
} Item;

Item* hashArray[SIZE];

int hash(int value) {
    return value % 101;
}

void insert(int index, int value) {
    
    Item *newItem = (struct Item*) malloc(sizeof(struct Item));
    newItem->index = index;
    newItem->value = value;
    newItem->next = NULL;

    int hashIndex = hash(value);

    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->value != value) {
        hashIndex = (hashIndex + 1) % 101;
    }

    if(hashArray[hashIndex] == NULL) {
        hashArray[hashIndex] = newItem;
    }
    else if(hashArray[hashIndex]->value == value) {
        hashArray[hashIndex]->next = newItem;
    } 
}

Item* search(int value) {

    int hashIndex = hash(value);

    while(hashArray[hashIndex] != NULL) {
        if(hashArray[hashIndex]->value == value) {
            Item *toReturn = hashArray[hashIndex];
            hashArray[hashIndex] = hashArray[hashIndex]->next;
            return toReturn;
        }
        hashIndex = hash(hashIndex+1);
    }

    return NULL;
}

int* anagramMap(int *A, int *B, int n) {

    for(int i = 0; i < n; i++) {
        insert(i, B[i]);
    }

    int* toReturn = malloc(sizeof(int) * n);
    
    for(int i = 0; i < n; i++) {
        Item *res = search(A[i]);
        toReturn[i] = res->index;
    }

    return toReturn;
}

int main() {
    int n;
    int *numbersA;
    int *numbersB;
    
    FILE *file = fopen(FILENAME, "r");
    fscanf(file, "%d", &n);
    numbersA = malloc(sizeof(int) * n);
    numbersB = malloc(sizeof(int) * n);
    printf("A:\n");
    for(int i = 0; i < n; i++) {
        fscanf(file, "%d", &numbersA[i]);
        printf("%d ", numbersA[i]);
    }
    printf("\nB:\n");
    for(int i = 0; i < n; i++) {
        fscanf(file, "%d", &numbersB[i]);
        printf("%d ", numbersB[i]);
    }
    fclose(file);

    int *numbersMap = anagramMap(numbersA, numbersB, n);
    printf("\nMapping:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", numbersMap[i]);
    }
    printf("\n");

    free(numbersA);
    free(numbersB);
    free(numbersMap);
    return 0;
}