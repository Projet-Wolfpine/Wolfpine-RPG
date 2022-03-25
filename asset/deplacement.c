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

//Fonction de création et d'initialisationn d'une matrice vide (remplie d'etat de collisio à 0)
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
      if(mat[i][j].col== 2){//personnage
        printf("P");
      }
      if(mat[i][j].col== 1)//collision
        printf("C");
      if(mat[i][j].col== 0 && strcmp(mat[i][j].id,"vide"))//case traversable
        printf("T");
      if(mat[i][j].col== 0)//case vide
        printf(" ");
    }
    printf("\n");
  }
}

//Renvoi vrai si la case est libre
int case_libre (case_t mat[Y][X], int coord_y, int coord_x){
  return(mat[coord_y][coord_x].col == 0);//ne pas modifier pour garder le déplacement du personnage possible
}

//Fonction qui permet de placer un objet dans la matrice
void placer_objet(case_t mat[Y][X], int coord_y, int coord_x, char* id, int col){
  if(case_libre(mat,coord_y,coord_x) && strcmp(mat[coord_y][coord_x].id,"vide")){
    mat[coord_y][coord_x].col = col; //ici le chiffre 1 correspond à une collision et 0 correspond à une aucune collision
    mat[coord_y][coord_x].id = id;
  }else{
    //traiter le cas ou ça ne peut pas placer / ou il y'a deja un objet
  }
}

void placer_pers(case_t mat[Y][X], int coord_y, int coord_x, perso_t  *player){
  if(case_libre(mat,coord_y,coord_x)){
    mat[coord_y][coord_x].col=2;
    player->anc_coord_x = coord_x;
    player->anc_coord_y = coord_y;
  }
}

void deplacer_pers(case_t mat[Y][X], int coord_y, int coord_x, perso_t  *player){
  if(case_libre(mat,coord_y,coord_x)){
    mat[player->anc_coord_y][player->anc_coord_x].col = 0;
    placer_pers(mat,coord_y,coord_x,player);
  }
}

void aller_gauche(case_t mat[Y][X], perso_t *player){
  deplacer_pers(mat,player->anc_coord_x-1,player->anc_coord_y,player);
  player->anc_coord_x -= 1;
}

void aller_droite(case_t mat[Y][X], perso_t *player){
  deplacer_pers(mat,player->anc_coord_x,player->anc_coord_y+1,player);
  player->anc_coord_y += 1;
}

void aller_dessus(case_t mat[Y][X], perso_t *player){
  deplacer_pers(mat,player->anc_coord_x,player->anc_coord_y-1,player);
  player->anc_coord_y -= 1;
}

void aller_dessous(case_t mat[Y][X], perso_t *player){
  deplacer_pers(mat,player->anc_coord_x+1,player->anc_coord_y,player);
  player->anc_coord_x += 1;
}

//Nous permet de savoir ce que contient une case
void info_objet(case_t mat[Y][X], int coord_y, int coord_x){
  if(case_libre(mat,coord_y,coord_x) && strcmp(mat[coord_y][coord_x].id,"vide")){//ne marche pas mais est pourtant necessaire pour éviter une erreur de segmentation
    printf("L'emplacement en Y = %d et X = %d ne contient aucun objet\n", coord_y, coord_x);
  }else{
    printf("L'objet stocké en Y = %d et X = %d est : %s\n",coord_y, coord_x, mat[coord_y][coord_x].id);
    printf("Son statut de collision est de : %d\n",mat[coord_y][coord_x].col);
  }
}
