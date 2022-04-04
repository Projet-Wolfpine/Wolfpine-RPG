#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../lib/deplacement.h"

/**
 * \file deplacement.c
 * \brief Fonctions de déplacement d'un personnage dans une matrice.
 * \author Ilyas.A
 * \version 1.2
 * \date 04 avril 2022
 */

/**
 * \fn void init_mat(case_t mat[Y][X])
 * \brief Fonction de création et d'initialisationn d'une matrice vide (remplie d'etat de collision à 0)
 * \param mat matrice de case_t dans laquelle on stocke les informations initialisées
 */
void init_mat(case_t mat[Y][X]){
  for(int i=0;i<Y;i++){
    for(int j=0; j<X; j++){
      mat[i][j].col = 0;
      mat[i][j].id = "vide";
    }
  }
}

/**
 * \fn void init_mat(case_t mat[Y][X])
 * \brief Fonction de création des bordures de la matrice
 * \param mat matrice de case_t dans laquelle on stocke les informations initialisées
 */
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

/**
 * \fn void afficher_mat(case_t mat[Y][X])
 * \brief Fonction d'affichage de la matrice
 * \param mat matrice de case_t que l'on souhaite afficher
 */
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

/**
 * \fn int case_libre (case_t mat[Y][X], int coord_y, int coord_x)
 * \brief Vérifie si la case sur laquelle on se déplace est libre (id collision)
 * \param mat matrice de case_t sur laquelle on se déplace
 * \param coord_y coordonée en y que l'on souhaite tester
 * \param coor_x coordonée en x que l'on souhaite tester
 * \return renvoie 1 si la case est libre, 0 sinon
 */
int case_libre (case_t mat[Y][X], int coord_y, int coord_x){
  return(mat[coord_y][coord_x].col == 0);
}

/**
 * \fn void placer_pers(case_t mat[Y][X], int coord_y, int coord_x, perso_t  *player)
 * \brief Place le personnage si la case est libre
 * \param mat matrice de case_t sur laquelle on souhaite placer le personnage
 * \param coord_y coordonée en y où l'on place le personnage
 * \param coor_x coordonée en x où l'on place le personnage
 */
void placer_pers(case_t mat[Y][X], int coord_y, int coord_x, perso_t  *player){
  if(case_libre(mat,coord_y,coord_x)){
    mat[coord_y][coord_x].col=2;
    player->anc_coord_x = coord_x;
    player->anc_coord_y = coord_y;
  }
}

/**
 * \fn int deplacer_pers(case_t mat[Y][X], int coord_y, int coord_x, perso_t  *player)
 * \brief Déplace le personnage sur la case souhaitée
 * \param mat matrice de case_t sur laquelle on souhaite déplacer le personnage
 * \param coord_y coordonée en y où l'on place le personnage
 * \param coor_x coordonée en x où l'on place le personnage
 * \param player personnage que l'on souhaite déplacer
 */
int deplacer_pers(case_t mat[Y][X], int coord_y, int coord_x, perso_t  *player){
  if(case_libre(mat,coord_y,coord_x)){
    mat[player->anc_coord_y][player->anc_coord_x].col = 0;
    placer_pers(mat,coord_y,coord_x,player);
    return 1;
  }else{
    return 0;
  }
}

 
/**
 * \fn int gauche(case_t mat[Y][X], perso_t *player)
 * \brief Fonction de déplacement matriciel vers la gauche
 * \param mat matrice de case_t sur laquelle on souhaite déplacer le personnage
 * \param player personnage que l'on souhaite déplacer
 */
int gauche(case_t mat[Y][X], perso_t *player){
  return(deplacer_pers(mat,player->anc_coord_y,player->anc_coord_x-1,player));
}

/**
 * \fn int droite(case_t mat[Y][X], perso_t *player)
 * \brief Fonction de déplacement matriciel vers la droite
 * \param mat matrice de case_t sur laquelle on souhaite déplacer le personnage
 * \param player personnage que l'on souhaite déplacer
 */
int droite(case_t mat[Y][X], perso_t *player){
  return(deplacer_pers(mat,player->anc_coord_y,player->anc_coord_x+1,player));
}

/**
 * \fn int dessus(case_t mat[Y][X], perso_t *player)
 * \brief Fonction de déplacement matriciel vers le haut
 * \param mat matrice de case_t sur laquelle on souhaite déplacer le personnage
 * \param player personnage que l'on souhaite déplacer
 */
int dessus(case_t mat[Y][X], perso_t *player){
  return(deplacer_pers(mat,player->anc_coord_y-1,player->anc_coord_x,player));
}

/**
 * \fn int dessous(case_t mat[Y][X], perso_t *player)
 * \brief Fonction de déplacement matriciel vers le bas
 * \param mat matrice de case_t sur laquelle on souhaite déplacer le personnage
 * \param player personnage que l'on souhaite déplacer
 */
int dessous(case_t mat[Y][X], perso_t *player){
  return(deplacer_pers(mat,player->anc_coord_y+1,player->anc_coord_x,player));
}

/**
 * \fn int est_a_cote(case_t mat[Y][X], perso_t *perso)
 * \brief Fonction pour savoir si on est proche ou non d'un PNJ
 * \param mat matrice de case_t dans laquelle on souhaite effectuer le test
 * \param perso personnage sur qui on souhaite effectuer le test
 * \return -1 si bas, -2 si haut, -3 si droite, -4 si gauche, 0 si pas de PNJ
 */
int est_a_cote(case_t mat[Y][X], perso_t *perso){
   if(mat[perso->anc_coord_y+1][perso->anc_coord_x].col == 3){
        printf("\nDetection PNJ bas\n");
       return -1;
   }
   if(mat[perso->anc_coord_y-1][perso->anc_coord_x].col == 3){
     printf("\nDetection PNJ haut\n");
       return -2;
   }
   if(mat[perso->anc_coord_y][perso->anc_coord_x+1].col == 3){
     printf("\nDetection PNJ droite\n");
       return -3;
   }
   if(mat[perso->anc_coord_y][perso->anc_coord_x-1].col == 3){
     printf("\nDetection PNJ gauche\n");
       return -4;
   }else{
        printf("\nPas de PNJ\n");
        return 0;
    }
}
