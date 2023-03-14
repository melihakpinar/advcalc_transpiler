
.PHONY = all clean

CC = gcc

SRCS = ./src/main.c
EXEC = advcal

all:
# if executable exists, remove it
	@if [ -f $(EXEC) ]; then rm $(EXEC); fi
	@ $(CC) $(SRCS) -o $(EXEC)

clean:
	@ rm $(EXEC)