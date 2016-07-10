CC = gcc
CFLAGS = 
PROG = stack_test
OBJ = stack.o test.o

all: $(PROG)

$(PROG): $(OBJ) 
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm $(PROG) $(OBJ) -rf

