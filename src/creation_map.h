#include "deplacement.h"

void lecture_fichier_map(char nom_fichier[20],int map_int[Y][X]);
void mise_struct_map(case_t map_info[Y][X], int map_int[Y][X]);
void afficher_map(char * nom_map,int taille, case_t map_info[Y][X]);