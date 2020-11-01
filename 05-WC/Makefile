CC=gcc

SOURCE1 = wc-1-enum-switch.c
BIN1 = wc-1-enum-switch.exe
OBJ1 = wc-1-enum-switch.o

SOURCE2 = wc-2-goto.c
BIN2 = wc-2-goto.exe
OBJ2 = wc-2-goto.o

SOURCE3 = wl-3-rec.c
BIN3 = wl-3-rec.exe
OBJ3 = wl-3-rec.o

SOURCE4 = wl-x.c
BIN4 = wl-x.exe
OBJ4 = wl-x.o

all: $(BIN1) $(BIN2) $(BIN3) $(BIN4)

$(BIN1): $(OBJ1)
	$(CC) $(OBJ1) -o $(BIN1)
$(OBJ1): $(SOURCE1)
	$(CC) -c $(SOURCE1) -o $(OBJ1) $(CFLAGS)

$(BIN2): $(OBJ2)
	$(CC) $(OBJ2) -o $(BIN2)
$(OBJ2): $(SOURCE2)
	$(CC) -c $(SOURCE2) -o $(OBJ2) $(CFLAGS)

$(BIN3): $(OBJ3)
	$(CC) $(OBJ3) -o $(BIN3)
$(OBJ3): $(SOURCE3)
	$(CC) -c $(SOURCE3) -o $(OBJ3) $(CFLAGS)

$(BIN4): $(OBJ4)
	$(CC) $(OBJ4) -o $(BIN4)
$(OBJ4): $(SOURCE4)
	$(CC) -c $(SOURCE4) -o $(OBJ4) $(CFLAGS)
# https://opensource.com/article/18/8/what-how-makefile
# https://stackoverflow.com/questions/13919505/how-to-build-multiple-targets-from-one-makefile