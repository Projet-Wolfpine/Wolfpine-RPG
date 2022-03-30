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

int main(){
  case_t mat[Y][X];
  perso_t player = init_player();
  init_mat(mat);
  contour_mat(mat);
  placer_pers(mat,10,10,&player);
  afficher_mat(mat);
  deplacer_pers(mat,10,11,&player);
  afficher_mat(mat);
  deplacer_pers(mat,10,12,&player);
  afficher_mat(mat);
  printf("TEST\n");
  aller_gauche2(mat,&player);
}
