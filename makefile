CC=g++
CFLAGS=-I.
DEPS = csc160.h
OBJ = csc160.o hw11.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hw11: $(OBJ)
	$(CC) -o $@ csc160.o hw11.o $(CFLAGS)

all: hw11

clean:
	rm -f *.o hw11
