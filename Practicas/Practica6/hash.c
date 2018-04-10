#include <stdlib.h>
#include <stdio.h>
#include "hash.h"

void initHash(Hash *myHash,
            unsigned size,
            unsigned (*hash)(void *, unsigned),
            int (*cmpKeys)(void *, void *),
            void *(*copyKey)(void *),
            void *(*copyValue)(void *)) {
    myHash->size = size;
    myHash->hash = hash;
    myHash->data = (Vector *)calloc(size, sizeof(Vector));
    myHash->cmpKeys = cmpKeys;
    myHash->copyKey = copyKey;
    myHash->copyValue = copyValue;
};

void insertHash(Hash *myHash, void *key, void *value) {
    unsigned pos = myHash->hash(key, myHash->size);
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
    myHash->data[pos].elements[elementPos].key = myHash->copyValue(key);
    myHash->data[pos].elements[elementPos].value = myHash->copyValue(value);
    myHash->data[pos].count++;
    return;
}

void * getHash(Hash *myHash, void *key) {
    unsigned pos = myHash->hash(key, myHash->size);
    for(int i = 0; i < myHash->data[pos].count; i++) {
        if(myHash->cmpKeys(key, myHash->data[pos].elements[i].key) == 0) {
            return myHash->copyValue(myHash->data[pos].elements[i].value);
        }
    }
    return NULL;
}