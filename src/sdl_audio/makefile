
CC=gcc

SDL_DIR=${HOME}/SDL2
SDLLIB_DIR=${SDL_DIR}/lib
SDLINC_DIR=${SDL_DIR}/include

LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2main
INCLUDES=-I${SDLINC_DIR} 

PROG=sdl_audio

all: sdl_text

sdl_text: sdl_audio.c
	${CC} -o ${PROG} sdl_audio.c ${LIBS} ${INCLUDES}

clean: 
	rm -f ${PROG}
	rm -f *.o


