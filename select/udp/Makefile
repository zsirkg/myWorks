CC=gcc
CFLAGS=

all: server client

server: server.o
	$(CC) -o $@ $< $(CFLAGS)

client: client.o
	$(CC) -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o server client
