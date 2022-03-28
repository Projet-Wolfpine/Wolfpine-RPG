#include "stdlib.h"
#include "stdio.h"
#include "deplacement.h"

void lecture_fichier_map(char nom_fichier[20],int map_int[Y][X]){
  /* lis un fichier.txt data de a map demandée,
   et met chaque entier dans une case de la matrice*/
  int i, j, var;
  FILE * fic;
  fic=fopen(nom_fichier,"r");
  fscanf(fic,"%i", &var);
  for(i=0;i<Y;i++){
    for(j=0;j<X;j++){
      map_int[i][j]=var;
      fscanf(fic,"%i", &var);
    }
  }
  fclose(fic);
}


void mise_struct_map(case_t map_info[Y][X], int map_int[Y][X]){
  /* la fonction prend la matrice avec les entiers afin de  remplir un tableau
  de structure contenant les infos de chaque cases (id_bloc et statut colision)*/
  int i, j;
  for(i=0;i<Y;i++){
    for(j=0;j<X;j++){
      switch(map_int[i][j]){
        case 1:
          map_info[i][j].id = "ID_MUR1";
          map_info[i][j].col = 1;
          break;
        case 2:
          map_info[i][j].id = "ID_MUR2";
          map_info[i][j].col = 1;
          break;
        case 3:
          map_info[i][j].id = "ID_SOL1";
          map_info[i][j].col = 0;
          break;
        case 4:
          map_info[i][j].id = "ID_LIT1";
          map_info[i][j].col = 1;
          break;
        case 5:
          map_info[i][j].id = "ID_LIT2";
          map_info[i][j].col = 1;
          break;
        case 6:
          map_info[i][j].id = "ID_TAPIS1";
          map_info[i][j].col = 0;
          break;
        case 7:
          map_info[i][j].id = "ID_TAPIS2";
          map_info[i][j].col = 0;
          break;
        case 8:
          map_info[i][j].id = "ID_TAPIS3";
          map_info[i][j].col = 0;
          break;
        case 9:
          map_info[i][j].id = "ID_TAPIS4";
          map_info[i][j].col = 0;
          break;
        case 10:
          map_info[i][j].id = "ID_TAPIS5";
          map_info[i][j].col = 0;
          break;
        case 11:
          map_info[i][j].id = "ID_TAPIS6";
          map_info[i][j].col = 0;
          break;
        case 12:
          map_info[i][j].id = "ID_TAPIS7";
          map_info[i][j].col = 0;
          break;
        case 13:
          map_info[i][j].id = "ID_TAPIS8";
          map_info[i][j].col = 0;
          break;
        case 14:
          map_info[i][j].id = "ID_TAPIS9";
          map_info[i][j].col = 0;
          break;
        case 15:
          map_info[i][j].id = "ID_TABOURET";
          map_info[i][j].col = 0;
          break;
        case 16:
          map_info[i][j].id = "ID_TABLE1";
          map_info[i][j].col = 1;
          break;
        case 17:
          map_info[i][j].id = "ID_TABLE2";
          map_info[i][j].col = 1;
          break;
        case 18:
          map_info[i][j].id = "ID_TABLE3";
          map_info[i][j].col = 1;
          break;
        case 19:
          map_info[i][j].id = "ID_TABLE4";
          map_info[i][j].col = 1;
          break;
        case 20:
          map_info[i][j].id = "ID_TABLE5";
          map_info[i][j].col = 1;
          break;
        case 21:
          map_info[i][j].id = "ID_TABLE6";
          map_info[i][j].col = 1;
          break;
        case 22:
          map_info[i][j].id = "ID_TABLE7";
          map_info[i][j].col = 1;
          break;
        case 23:
          map_info[i][j].id = "ID_TABLE8";
          map_info[i][j].col = 1;
          break;
        case 24:
          map_info[i][j].id = "ID_TABLE9";
          map_info[i][j].col = 1;
          break;
        case 25:
          map_info[i][j].id = "ID_SORTIE1";
          map_info[i][j].col = 0;
          break;
        case 27:
          map_info[i][j].id = "ID_SORTIE2";
          map_info[i][j].col = 0;
          break;
        case 28:
          map_info[i][j].id = "ID_HERBE1";
          map_info[i][j].col = 0;
          break;
      }
    }
  }
}


int main(){
  case_t map_info[Y][X];
  int map_int[Y][X];
  char nom_fichier[20];
  int i,j;
  printf("donnez le nom du fichier : ") ;
  scanf("%s", nom_fichier) ;
  lecture_fichier_map(nom_fichier, map_int);
  for(i = 0; i<Y;i++){
    for(j = 0; j<X;j++){
      printf("%i ", map_int[i][j]);
    }
    printf("\n");
  }
  mise_struct_map(map_info,map_int);
  printf("\n");
  printf("\n");
  for(i =0; i<Y;i++){
    for(j=0; j<X;j++){
      printf("%s   ",map_info[i][j].id);
    }
    printf("\n");
  }
  printf("\n");
}
