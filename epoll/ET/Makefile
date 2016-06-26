CC = gcc
CFLAGS = 

all: server

server: server.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o server
