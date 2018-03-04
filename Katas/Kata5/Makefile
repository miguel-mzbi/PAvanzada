clean:
	 rm *.o *.exe || exit 0

hash: clean
	 gcc -c hash.c
	 gcc -c main.c
	 gcc -o hash.exe hash.o main.o -g

run: hash
	 ./hash.exe
