CC=gcc
CFLAGS=-g -Wall -O3
LDLIBS=
CFILE=heapsort.c

all: $(CFILE)
	$(CC) -c $(CFILE)

clean:
	rm *.o

