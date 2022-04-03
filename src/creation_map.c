#include "../lib/deplacement.h"
#include "../lib/creation_map.h"
#include "../lib/fonction_sdl.h"
#include <sys/time.h>
#include <time.h>

case_t map_info[Y][X];
int map_int[Y][X];

float time_diff2(struct timespec *start, struct timespec *end){
    return (end->tv_sec - start->tv_sec) + 1e-9*(end->tv_nsec - start->tv_nsec);
}


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

//Fonction pemetant d'associer un id et un statut de collision à toutes les cases de la matrice
void mise_struct_map(case_t map_info[Y][X], int map_int[Y][X]){
    struct timespec start2;
    struct timespec end2;
    clock_gettime(CLOCK_REALTIME, &start2);
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
            if(map_int[i][j] == 52){
              map_info[i][j].id = "ID_SOL2";
              map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 53){
                map_info[i][j].id = "ID_HERBE2";
                map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 54){
                map_info[i][j].id = "ID_ARBRE1_1";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 55){
                map_info[i][j].id = "ID_ARBRE1_2";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 56){
                map_info[i][j].id = "ID_ARBRE1_3";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 57){
                map_info[i][j].id = "ID_ARBRE1_4";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 58){
                map_info[i][j].id = "ID_ARBRE2_1";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 59){
                map_info[i][j].id = "ID_ARBRE2_2";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 60){
                map_info[i][j].id = "ID_ARBRE2_3";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 61){
                map_info[i][j].id = "ID_ARBRE2_4";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 62){
                map_info[i][j].id = "ID_ARBRE3_1";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 63){
                map_info[i][j].id = "ID_ARBRE3_2";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 64){
                map_info[i][j].id = "ID_ARBRE3_3";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 65){
                map_info[i][j].id = "ID_ARBRE3_4";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 66){
                map_info[i][j].id = "ID_SORTIE4";
                map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 67){
                map_info[i][j].id = "ID_CHEMINBLOC2";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 68){
                map_info[i][j].id = "ID_ESCALIER1";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 69){
                map_info[i][j].id = "ID_ESCALIER2";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 70){
                map_info[i][j].id = "ID_ESCALIER3";
                map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 71){
                map_info[i][j].id = "ID_ESCALIER4";
                map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 72){
                map_info[i][j].id = "ID_ESCALIER5";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 73){
                map_info[i][j].id = "ID_ESCALIER6";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 74){
                map_info[i][j].id = "ID_ENTREEGROTTE1";
                map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 75){
                map_info[i][j].id = "ID_ENTREEGROTTE2";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 76){
                map_info[i][j].id = "ID_GROTTE1";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 77){
                map_info[i][j].id = "ID_GROTTE2";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 78){
                map_info[i][j].id = "ID_GROTTE3";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 79){
                map_info[i][j].id = "ID_GROTTE4";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 80){
                map_info[i][j].id = "ID_GROTTE5";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 81){
                map_info[i][j].id = "ID_GROTTE6";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 82){
                map_info[i][j].id = "ID_GROTTE7";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 83){
                map_info[i][j].id = "ID_GROTTE8";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 84){
                map_info[i][j].id = "ID_GROTTE9";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 85){
                map_info[i][j].id = "ID_GROTTE10";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 86){
                map_info[i][j].id = "ID_GROTTE11";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 87){
                map_info[i][j].id = "ID_BARRIERE1";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 88){
                map_info[i][j].id = "ID_BARRIERE2";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 89){
                map_info[i][j].id = "ID_BARRIERE3";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 90){
                map_info[i][j].id = "ID_MUR3";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 91){
                map_info[i][j].id = "ID_MURDONJON1";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 92){
                map_info[i][j].id = "ID_SORTIE5";
                map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 93){
                map_info[i][j].id = "ID_SORTIE6";
                map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 94){
                map_info[i][j].id = "ID_SOLMONSTRE1";
                map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 95){
                map_info[i][j].id = "ID_SOLMONSTRE2";
                map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 96){
                map_info[i][j].id = "ID_SORTIE7";
                map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 97){
                map_info[i][j].id = "ID_SORTIE8";
                map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 98){
                map_info[i][j].id = "ID_SORTIE9";
                map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 99){
                map_info[i][j].id = "ID_ESCALIERDONJON1";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 100){
                map_info[i][j].id = "ID_ESCALIERDONJON2";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 101){
                map_info[i][j].id = "ID_ESCALIERDONJON3";
                map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 102){
                map_info[i][j].id = "ID_ESCALIERDONJON4";
                map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 103){
                map_info[i][j].id = "ID_ESCALIERDONJON5";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 104){
                map_info[i][j].id = "ID_ESCALIERDONJON6";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 105){
                map_info[i][j].id = "ID_SOL3";
                map_info[i][j].col = 0;
            }
            if(map_int[i][j] == 106){
                map_info[i][j].id = "ID_MURET1";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 107){
                map_info[i][j].id = "ID_MURET2";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 108){
                map_info[i][j].id = "ID_MURET3";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 109){
                map_info[i][j].id = "ID_MURET4";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 110){
                map_info[i][j].id = "ID_WOLFY1";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 111){
                map_info[i][j].id = "ID_WOLFY2";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 112){
                map_info[i][j].id = "ID_WOLFY3";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 113){
                map_info[i][j].id = "ID_WOLFY4";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 114){
                map_info[i][j].id = "ID_WOLFY5";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 115){
                map_info[i][j].id = "ID_WOLFY6";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 116){
                map_info[i][j].id = "ID_WOLFY7";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 117){
                map_info[i][j].id = "ID_WOLFY8";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 118){
                map_info[i][j].id = "ID_WOLFY9";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 119){
                map_info[i][j].id = "ID_WOLFY10";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 120){
                map_info[i][j].id = "ID_WOLFY11";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 121){
                map_info[i][j].id = "ID_WOLFY12";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 122){
                map_info[i][j].id = "ID_WOLFY13";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 123){
                map_info[i][j].id = "ID_WOLFY14";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 124){
                map_info[i][j].id = "ID_WOLFY15";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 125){
                map_info[i][j].id = "ID_WOLFY16";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 126){
                map_info[i][j].id = "ID_WOLFY17";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 127){
                map_info[i][j].id = "ID_WOLFY18";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 128){
                map_info[i][j].id = "ID_WOLFY19";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 129){
                map_info[i][j].id = "ID_WOLFY20";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 130){
                map_info[i][j].id = "ID_WOLFY21";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 131){
                map_info[i][j].id = "ID_WOLFY22";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 132){
                map_info[i][j].id = "ID_WOLFY23";
                map_info[i][j].col = 1;
            }
            if(map_int[i][j] == 900){
                map_info[i][j].id = "PNJ01";
                map_info[i][j].col = 3;
            }
            if(map_int[i][j] == 901){
                map_info[i][j].id = "PNJ_EPEE";
                map_info[i][j].col = 3;
            }
            if(map_int[i][j] == 902){
                map_info[i][j].id = "PNJ02";
                map_info[i][j].col = 3;
            }
            if(map_int[i][j] == 911){
                map_info[i][j].id = "PNJ_WOLFY";
                map_info[i][j].col = 3;
            }

        }
    }
    clock_gettime(CLOCK_REALTIME, &end2);
     printf("time fonction %0.8f sec\n",time_diff2(&start2, &end2));
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
