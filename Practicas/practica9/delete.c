#include <stdio.h>
#include <string.h>

struct Student {
    char firstName[20];
    char lastName[20];
    short id;
    char semester[3];
    char free;
} typedef Student;

int main(int argc, char **argv) {
    char *dbName = "student.dat";
    Student myStudent;
    char *searchName = argv[1];

    FILE *data = fopen(dbName, "r+b");
    while(1) {
        if(feof(data)) break;
        fread(&myStudent, sizeof(Student), 1, data);
        if(myStudent.free == 1) continue;
        if(!strcmp(myStudent.firstName, searchName)) {
            myStudent.free = 1;
            fseek(data, -1*sizeof(Student), SEEK_CUR);
            fwrite(&myStudent, sizeof(Student), 1, data);
        }
    }
    fclose(data);
    return 0;
}