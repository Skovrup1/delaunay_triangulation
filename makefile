CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2

all: delaunay

delaunay: delaunay.o
	$(CC) $(CFLAGS) -o delaunay delaunay.o

delaunay.o: delaunay.c
	$(CC) $(CFLAGS) -c delaunay.c

clean:
	rm -f delaunay.o delaunay
