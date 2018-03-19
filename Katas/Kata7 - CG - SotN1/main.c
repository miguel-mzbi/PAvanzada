#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int W; // width of the building.
    int H; // height of the building.
    scanf("%d%d", &W, &H);
    int N; // maximum number of turns before game over.
    scanf("%d", &N);
    int X0;
    int Y0;
    scanf("%d%d", &X0, &Y0);
    
    int WL = 0;
    int WR = W;
    int HU = 0;
    int HD = H;

    // game loop
    while (1) {
        char bombDir[4]; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        scanf("%s", bombDir);
        
        if(strcmp(bombDir, "U") == 0) {
            HD = Y0;
            Y0 = (HD + HU)/2;
            printf("%i %i\n", X0, Y0);
        }
        else if(strcmp(bombDir, "UR") == 0) {
            HD = Y0;
            Y0 = (HD + HU)/2;
            WL = X0;
            X0 = (WL + WR)/2;
            printf("%i %i\n", X0, Y0);
        }
        else if(strcmp(bombDir, "UL") == 0) {
            HD = Y0;
            Y0 = (HD + HU)/2;
            WR = X0;
            X0 = (WL + WR)/2;
            printf("%i %i\n", X0, Y0);
        }
        else if(strcmp(bombDir, "R") == 0) {
            WL = X0;
            X0 = (WL + WR)/2;
            printf("%i %i\n", X0, Y0);
        }
        else if(strcmp(bombDir, "L") == 0) {
            WR = X0;
            X0 = (WL + WR)/2;
            printf("%i %i\n", X0, Y0);
        }
        else if(strcmp(bombDir, "D") == 0) {
            HU = Y0;
            Y0 = (HD + HU)/2;
            printf("%i %i\n", X0, Y0);
        }
        else if(strcmp(bombDir, "DR") == 0) {
            HU = Y0;
            Y0 = (HD + HU)/2;
            WL = X0;
            X0 = (WL + WR)/2;
            printf("%i %i\n", X0, Y0);
        }
        else if(strcmp(bombDir, "DL") == 0) {
            HU = Y0;
            Y0 = (HD + HU)/2;
            WR = X0;
            X0 = (WL + WR)/2;
            printf("%i %i\n", X0, Y0);
        }
    }

    return 0;
}