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
    char *updateName = argv[2];

    FILE *data = fopen(dbName, "r+b");
    while(1) {
        if(feof(data)) break;
        fread(&myStudent, sizeof(Student), 1, data);
        if(!strcmp(myStudent.firstName, searchName)) {
            strcpy(myStudent.firstName, updateName);
            fseek(data, -1*sizeof(Student), SEEK_CUR);
            fwrite(&myStudent, sizeof(Student), 1, data);
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