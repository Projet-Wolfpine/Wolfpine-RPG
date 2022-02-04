#include <stdlib.h>
#include <stdio.h>
//Lors du parcours de matrice puisque que les premiers crochet correspondes à la vertical et pas l'horizontal il faudra commencer par mettre les coordonnés Y puis X pour les fonctions
#define Y 11
#define X 31
/*typedef struct cell{
  char * id;
  int col;
}*/

//Fonction de création et d'initialisationn d'une matrice vide (remplie de 0)
void init_mat(int mat[Y][X]){
  for(int i=0;i<Y;i++){
    for(int j=0; j<X; j++){
      mat[i][j] = 0;
    }
  }
}

//Fonction de création des bordures de la matrice
void contour_mat(int mat[Y][X]){
  for(int j = 0; j<X; j++){
      mat[0][j] = 1;
      mat[Y-1][j] = 1;
  }
  for(int i = 0; i<Y; i++){
      mat[i][0] = 1;
      mat[i][X-1] = 1;
  }
}

//Fonction d'affichage de la matrice
void afficher_mat(int mat[Y][X]){
  for(int i=0;i<Y;i++){
    for(int j=0; j<X; j++){
      if(mat[i][j]== 2)
        printf("P");
      if(mat[i][j]== 1)
        printf("X");
      if(mat[i][j]== 0)
        printf(" ");
    }
    printf("\n");
  }
}

//Renvoi vrai si la case est libre
int case_libre (int mat[Y][X], int coord_x, int coord_y){
  return(mat[coord_y][coord_x] == 0);
}

//Place le personnage au debut de partie
void placer_pers(int mat[Y][X], int coord_x, int coord_y){
  if(case_libre(mat,coord_y,coord_x))
    mat[coord_y][coord_x]=2;
}

//Deplace le personnage (ne pas oublier de supprimer l'ancien personnage avant de placer le nouveau)
void deplacer_pers(int mat[Y][X], int coord_x, int coord_y, int anc_coord_x, int anc_coord_y){
  if(case_libre(mat,coord_y,coord_x)){
    placer_pers(mat,coord_y,coord_x);
    mat[anc_coord_y][anc_coord_x] = 0;
  }
}

//fonction provisoire pour tester les deplacements + probleme dans les deplacement (surement le default qui remet pas dans le switch après)
void jeu(int mat[Y][X], int anc_coord_x, int anc_coord_y){
  char direction;
  printf("Saisir Z,Q,S ou D pour vous deplacer\n");
  scanf("%c",&direction);
  switch(direction){
    case 'z': deplacer_pers(mat,anc_coord_x,anc_coord_y-1,anc_coord_x,anc_coord_y);break;
    case 'q': deplacer_pers(mat,anc_coord_x-1,anc_coord_y,anc_coord_x,anc_coord_y);break;
    case 's': deplacer_pers(mat,anc_coord_x,anc_coord_y+1,anc_coord_x,anc_coord_y);break;
    case 'd': deplacer_pers(mat,anc_coord_x+1,anc_coord_y,anc_coord_x,anc_coord_y);break;
    case 'Z': deplacer_pers(mat,anc_coord_x,anc_coord_y-1,anc_coord_x,anc_coord_y);break;
    case 'Q': deplacer_pers(mat,anc_coord_x-1,anc_coord_y,anc_coord_x,anc_coord_y);break;
    case 'S': deplacer_pers(mat,anc_coord_x,anc_coord_y+1,anc_coord_x,anc_coord_y);break;
    case 'D': deplacer_pers(mat,anc_coord_x+1,anc_coord_y,anc_coord_x,anc_coord_y);break;
    default: printf("Saisir Z,Q,S ou D pour vous deplacer\n");scanf("%c",&direction); //changer le if ligne 68 (au dessus) pour le mettre à la place du default ici, ça evite la boucle en dessous aussi
  }
}

//Programme principal
int main (){
  int mat[Y][X];
  init_mat(mat);
  contour_mat(mat);
  placer_pers(mat, 1, 1);
  while(1){//boucle infinie pour test (oui je sais que c moche)
    system("clear");
    afficher_mat(mat);
    jeu(mat,1,1);
  }
  //afficher_mat(mat);
  return 0;
}
