#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include "student.h"

int main() {
    char *fileName = "student.dat";
    int fd = open(fileName, O_RDWR);
    int id;
    char name[20];

    Student *pAvanzada = (Student *)mmap(
        NULL,
        10 * sizeof(Student),
        PROT_READ | PROT_WRITE,
        MAP_SHARED,
        fd,
        0);

    close(fd);

    for(int i = 0; i < 4; i++) {
        printf("Give me an id and name\n");
        scanf(" %d %s", &id, name);
        strcpy(pAvanzada[id].firstName, name);
    }

    munmap(pAvanzada, 10 * sizeof(Student));
    return 0;
}