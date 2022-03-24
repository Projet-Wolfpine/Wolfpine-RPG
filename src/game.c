#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "fonction_sdl.h"
#include "gestion_deplacement_sdl.h"
#include "menu_principal.h"
#include "deplacement.h"
#include "game.h"

//#define TAILLE_CASE_PXL 64

case_t mat[Y][X];
perso_t joueur;
//joueur = malloc(sizeof(perso_t));


void map(){
	//fond_blanc();
	int longeur = 1920;
	int hauteur = 1080;
	int longeur_mat = longeur/TAILLE_CASE_PXL;
	int hauteur_mat = hauteur/TAILLE_CASE_PXL;
	for(int i = 0;i<longeur_mat; i++) // i coresppond a x de la matrice et j coresppond a y en ordonnée 
			for(int j = 0; j<hauteur_mat; j++)
                	drawImage(i*TAILLE_CASE_PXL , j*TAILLE_CASE_PXL , "herbe.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );

    drawImage(TAILLE_CASE_PXL*10 , TAILLE_CASE_PXL*5 , "perso.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );
	placer_pers(mat,5,10,&joueur);//probleme
    afficher_mat(mat);

}



void start(){
    SDL_RenderClear(renderer);
    int touche=-1;
    int cpt=0;
    int running = 1;
  	init_mat(mat);
	contour_mat(mat);
    afficher_mat(mat);
    init_player(&joueur);
    placer_pers(mat,5,10,&joueur);
    map();
    faire_rendu();
    while(running == 1){
        //cpt++;
        touche=touche_detecter();
        //printf("%d\n",touche);
        if(touche != 0){
            map();
            if(touche == 1){
                drawImage(TAILLE_CASE_PXL*15 , TAILLE_CASE_PXL*7 , "perso.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL ); 

            }
            if(touche == 2){
                drawImage(TAILLE_CASE_PXL*20 , TAILLE_CASE_PXL*15 , "perso.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );

            }
            if(touche == 5){
                running=0;
            }
            
            faire_rendu();
            

        }
        /*if(cpt == 15){
            running=0;
        }*/


        

    }
    //SDL_RenderClear(renderer);
    Menu();



}