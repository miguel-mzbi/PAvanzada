#include <stdio.h>

struct Student {
    char firstName[20];
    char lastName[20];
    short id;
    char semester[3];
} typedef Student;

int main() {
    char *dbName = "student.dat";
    Student pAvanzada[10];

    for(int i = 0; i < 10; i++) {
        sprintf(pAvanzada[i].firstName, "name%i", i);
        sprintf(pAvanzada[i].lastName, "lastname%i", i);
        pAvanzada[i].id = i;
        sprintf(pAvanzada[i].semester, "S%i", 8);
    }

    FILE *data = fopen(dbName, "wb");
    fwrite(pAvanzada, sizeof(Student), 10, data);
    fclose(data);
    return 0;
}