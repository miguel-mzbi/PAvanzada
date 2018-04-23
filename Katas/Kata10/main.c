#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int 	mask1      	= 0x80, result1 	= 0x00, 
				mask2      	= 0xe0, result2     = 0xc0,
				mask3      	= 0xf0, result3     = 0xe0,
				mask4		= 0xf8, result4     = 0xf0,
				maskByte	= 0xc0, resultByte	= 0x80;


int valid1(unsigned int c) {
	if((c & mask1) == result1) {
		return 1;
	}
	else {
		return 0;
	}
}

int valid2(unsigned int c) {
	if((c & mask2) == result2) {
		return 1;
	}
	else {
		return 0;
	}
}

int valid3(unsigned int c) {
	if((c & mask3) == result3) {
		return 1;
	}
	else {
		return 0;
	}
}

int valid4(unsigned int c) {
	if((c & mask4) == result4) {
		return 1;
	}
	else {
		return 0;
	}
}

int validByte(unsigned int c) {
	if((c & maskByte) == resultByte) {
		return 1;
	}
	else {
		return 0;
	}
}

int validUtf8(unsigned int* numbers, int n) {

	
	for(int j = 0; j < n; j++) {
		
		int extraBytes = 0;
		
		if(valid1(numbers[j])) {
			continue;
		}
		else if(valid2(numbers[j])) {
			extraBytes = 1;
		}
		else if(valid3(numbers[j])) {
			extraBytes = 2;
		}
		else if(valid4(numbers[j])) {
			extraBytes = 3;
		}
		else {
			return 0;
		}
		for(int i = 1; i <= extraBytes; i++) {
			if(validByte(numbers[j+i])) {
				continue;
			}
			else {
				return 0;
			}
		}
		j += extraBytes;
	}

	return 1;
}

int main(int argc, char **argv) {

	FILE *file = fopen(argv[1], "r");

	char *buffer;
    size_t bufsize = 256;
    buffer = (char *) malloc(bufsize * sizeof(char));

    char *ptr;
    getline(&buffer, &bufsize, file);

    int noElements = strtol(buffer, &ptr, 10);
	unsigned int numbers[noElements];

	getline(&buffer, &bufsize, file);
	char *substr;
	if(buffer != NULL) {
		int i = 0;
		while((substr = strsep(&buffer, " ")) != NULL) {
			numbers[i] = strtol(substr, &ptr, 10);
			i++;
		}
	}
	if(validUtf8(numbers, noElements)) {
		printf("CORRECT\n");
	}
	else {
		printf("INCORRECT\n");
	}
}
