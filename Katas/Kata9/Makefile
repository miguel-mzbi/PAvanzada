LIB := $(shell find ./lib -name '*.o')
clean:
	 rm *.o *.exe || exit 0

kata9: clean
	 gcc -c kata9.c
	 gcc -c main.c
	 gcc -o kata9.exe kata9.o main.o $(LIB)

run: kata9
	 ./kata9.exe flights.txt movies.txt

