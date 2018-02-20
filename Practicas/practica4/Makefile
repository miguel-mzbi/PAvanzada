LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c example.c
	 gcc -c main.c
	 gcc -o example.exe example.o main.o $(LIB)

exampletest: clean
	 gcc -c example.c
	 gcc -c exampletest.c
	 gcc -o exampletest.exe example.o exampletest.o
	 ./exampletest.exe

test:	 exampletest

clean:
	 rm *.out *.o *.exe || exit 0

example: clean
	 gcc -c example.c
	 gcc -c main.c
	 gcc -o example.exe example.o main.o $(LIB)

run: example
	 ./example.exe

runtest: example
	 ./maintest.tcl ./example.exe

