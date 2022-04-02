#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/*
#include "structures.h"
#include "deplacement.h"
#include "spells.h"
#include "inventory.h"
*/
#include "combat.h"

//Test de la création, initialisation de la map et du joueur en terminal, et du déplacement
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
  aller_gauche2(mat,&player);
}
