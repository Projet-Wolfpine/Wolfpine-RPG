CC=gcc
CCO=gcc
FLAGS=-Wall -g
SDL_DIR=lib/SDL2
EXECU_DIR=bin
SDL_DIR=${HOME}/SDL2
SDLLIB_DIR=${SDL_DIR}/lib
SDLINC_DIR=${SDL_DIR}/include
SDL_DIR=${HOME}/SDL2
LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image
INCLUDES=-I${SDLINC_DIR} 

include=include/
src=src/
prog=bin/prog 
obj=obj/
ncurse=-lncurses
fichierc=main.c menu_principal.c commun.c affichage_sdl.c fonction_sdl.c deplacement.c game.c gestion_deplacement_sdl.c creation_map.c 
fichierh=menu_principal.h commun.h affichage_sdl.h fonction_sdl.h deplacement.h game.h gestion_deplacement_sdl.h creation_map.h 

PROG=prog

all:clean main

main: ${fichierc} ${fichierh}
	${CC} -o ${PROG} ${fichierc} ${fichierh} ${LIBS} ${INCLUDES} 


PATH:
	export LD_LIBRARY_PATH="${HOME}/SDL2/lib"

clean: 
	rm -f ${src}*.o
	rm -f ${include}*.o
	rm -f *.o
	rm -f ${prog}
