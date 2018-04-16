#include <stdlib.h>

#include "kata9.h"

int twoMoviesInFlight(int flightTime, int *moviesTime, int moviesQty) {
    int *relativeInt = calloc(1024, sizeof(int));
    
    for(int i = 0; i < moviesQty; i++) {
        relativeInt[moviesTime[i]] = 1;
    }

    for(int i = 0; i < moviesQty; i++) {
        if(moviesTime[i] < flightTime) {
            if(relativeInt[flightTime - moviesTime[i]] && relativeInt[flightTime - moviesTime[i]] != moviesTime[i]) {
                printf("Flight of duration %i has a two combination movie (%i and %i)\n", flightTime, moviesTime[i], flightTime - moviesTime[i]);
                return 1;
            }
        }
    }
    printf("Flight of duration %i doesn't has a two different combination movie\n", flightTime);
    return 0;
}

