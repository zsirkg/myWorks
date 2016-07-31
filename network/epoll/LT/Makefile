CC = gcc
CFLAGS = 
PROG = server

all: $(PROG)

$(PROG): server.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o $(PROG)
