CC = gcc
CGLAGS = 
PROG = test_queue

all: $(PROG)

$(PROG): queue.o test.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o $(PROG) -rf
