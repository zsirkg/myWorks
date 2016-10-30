CC = gcc
CGLAGS =
PROG = test_hash

all: $(PROG)

$(PROG): hash_table.o test.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o $(PROG) -rf
