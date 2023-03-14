
.PHONY = all clean

CC = gcc

SRCS = ./src/main.c
EXEC = advcal

all: 
	$(CC) $(SRCS) -o $(EXEC)

clean:
	rm $(EXEC)