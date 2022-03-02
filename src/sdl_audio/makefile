CC=gcc
FLAGS=-Wall -g

PROG=audio
PROG_F=source/audio.c source/prog_audio_test.c

all: main

main: source/audio.c source/prog_audio_test.c
	${CC} -o ${PROG} ${PROG_F} -lSDL2main -lSDL2_image -lSDL2_ttf -lSDL2 -lSDL2_mixer

clean: 
	rm -f ${PROG}
	rm -f *.o
