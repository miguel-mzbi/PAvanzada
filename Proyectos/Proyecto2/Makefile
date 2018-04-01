UTILITIES = VertexArray.c TransitionsArray.c NFAArray.c CharArray.c
MAIN_UTILITIES = ThompsonBuild.c NFAExecution.c
UTILITIES_OBJECTS = $(shell find ./ -name '*.o')

clean:
	rm *.o *.exe || exit 0

utilities: clean
	gcc -c $(UTILITIES)
	gcc -c $(MAIN_UTILITIES)

Thompson: utilities
	gcc -c main.c
	gcc -o Thompson.exe -g $(UTILITIES_OBJECTS) main.o 

run: Thompson
	./Thompson.exe

