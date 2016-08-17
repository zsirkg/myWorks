CC = gcc
CGLAGS = 
PROG = test_tree

all: $(PROG)

$(PROG): tree.o test.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o $(PROG) -rf
