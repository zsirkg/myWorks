CC = gcc
CFLAGS = 
PROG = signal

all: $(PROG)

$(PROG): signal.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o $(PROG) -rf
