.PHONY = all clean

CC = gcc
CFLAGS = -Wall
SRC = src
OBJ = obj
BIN = bin
SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
BINS = $(patsubst $(SRC)/%.c, $(BIN)/%, $(SRCS))

all: pre-build main-build

pre-build:
	if [ ! -d "$(OBJ)" ]; then mkdir -v "$(OBJ)"; fi
	if [ ! -d "$(BIN)" ]; then mkdir -v "$(BIN)"; fi

main-build: ansi_escapes.o core.o hanoi

ansi_escapes.o: $(SRC)/ansi_escapes.c $(SRC)/ansi_escapes.h
	$(CC) $(CFLAGS) -o $(OBJ)/ansi_escapes.o -c $(SRC)/ansi_escapes.c

core.o: $(SRC)/core.c $(SRC)/core.h
	$(CC) $(CFLAGS) -o $(OBJ)/core.o -c $(SRC)/core.c

hanoi: $(SRC)/hanoi.c $(OBJ)/ansi_escapes.o $(OBJ)/core.o
	${CC} $(CFLAGS) -o $(BIN)/$@ $^
	$(BIN)/$@

clean:
	@echo "Cleaning up..."
	@rm -rvf ${BINS} ${OBJS} $(SRC)/*.o