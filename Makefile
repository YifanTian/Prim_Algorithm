CC = g++

CFLAGS=-c -Wall


all: Prim

prim: Prim.o
	$(CC) Prim.o -o Prim

prim.o: Prim.cpp
	$(CC) $(CFLAGS) Prim.cpp

clean:
	rm -rf *o prim
