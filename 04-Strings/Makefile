CC=gcc
CFLAGS=-I.
DEPS = String.h
OBJ = String.o StringTest.o 
BIN = StringTest

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BIN): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

## https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/