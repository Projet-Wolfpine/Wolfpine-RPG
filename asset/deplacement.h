#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structures.h"

//Lors du parcours de matrice puisque que les premiers crochet correspondes à la vertical et pas l'horizontal il faudra commencer par mettre les coordonnés Y puis X pour les fonctions
#define Y 16
#define X 30

void init_mat(case_t mat[Y][X]);

void contour_mat(case_t mat[Y][X]);

void afficher_mat(case_t mat[Y][X]);

int case_libre (case_t mat[Y][X], int coord_y, int coord_x);

void placer_objet(case_t mat[Y][X], int coord_y, int coord_x, char* id, int col);

void placer_pers(case_t mat[Y][X], int coord_y, int coord_x, perso_t  *player);

void deplacer_pers(case_t mat[Y][X], int coord_y, int coord_x, perso_t  *player);

void aller_gauche(case_t mat[Y][X], perso_t *player);

void aller_droite(case_t mat[Y][X], perso_t *player);

void aller_dessus(case_t mat[Y][X], perso_t *player);

void aller_dessous(case_t mat[Y][X], perso_t *player);

void info_objet(case_t mat[Y][X], int coord_y, int coord_x);//Pas forcement utile à voir pour supprimer



