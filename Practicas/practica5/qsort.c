#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "qsort.h"

static int compareById(const void *element1, const void *element2) {
    Student *student1 = (Student *) element1;
    Student *student2 = (Student *) element2;
    return student1->id - student2->id;
}

void sortById(Student * class, int numElements) {
    qsort((void *) class, (size_t) numElements, (size_t) sizeof(Student), compareById);
}

static int compareByName(const void *element1, const void *element2) {
    Student *student1 = (Student *) element1;
    Student *student2 = (Student *) element2;
    return strcmp(student1->name, student2->name);
}

void sortByName(Student * class, int numElements) {
    qsort((void *) class, (size_t) numElements, (size_t) sizeof(Student), compareByName);
}
