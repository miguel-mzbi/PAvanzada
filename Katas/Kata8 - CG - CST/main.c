#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int boostAv = 1;
    // game loop
    while (1) {
        int x;
        int y;
        int nextCheckpointX; // x position of the next check point
        int nextCheckpointY; // y position of the next check point
        int nextCheckpointDist; // distance to the next checkpoint
        int nextCheckpointAngle; // angle between your pod orientation and the direction of the next checkpoint
        int thrust;
        int willBoost = 0;
        scanf("%d%d%d%d%d%d", &x, &y, &nextCheckpointX, &nextCheckpointY, &nextCheckpointDist, &nextCheckpointAngle);
        int opponentX;
        int opponentY;
        scanf("%d%d", &opponentX, &opponentY);
        
        if(nextCheckpointAngle > 90 || nextCheckpointAngle < -90) {
            thrust = 0;
        }
        else if(nextCheckpointDist < 600) {
            thrust = 25;
            if(nextCheckpointAngle > 45 || nextCheckpointAngle < -45) {
                thrust = 12;
            }
        }
        else if(nextCheckpointDist < 900) {
            thrust = 50;
            if(nextCheckpointAngle > 45 || nextCheckpointAngle < -45) {
                thrust = 25;
            }
        }
        else if(nextCheckpointDist < 1300) {
            thrust = 75;
            if(nextCheckpointAngle > 45 || nextCheckpointAngle < -45) {
                thrust = 38;
            }
        }
        else if(nextCheckpointDist > 2000 
                && boostAv 
                && (nextCheckpointAngle < 30 && nextCheckpointAngle > -30)) {
            willBoost = 1;
            boostAv = 0;
        }
        else {
            thrust = 100;
        }

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
        if(willBoost) {
            printf("%d %d %s\n", nextCheckpointX, nextCheckpointY, "BOOST");
        }
        else {
            printf("%d %d %d\n", nextCheckpointX, nextCheckpointY, thrust);
        }

        // You have to output the target position
        // followed by the power (0 <= thrust <= 100)
        // i.e.: "x y thrust"
    }

    return 0;
}