CC = gcc
CGLAGS = 
PROG = test_list

all: $(PROG)

$(PROG): list.o test.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o $(PROG) -rf
