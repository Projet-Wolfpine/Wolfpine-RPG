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

include=include/
src=src/
prog=../bin/prog 
obj=obj/
lib=../lib/
ncurse=-lncurses
fichierc=main.c menu_principal.c affichage_sdl.c fonction_sdl.c game.c gestion_deplacement_sdl.c creation_map.c combat.c deplacement.c inventory.c spells.c audio.c
fichierh=${lib}menu_principal.h ${lib}affichage_sdl.h ${lib}fonction_sdl.h ${lib}game.h ${lib}gestion_deplacement_sdl.h ${lib}creation_map.h ${lib}structures.h ${lib}combat.h ${lib}deplacement.h ${lib}inventory.h ${lib}spells.h ${lib}audio.h


all:clean main

main: ${fichierc} ${fichierh}
	${CC} -o ${prog} ${fichierc} ${fichierh} ${LIBS} ${INCLUDES} 


PATH:
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$HOME/SDL2/lib

clean: 
	rm -f ${src}*.o
	rm -f ${include}*.o
	rm -f *.o
	rm -f ${prog}
