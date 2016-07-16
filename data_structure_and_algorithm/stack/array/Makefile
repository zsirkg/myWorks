CC = gcc
CFLAGS = 
PROG = test_stack
OBJ = stack.o test.o

all: $(PROG)

$(PROG): $(OBJ) 
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm $(PROG) $(OBJ) -rf

