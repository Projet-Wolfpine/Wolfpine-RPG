#include <stdlib.h>
#include <stdio.h>
//Lors du parcours de matrice puisque que les premiers crochet correspondes à la vertical et pas l'horizontal il faudra commencer par mettre les coordonnés Y puis X pour les fonctions
#define Y 11
#define X 31

typedef struct objet_s{
  char *id;
  int col;
}objet_t;

//Fonction de création et d'initialisationn d'une matrice vide (remplie de 0)
void init_mat(objet_t mat[Y][X]){
  for(int i=0;i<Y;i++){
    for(int j=0; j<X; j++){
      mat[i][j].col = 0;
    }
  }
}

//Fonction de création des bordures de la matrice
void contour_mat(objet_t mat[Y][X]){
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
void afficher_mat(objet_t mat[Y][X]){
  for(int i=0;i<Y;i++){
    for(int j=0; j<X; j++){
      if(mat[i][j].col== 3){//personnage
        printf("P");
      }
      if(mat[i][j].col== 2)//objet traversable
        printf("T");
      if(mat[i][j].col== 1)//collision
        printf("C");
      if(mat[i][j].col== 0)//case vide
        printf(" ");
    }
    printf("\n");
  }
}

//Renvoi vrai si la case est libre
int case_libre (objet_t mat[Y][X], int coord_x, int coord_y){
  return(mat[coord_y][coord_x].col == 0);
}

void placer_objet(objet_t mat[Y][X], int coord_x, int coord_y, char* id, int col){
  if(case_libre(mat,coord_y,coord_x)){
    mat[coord_y][coord_x].col = col; //ici le chiffre 2 correspond à un objet traversable, le chiffre 1 correspond à une collision et 0 correspond à une valeur sans aucun objet
    mat[coord_y][coord_x].id = id;
  }
}

void info_objet(objet_t mat[Y][X], int coord_x, int coord_y){
  //if(!case_libre(mat,coord_y,coord_x)){ //ne marche pas mais est pourtant necessaire pour éviter une erreur de segmentation
    printf("L'objet stocké en Y = %d et X = %d est : %s\n",coord_y, coord_x, mat[coord_y][coord_x].id);
    printf("Son statut de collision est de : %d\n",mat[coord_y][coord_x].col);
  //}
}

int main(){
  objet_t mat[Y][X];
  init_mat(mat);
  contour_mat(mat);
  placer_objet(mat,1,3,"palmier",1);
  afficher_mat(mat);
  info_objet(mat,2,4);
}