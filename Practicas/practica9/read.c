#include <stdio.h>
#include <string.h>

struct Student {
    char firstName[20];
    char lastName[20];
    short id;
    char semester[3];
} typedef Student;

int main(int argc, char **argv) {
    char *dbName = "student.dat";
    Student myStudent;
    char *searchName = argv[1];

    FILE *data = fopen(dbName, "rb");
    while(1) {
        if(feof(data)) break;
        fread(&myStudent, sizeof(Student), 1, data);
        if(!strcmp(myStudent.firstName, searchName)) {
            printf("Student info:\n");
            printf("First name: %s\n", myStudent.firstName);
            printf("Last name: %s\n", myStudent.lastName);
            printf("ID: %i\n", myStudent.id);
            printf("Semester: %s\n", myStudent.semester);
        }
    }
    fclose(data);
    return 0;
}