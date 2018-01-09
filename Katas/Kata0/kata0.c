#include <stdlib.h>
#include <stdio.h>

#define SIZE 100

struct Item {
    int index;
    int value;
};

struct Item* hashArray[SIZE];

int hash(int value) {
    return value % SIZE;
}

void insert(int index, int value) {
    
    struct Item* item = (struct Item*) malloc(sizeof(struct Item));
    item->index = index;
    item->value = value;

    int hashIndex = hash(value);

    while(hashArray[hashIndex] != NULL) {
        hashIndex = (hashIndex + 1) % SIZE;
    }

    hashArray[hashIndex] = item;
}

struct Item* search(int value) {

    int hashIndex = hash(value);

    while(hashArray[hashIndex] != NULL) {
        if(hashArray[hashIndex]->value == value)
            return hashArray[hashIndex];
        hashIndex = (hashIndex + 1) % SIZE;
    }

    return NULL;
}

int* twoSum(int* nums, int numsSize, int target) {

    for(int i = 0; i < numsSize; i++) {
        insert(i, nums[i]);
    }

    int* toReturn = malloc(sizeof(int) * 2);
    toReturn[0] = -1;
    toReturn[1] = -1;

    for(int i = 0; i < numsSize; i++) {
        struct Item* result = search(target - nums[i]);
        if(result != NULL) {
            toReturn[0] = i;
            toReturn[1] = result->index;
            break;
        }
    }

    return toReturn;
}

int main() {

    int n[] = {3, 5, 19, 7, 10, 8, 17};
    int target = 29;

    int* res = twoSum(n, sizeof(n)/sizeof(int), target);
    if(res[0] != -1) {
        printf("Index %d and %d\n", res[0], res[1]);
    }
    else {
        printf("-1\n");
    }
}