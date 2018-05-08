UTILITIES = LCA.c queue.c
UTILITIES_OBJECTS = $(shell find ./ -name '*.o')

clean:
	rm *.o *.exe || exit 0

utilities: clean
	gcc -c $(UTILITIES)

LCA: utilities
	gcc -c main.c
	gcc -o LCA.exe -g $(UTILITIES_OBJECTS) main.o 

run: LCA
	./LCA.exe

