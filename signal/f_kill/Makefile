CC = gcc
CFLAGS = 
PROG = kill 

all: $(PROG)

$(PROG): kill.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o $(PROG) -rf
