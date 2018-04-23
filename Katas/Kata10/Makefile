LIB := $(shell find ./lib -name '*.o')
clean:
	 rm *.o *.exe || exit 0

kata10: clean
	 gcc -c main.c
	 gcc -o kata10.exe main.o

run: kata10
	 ./kata10.exe chars.txt

