#include "stdio.h"
#include "stdlib.h"
#include "../lib/string.h"
#include "../lib/combat.h"

/**
 * \file test_deplacement.c
 * \brief Test des fonctions de déplacement
 * \author Ilyas.A
 * \version 1.0
 * \date 04 avril 2022
 */

/**
 * \fn int main()
 * \brief Test de la création, initialisation de la map et du joueur en terminal, et du déplacement
 */
int main(){
  //Initialisation
  case_t mat[Y][X];
  perso_t player = init_player();
  init_mat(mat);
  contour_mat(mat);
  placer_pers(mat,10,10,&player);
  afficher_mat(mat);
  //Test du déplacement avec déplacer et la fonction gauche
  deplacer_pers(mat,10,11,&player);
  afficher_mat(mat);
  deplacer_pers(mat,10,12,&player);
  afficher_mat(mat);
  printf("TEST\n");
  gauche(mat,&player);
  droite(mat,&player);
}
