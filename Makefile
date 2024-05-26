CC=gcc
CFLAGS=-Wall

all: myreader

myreader: main.o reader.o 
	$(CC) main.o reader.o -o myreader

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

reader.o: reader.c
	$(CC) $(CFLAGS) -c reader.c

clean:
	rm -f *.o myreader
