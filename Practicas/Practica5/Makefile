LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c qsort.c
	 gcc -c main.c
	 gcc -o qsort.exe qsort.o main.o $(LIB)

qsorttest: clean
	 gcc -c qsort.c
	 gcc -c qsorttest.c
	 gcc -o qsorttest.exe qsort.o qsorttest.o
	 ./qsorttest.exe

test:	 qsorttest

clean:
	 rm *.out *.o *.exe || exit 0

qsort: clean
	 gcc -c qsort.c
	 gcc -c main.c
	 gcc -o qsort.exe qsort.o main.o $(LIB)

run: qsort
	 ./qsort.exe

runtest: qsort
	 ./maintest.tcl ./qsort.exe

