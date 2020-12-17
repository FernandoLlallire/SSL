SOURCE = calc.c scanner.c parser.c
BIN = calc.exe
OBJ = calc.o scanner.o parser.o
CC = gcc
CFLAGS = -std=c18 -g
RM = rm -f

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN) $(CFLAGS)

$(OBJ): $(SOURCE)
	$(CC) -c $(SOURCE) $(CFLAGS)
	
test: $(BIN)
	./$(BIN) < test
# https://opensource.com/article/18/8/what-how-makefile
# https://stackoverflow.com/questions/13919505/how-to-build-multiple-targets-from-one-makefile