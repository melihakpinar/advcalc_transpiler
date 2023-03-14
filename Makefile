
CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c99 -lm

SRC = $(wildcard ./src/*/*.c)
EXEC = advcalc
INC = -I./src/lib

all: $(SRC)
	@ if [ -f $(EXEC) ]; then rm $(EXEC); fi
	@ $(CC) $(CFLAGS) $(SRC) -o $(EXEC) $(INC)

clean:
	@ rm $(EXEC)