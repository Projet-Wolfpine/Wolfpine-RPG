#include "deplacement.h"
#include "creation_map.h"
#include "fonction_sdl.h"

case_t map_info[Y][X];
int map_int[Y][X];


  /* la fonction prend la matrice avec les entiers afin de  remplir un tableau
  de structure contenant les infos de chaque cases (id_bloc et statut colision)*/


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
    int i, j;
    for(i=0;i<Y;i++){
        for(j=0;j<X;j++){
            if(map_int[i][j] == 1){
                map_info[i][j].id = "ID_MUR1";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 2){
                map_info[i][j].id = "ID_MUR2";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 3){
                map_info[i][j].id = "ID_SOL1";
                map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 4){
                map_info[i][j].id = "ID_LIT1";
                map_info[i][j].col = 1;

            }
            if(map_int[i][j] == 5){
                map_info[i][j].id = "ID_LIT2";
                map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 6){
              map_info[i][j].id = "ID_TAPIS1";
              map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 7){
              map_info[i][j].id = "ID_TAPIS2";
              map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 8){
              map_info[i][j].id = "ID_TAPIS3";
              map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 9){
              map_info[i][j].id = "ID_TAPIS4";
              map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 10){
                map_info[i][j].id = "ID_TAPIS5";
                map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 11){
                map_info[i][j].id = "ID_TAPIS6";
                map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 12){
                map_info[i][j].id = "ID_TAPIS7";
                map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 13){
                map_info[i][j].id = "ID_TAPIS8";
                map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 14){
                map_info[i][j].id = "ID_TAPIS9";
                map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 15){
                map_info[i][j].id = "ID_TABOURET";
                map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 16){
                map_info[i][j].id = "ID_TABLE1";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 17){
                map_info[i][j].id = "ID_TABLE2";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 18){
                map_info[i][j].id = "ID_TABLE3";
                map_info[i][j].col = 1;
            }

            if(map_int[i][j] == 19){
                map_info[i][j].id = "ID_TABLE4";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 20){
                map_info[i][j].id = "ID_TABLE5";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 21){
                map_info[i][j].id = "ID_TABLE6";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 22){
                map_info[i][j].id = "ID_TABLE7";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 23){
                map_info[i][j].id = "ID_TABLE8";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 24){
                map_info[i][j].id = "ID_TABLE9";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 25){
                map_info[i][j].id = "ID_SORTIE1";
                map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 26){
                map_info[i][j].id = "ID_SORTIE2";
                map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 27){
                map_info[i][j].id = "ID_HERBE1";
                map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 28){
                map_info[i][j].id = "ID_PORTE1";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 29){
                map_info[i][j].id = "ID_PORTE2";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 30){
                map_info[i][j].id = "ID_FENETRE";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 31){
                map_info[i][j].id = "ID_TOIT1";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 32){
                map_info[i][j].id = "ID_TOIT2";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 33){
                map_info[i][j].id = "ID_TOIT3";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 34){
                map_info[i][j].id = "ID_TOIT4";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 35){
                map_info[i][j].id = "ID_BUISSON";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 36){
                map_info[i][j].id = "ID_CHEMIN";
                map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 37){
                map_info[i][j].id = "ID_FONTAINE1";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 38){
                map_info[i][j].id = "ID_FONTAINE2";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 39){
                map_info[i][j].id = "ID_FONTAINE3";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 40){
                map_info[i][j].id = "ID_FONTAINE4";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 41){
                map_info[i][j].id = "ID_FONTAINE5";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 42){
                map_info[i][j].id = "ID_FONTAINE6";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 43){
                map_info[i][j].id = "ID_FONTAINE7";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 44){
                map_info[i][j].id = "ID_FONTAINE8";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 45){
                map_info[i][j].id = "ID_FONTAINE9";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 46){
                map_info[i][j].id = "ID_SORTIE3";
                map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 47){
                map_info[i][j].id = "ID_CHEMINBLOC1";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 48){
                map_info[i][j].id = "ID_TOITBLEU1";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 49){
                map_info[i][j].id = "ID_TOITBLEU2";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 50){
                map_info[i][j].id = "ID_TOITBLEU3";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 51){
                map_info[i][j].id = "ID_TOITBLEU4";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 51){
                map_info[i][j].id = "ID_MUR3";
                map_info[i][j].col = 1;
            }
        }
    }
}

void afficher_map(char * nom_map,int taille, case_t map_info[Y][X]){
  int i,j;
  //init_mat(map_info);
  lecture_fichier_map(nom_map, map_int);
  mise_struct_map(map_info,map_int);
  for(i = 0;i<Y; i++){
        for(j = 0; j<X; j++){
            drawImage(j*taille , i*taille , map_info[i][j].id, taille, taille);
        }
    }
}