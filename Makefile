
CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11 -lm

SRC = $(wildcard ./src/*/*.c)
EXEC = advcalc
INC = -I./src

all:
	@ $(clean)
	@ $(CC) $(CFLAGS) $(SRC) -o $(EXEC) $(INC)

clean:
	@ if [ -f $(EXEC) ]; then rm $(EXEC); fi
