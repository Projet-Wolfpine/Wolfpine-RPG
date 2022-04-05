CC=gcc
CCO=gcc
FLAGS=-Wall -g
SDL_DIR=lib/SDL2
EXECU_DIR=bin
SDL_DIR=${HOME}/SDL2
SDLLIB_DIR=${SDL_DIR}/lib
SDLINC_DIR=${SDL_DIR}/include
SDL_DIR=${HOME}/SDL2
LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image -lm
INCLUDES=-I${SDLINC_DIR} 

INCLUDE=include/
SRC=src/
PROG=../bin/prog 
OBJ=obj/
LIB=../lib/
NCURSE=-lncurses

FICHIERC=main.c menu_principal.c affichage_sdl.c fonction_sdl.c game.c gestion_deplacement_sdl.c creation_map.c combat.c deplacement.c inventory.c spells.c audio.c 

FICHIERH=${LIB}menu_principal.h ${LIB}affichage_sdl.h ${LIB}fonction_sdl.h ${LIB}game.h ${LIB}gestion_deplacement_sdl.h ${LIB}creation_map.h ${LIB}structures.h ${LIB}combat.h ${LIB}deplacement.h ${LIB}inventory.h ${LIB}spells.h ${LIB}audio.h


all:clean main

main: ${FICHIERC} ${FICHIERH}
	${CC} -o ${PROG} ${FICHIERC} ${FICHIERH} ${LIBS} ${INCLUDES} 
	
PATH:
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$HOME/SDL2/lib

clean: 
	rm -f ${SRC}*.o
	rm -f ${INCLUDE}*.o
	rm -f *.o
	rm -f ${prog}
