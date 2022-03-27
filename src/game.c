#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "fonction_sdl.h"
#include "gestion_deplacement_sdl.h"
#include "menu_principal.h"
#include "deplacement.h"
#include "game.h"
#include "creation_map.h"

#define TAILLE_CASE_PXL 32

perso_t *joueur;
char * nom_map="map3.txt";

//joueur = malloc(sizeof(perso_t));

void start(){
    int y=10,x=10;
    SDL_RenderClear(renderer);
    int touche=-1;
    int running = 1;
  	//init_mat(mat);
	//contour_mat(mat);
    //afficher_mat(mat);
    //init_player(&joueur);
    //placer_pers(mat,5,10,&joueur);
    afficher_map(nom_map,64);
    faire_rendu();
    while(running == 1){
        touche=touche_detecter();
        if(touche != 0){
            afficher_map(nom_map,64);
        
            if(touche == 1){
                //nom_map="map2.txt";
                y--;
                drawImage(TAILLE_CASE_PXL*x , TAILLE_CASE_PXL*y , "perso.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL ); 
                faire_rendu();

            }
            if(touche == 2){
                //nom_map="map3.txt";
                y++;
                drawImage(TAILLE_CASE_PXL*x , TAILLE_CASE_PXL*y , "perso.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );
                faire_rendu();
                
            }
            if(touche == 3){
                x++;
                drawImage(TAILLE_CASE_PXL*x, TAILLE_CASE_PXL*y , "perso.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );
                faire_rendu();
                
            }
            if(touche == 4){
                x--;
                drawImage(TAILLE_CASE_PXL*x , TAILLE_CASE_PXL*y , "perso.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );
                faire_rendu();
                
            }
            if(touche == 5){
                running=0;
            }
            
            

        }      

    }
    Menu();
}
