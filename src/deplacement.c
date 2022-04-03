#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "deplacement.h"

/**
 * \file deplacement.c
 * \brief Fonctions de déplacement d'un personnage dans une matrice.
 * \author Ilyas.A
 * \version 1.0
 * \date 21 mars 2022
 */

//Fonction de création et d'initialisationn d'une matrice vide (remplie d'etat de collision à 0)
void init_mat(case_t mat[Y][X]){
  for(int i=0;i<Y;i++){
    for(int j=0; j<X; j++){
      mat[i][j].col = 0;
      mat[i][j].id = "vide";
    }
  }
}

//Fonction de création des bordures de la matrice
void contour_mat(case_t mat[Y][X]){
  for(int j = 0; j<X; j++){
      mat[0][j].col = 1;
      mat[Y-1][j].col = 1;
  }
  for(int i = 0; i<Y; i++){
      mat[i][0].col = 1;
      mat[i][X-1].col = 1;
  }
}

//Fonction d'affichage de la matrice
void afficher_mat(case_t mat[Y][X]){
  for(int i=0;i<Y;i++){
    for(int j=0; j<X; j++){
      if(mat[i][j].col== 3){//pnj
        printf("A");
      }
      if(mat[i][j].col== 2){//personnage
        printf("P");
      }
      if(mat[i][j].col== 1)//collision
        printf("C");
      if(mat[i][j].col== 0)//case vide
        printf(".");
    }
    printf("\n");
  }
}

//Renvoi vrai si la case est libre
int case_libre (case_t mat[Y][X], int coord_y, int coord_x){
  return(mat[coord_y][coord_x].col == 0);//ne pas modifier pour garder le déplacement du personnage possible
}

//Place le personnage si la case est libre
void placer_pers(case_t mat[Y][X], int coord_y, int coord_x, perso_t  *player){
  if(case_libre(mat,coord_y,coord_x)){
    mat[coord_y][coord_x].col=2;
    player->anc_coord_x = coord_x;
    player->anc_coord_y = coord_y;
  }
}

//Deplace un personnage à des coordonnées voulu
int deplacer_pers(case_t mat[Y][X], int coord_y, int coord_x, perso_t  *player){
  if(case_libre(mat,coord_y,coord_x)){
    mat[player->anc_coord_y][player->anc_coord_x].col = 0;
    placer_pers(mat,coord_y,coord_x,player);
    return 1;
  }else{
    return 0;
  }
}

//Fonction de déplacement matricielle 

int gauche(case_t mat[Y][X], perso_t *player){
  return(deplacer_pers(mat,player->anc_coord_y,player->anc_coord_x-1,player));
}

int droite(case_t mat[Y][X], perso_t *player){
  return(deplacer_pers(mat,player->anc_coord_y,player->anc_coord_x+1,player));
}

int dessus(case_t mat[Y][X], perso_t *player){
  return(deplacer_pers(mat,player->anc_coord_y-1,player->anc_coord_x,player));
}

int dessous(case_t mat[Y][X], perso_t *player){
  return(deplacer_pers(mat,player->anc_coord_y+1,player->anc_coord_x,player));
}

//Fonction pour savoir si on est proche ou non d'un PNJ
int est_a_cote(case_t mat[Y][X], perso_t *perso){ //pour les pnj 
   if(mat[perso->anc_coord_y+1][perso->anc_coord_x].col == 3){
       return -1;
   }
   if(mat[perso->anc_coord_y-1][perso->anc_coord_x].col == 3){
       return -2;
   }
   if(mat[perso->anc_coord_y][perso->anc_coord_x+1].col == 3){
       return -3;
   }
   if(mat[perso->anc_coord_y][perso->anc_coord_x-1].col == 3){
       return -4;
   }else{
        return 0;
    }
}
