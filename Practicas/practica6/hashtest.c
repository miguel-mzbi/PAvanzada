#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minunit.h"
#include "hash.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\033[0m"

int testsRun = 0;

unsigned hash(void *key, unsigned size) {
  return 0;
}

unsigned hash2(void *key, unsigned size) {
  unsigned char *str = (unsigned char *)key;
  unsigned hash = 5381;
  int c;
  while(c = *str++) {
    hash = ((hash << 5) + hash) + c;
  }
  return hash % size;
}

void * copy(void *element) {
  char *realVal = (char *)element;
  return (void *)strdup(realVal);
}

int cmpKeys(void *e1, void *e2) {
  return strcmp((char *)e1, (char *)e2);
}

static char * testInit() {
  Hash myHash;
  unsigned size = 20;
  initHash(&myHash, size, hash, cmpKeys, copy, copy);
  muAssert("error, hash size musy be 20", myHash.size == size);
  muAssert("error, hash() must be 0", myHash.hash(NULL, 0) == 0);
  muAssert("error, data mustn't be NULL", myHash.data != NULL);
  return 0;
}

static char * testInsert() {
  Hash myHash;
  unsigned size = 4;
  char *key = "Hello";
  char *value = "Hola";
  initHash(&myHash, size, hash, cmpKeys, copy, copy);
  insertHash(&myHash, (void *)key, (void *)value);
  muAssert("error, data[0].elements[0].key", strcmp(myHash.data[0].elements[0].key, key) == 0);
  muAssert("error, data[0].elements[0].value", strcmp(myHash.data[0].elements[0].value, value) == 0);
  return 0;
}

static char * testGet() {
  Hash myHash;
  unsigned size = 4;
  char *key = "Hello";
  char *value = "Hola";
  initHash(&myHash, size, hash, cmpKeys, copy, copy);
  insertHash(&myHash, (void *)key, (void *)value);
  void * hashValue = (char *)getHash(&myHash, "Hello");
  void * hashValue2 = (char *)getHash(&myHash, "Adios");
  muAssert("error, Must be hola", strcmp(hashValue, value) == 0);
  muAssert("error,Must be NULL", hashValue2 == NULL);
  return 0;
}

static char * testFull() {
  Hash myHash;
  unsigned size = 10;
  char key[size];
  char value[size];
  initHash(&myHash, size, hash, cmpKeys, copy, copy);
  for(int i = 0; i < 2 * size; i++) {
    sprintf(key, "Hello%d", i);
    sprintf(value, "Hola%d", i);
    insertHash(&myHash, (void *)key, (void *)value);
  }
  void * hashValue = (char *)getHash(&myHash, "Hello15");
  void * hashValue2 = (char *)getHash(&myHash, "Adios");
  muAssert("error, Must be hola", strcmp(hashValue, "Hola15") == 0);
  muAssert("error,Must be NULL", hashValue2 == NULL);
  return 0;
}

static char * allTests() {
  muRunTest(testInit);
  muRunTest(testInsert);
  muRunTest(testGet);
  muRunTest(testFull);
  return 0;
}

int main(int argc, char **argv) {
  char *result = allTests();
  if (result != 0) {
    printf("-_-_-_-_-_-_-_,------,      o \n");
    printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");
    printf("-_-_-_-_-_-_-~|__( X .X)  +     + \n");
    printf("_-_-_-_-_-_-_- \"\"  \"\" \n");
    printf(KRED "✗ %s \n" RESET, result);
  }
  else {
    printf("-_-_-_-_-_-_-_,------,      o \n");
    printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");
    printf("-_-_-_-_-_-_-~|__( ^ .^)  +     + \n");
    printf("_-_-_-_-_-_-_-  \"\"  \"\" \n");
    printf(KGRN " ✓ ALL TESTS PASSED \n" RESET);
  }
  printf("Tests run: %d\n", testsRun);
  return result != 0;
}
