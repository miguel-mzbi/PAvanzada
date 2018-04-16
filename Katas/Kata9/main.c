#include <stdlib.h>
#include <stdio.h>
#include "kata9.h"

/* Add function signatures here */

int main(int argc, char **argv) {
	/* Start your code here */

	char *buffer;
	size_t bufsize = 256;
	buffer = (char *) malloc(bufsize * sizeof(char));
	char *ptr;
	
	FILE *moviesFile = fopen(argv[2], "r");
	getline(&buffer, &bufsize, moviesFile);
	int moviesQty = strtol(buffer, &ptr, 10);

	int *moviesTime = malloc(moviesQty * sizeof(int));
	for(int i = 0; i < moviesQty; i++) {
		getline(&buffer, &bufsize, moviesFile);
		if(buffer != NULL) {
			moviesTime[i] = strtol(buffer, &ptr, 10);
		}
		else {
			moviesTime[i] = -1;
		}
	}

	fclose(moviesFile);

	FILE *flightsFile = fopen(argv[1], "r");
	getline(&buffer, &bufsize, flightsFile);
	int flightsQty = strtol(buffer, &ptr, 10);

	for(int i = 0; i < flightsQty; i++) {
		getline(&buffer, &bufsize, flightsFile);
		if(buffer != NULL) {
			int flightDuration = strtol(buffer, &ptr, 10);
			twoMoviesInFlight(flightDuration, moviesTime, moviesQty);
		}
		else {
			printf("ERROR ON LINE\n");
		}
	}

	fclose(flightsFile);

	return 0;
}
