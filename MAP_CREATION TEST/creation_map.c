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
          map_info[i][j].id = "ID_LIT2";
          map_info[i][j].col = 0;
          break;
        case 5:
          map_info[i][j].id = "ID_LIT3";
          map_info[i][j].col = 0;
          break;
        case 6:
          map_info[i][j].id = "ID_";
          map_info[i][j].col = 0;
          break;
        case 7:
          map_info[i][j].id = "ID_";
          map_info[i][j].col = 0;
          break;
        case 8:
          map_info[i][j].id = "ID_";
          map_info[i][j].col = 0;
          break;
        case 9:
          map_info[i][j].id = "ID_";
          map_info[i][j].col = 0;
          break;
        case 10:
          map_info[i][j].id = "ID_";
          map_info[i][j].col = 0;
          break;
        case 11:
          map_info[i][j].id = "ID_";
          map_info[i][j].col = 0;
          break;
        case 12:
          map_info[i][j].id = "ID_";
          map_info[i][j].col = 0;
          break;
        case 13:
          map_info[i][j].id = "ID_";
          map_info[i][j].col = 0;
          break;
        case 14:
          map_info[i][j].id = "ID_";
          map_info[i][j].col = 0;
          break;
        case 15:
          map_info[i][j].id = "ID_";
          map_info[i][j].col = 0;
          break;
        case 16:
          map_info[i][j].id = "ID_";
          map_info[i][j].col = 0;
          break;
        case 17:
          map_info[i][j].id = "ID_";
          map_info[i][j].col = 0;
          break;
        case 19:
          map_info[i][j].id = "ID_";
          map_info[i][j].col = 0;
          break;
        case 20:
          map_info[i][j].id = "ID_";
          map_info[i][j].col = 0;
          break;
      }
    }
  }
}
