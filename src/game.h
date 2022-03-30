/*
#include "creation_map.h"
#include "combat.h"
#include "string.h"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "fonction_sdl.h"
#include "gestion_deplacement_sdl.h"
#include "menu_principal.h"
#include "deplacement.h"
*/
#define Y 16
#define X 30
void start();
void map();
void lecture_fichier_map(char nom_fichier[20],int map_int[Y][X]);
//char * info_case(case_t mat[Y][X] , int coord_y, int coord_x);
//void sauvegarder_jeu (case_t mat[Y][X],perso_t *perso, char * nom_map);
//void charger_jeu (case_t mat[Y][X], perso_t *perso,char * nom_map);