CC = gcc
CFLAGS = 
PROG = sigaction

all: $(PROG)

$(PROG): sigaction.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o $(PROG) -rf
