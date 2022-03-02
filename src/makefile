CC=gcc
FLAGS=-Wall -g


PROG=bin/main
PROG_F=src/main.c

all: main

main: src/main.c
	${CC} -o ${PROG} ${PROG_F} -lSDL2main -lSDL2_image -lSDL2_ttf -lSDL2

clean: 
	rm -f ${PROG}
	rm -f *.o
