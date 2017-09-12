all: test

CFLAGS = -g -O2

test: test.o mytoc.o
	cc -o test test.o mytoc.o

mytoc.o: mytoc.c
	cc -c mytoc.c

test.o: test.c mytoc.h
	cc -c test.c
clean:
	rm -f  *.o mytoc mytoc.exe test test.exe
