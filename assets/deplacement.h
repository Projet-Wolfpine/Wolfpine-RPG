#ifndef _DEPLACEMENT_H
#define _DEPLACEMENT_H
#include "structures.h"


//Lors du parcours de matrice puisque que les premiers crochet correspondes à la vertical et pas l'horizontal il faudra commencer par mettre les coordonnés Y puis X pour les fonctions
#define Y 16
#define X 31

void init_mat(case_t mat[Y][X]);

void contour_mat(case_t mat[Y][X]);

void afficher_mat(case_t mat[Y][X]);

int case_libre (case_t mat[Y][X], int coord_y, int coord_x);

void placer_pers(case_t mat[Y][X], int coord_y, int coord_x, perso_t  *player);

int deplacer_pers(case_t mat[Y][X], int coord_y, int coord_x, perso_t  *player);

int gauche(case_t mat[Y][X], perso_t *player);

int droite(case_t mat[Y][X], perso_t *player);

int dessus(case_t mat[Y][X], perso_t *player);

int dessous(case_t mat[Y][X], perso_t *player);

#endif
