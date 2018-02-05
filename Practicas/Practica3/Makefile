all:
	gcc main.c -o out

main.o: main.c
	gcc -c main.c

runtest: main.o
	gcc main.c -o out
	./testmain.tcl ./out