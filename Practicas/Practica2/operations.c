#include <assert.h>
#include "operations.h"

#define MAX_INT 2147483647

/* 
Function to add two numbers, x and y
*/
int add(int x, int y) {
    // Do the addition and check if there is an overflow
    long c = (long) x + y;
    assert(c < MAX_INT && c > -MAX_INT);
    return (int) c;
}

/* 
Function to substract two numbers, x and y
*/
int substract(int x, int y) {
    // Do the addition and check if there is an overflow
    long c = (long) x - y;
    assert(c < MAX_INT && c > -MAX_INT);
    return (int) c;
}