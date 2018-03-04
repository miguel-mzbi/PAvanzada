#include <stdlib.h>
#include <stdio.h>
#include "hash.h"

void initHash(Hash *myHash,
            unsigned size,
            unsigned (*hash)(void *, unsigned),
            int (*cmpKeys)(void *, void *),
            void *(*copyKey)(void *),
            int *(*copyValue)(int *)) {
    myHash->size = size;
    myHash->hash = hash;
    myHash->data = (Vector *)calloc(size, sizeof(Vector));
    myHash->cmpKeys = cmpKeys;
    myHash->copyKey = copyKey;
    myHash->copyValue = copyValue;
};

int * getVal(Hash *myHash, void *key) {
    unsigned pos = myHash->hash(key, myHash->size);
    for(int i = 0; i < myHash->data[pos].count; i++) {
        if(myHash->cmpKeys(key, myHash->data[pos].elements[i].key) == 0) {
            return myHash->data[pos].elements[i].value;
        }
    }
    return NULL;
}

void insert(Hash *myHash, void *key, int *value) {
    unsigned pos = myHash->hash(key, myHash->size);
    if(getVal(myHash, key) != NULL) {
        // INCREMENT!
        for(int i = 0; i < myHash->data[pos].count; i++) {
            if(myHash->cmpKeys(key, myHash->data[pos].elements[i].key) == 0) {
                *myHash->data[pos].elements[i].value = *myHash->data[pos].elements[i].value +1;
            }
        }
        return;
    }
    else {
        if(myHash->data[pos].size == 0) {
        myHash->data[pos].count = 0;
        myHash->data[pos].size = 2;
        myHash->data[pos].elements = (Element *)malloc(2 * sizeof(Element));
        }
        if(myHash->data[pos].size == myHash->data[pos].count) {
            myHash->data[pos].size *= 2;
            myHash->data[pos].elements = (Element *)realloc(myHash->data[pos].elements, myHash->data[pos].size * sizeof(Element));
        }
        unsigned elementPos = myHash->data[pos].count;
        myHash->data[pos].elements[elementPos].key = myHash->copyKey(key);
        myHash->data[pos].elements[elementPos].value = myHash->copyValue(value);
        myHash->data[pos].count++;
        return;
    }
}

void printTable(Hash *myHash) {
    printf("PRINTING TABLE~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    for(int i = 0; i < myHash->size; i++) {
        if(myHash->data[i].size == 0) continue;
        printf("\nBUCKET NUMBER %i ~~~~~~~~~~~~~~~~\n", i);
        Vector bucket = myHash->data[i];
        for(int j = 0; j < bucket.count; j++) {
            Element element = bucket.elements[j];
            printf("Word: %s\t Qty: %i\n", (char *)element.key, *element.value);
        }
    }
}