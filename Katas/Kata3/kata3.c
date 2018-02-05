#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFSIZE 1024
#define FILENAME "test.txt"


int robotTravel(char *directions, int n) {
    int horizontalC = 0, verticalC = 0;
    for(int i = 0; i < n; i++) {
        if(directions[i] == 'U') {
            verticalC++;
        }
        else if(directions[i] == 'D') {
            verticalC--;
        }
        else if(directions[i] == 'R') {
            horizontalC++;
        }
        else if(directions[i] == 'L') {
            horizontalC--;
        }
    }

    if(horizontalC == 0 && verticalC == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    
    char directions[BUFFSIZE];

    FILE *f = fopen("test.txt", "r");
    fgets(directions, BUFFSIZE, f);
    fclose(f);

    int n = strcspn(directions, "\n");
    directions[n] = 0;
    printf("String read: %s\nWith length of: %d\n", directions, n);

    int isAtOrigin = robotTravel(directions, n);
    if(isAtOrigin) {
        printf("Robot returned to origin\n");
    }
    else {
        printf("Robot didn't returned to origin\n");
    }

    free(f);

    return 0;
}