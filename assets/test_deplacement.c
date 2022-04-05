#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "combat.h"
#include "deplacement.h"

int main(){
  case_t mat[Y][X];
  perso_t player = init_player();
  init_mat(mat);
  contour_mat(mat);
  placer_pers(mat,1,1,&player);
  afficher_mat(mat);
  deplacer_pers(mat,1,2,&player);
  afficher_mat(mat);
  deplacer_pers(mat,1,3,&player);
  afficher_mat(mat);
  printf("TEST\n");
  gauche(mat,&player);
  afficher_mat(mat);
  gauche(mat,&player);
  afficher_mat(mat);
  gauche(mat,&player);
  afficher_mat(mat);
  gauche(mat,&player);
  afficher_mat(mat);
  droite(mat,&player);
  afficher_mat(mat);
  droite(mat,&player);
  afficher_mat(mat);
  droite(mat,&player);
  afficher_mat(mat);
  dessous(mat,&player);
  afficher_mat(mat);
  dessus(mat,&player);
  afficher_mat(mat);
}
