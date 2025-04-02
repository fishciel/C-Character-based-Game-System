CC = g++
DEBUG = -g

CFLAGS = -std=c++17 -Wall

PROG3 = BST.o Character.o main.o

all: a.out

a.out: $(PROG3)
	$(CC) $(CFLAGS) $(PROG3) -o a.out


BST.o: BST.cpp BST.h
	$(CC) $(CFLAGS) -c BST.cpp

Character.o: Character.cpp Character.h
	$(CC) $(CFLAGS) -c Character.cpp

main.o: main.cpp BST.h Character.h
	$(CC) $(CFLAGS) -c main.cpp

zip:
	zip -9 cs302-002-program-trieu.zip *h *.cpp README ?akefile

clean:
	rm -f $(PROG3) a.out
