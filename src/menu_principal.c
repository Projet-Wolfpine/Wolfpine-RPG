#include "affichage_sdl.h"
#include "fonction_sdl.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include  "game.h"


TTF_Font *police;
SDL_DisplayMode dm;

//#define TAILLE_CASE_PXL2 63



void Menu(){
	int longeur = 1920;
	int hauteur = 1080;
	int largeur = dm.w;
	int running=-1; //la variable qui gère le choix du menu
	char list[4][30] = { "Nouvelle partie", "Charger une Sauvegarde", "Options", "Quitter" };
	running = afficher_menu(list);

	if(running==0){
		start();
	}
	if(running==1){
		fond_rouge();
		SDL_Delay(1000);
		
	}
	if(running==2){
		fond_vert();
		SDL_Delay(1000);
	}
	if(running==3){
		quitter_affichage();
	}
}


/*
	drawImage(500, 500 , "cadre.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );
		faire_rendu();
		SDL_Delay(500);
		map();
		drawImage(550, 500 , "cadre.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );
		faire_rendu();
		SDL_Delay(500);
		map();
		drawImage(600, 500 , "cadre.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );
		faire_rendu();
		SDL_Delay(500);
		map();
		drawImage(625, 500 , "cadre.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );
		faire_rendu();
		SDL_Delay(500);
		map();
		drawImage(650, 500 , "cadre.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );
		faire_rendu();
		SDL_Delay(500);
		map();
		drawImage(700, 500 , "cadre.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );
		faire_rendu();
		SDL_Delay(500);
		map();
		drawImage(725, 500 , "cadre.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );
		faire_rendu();
		SDL_Delay(500);
		map();
		drawImage(750, 500 , "cadre.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );
		faire_rendu();




		int longeur_mat = longeur/TAILLE_CASE_PXL;
		int hauteur_mat = hauteur/TAILLE_CASE_PXL;

		//Test de la création matrice terminal
		case_t mat[Y][X];
   		perso_t *joueur;
  		init_mat(mat);
		contour_mat(mat);
		placer_pers(mat,1,30,joueur);



		map();

		//affichage personnage 

		drawImage(1*TAILLE_CASE_PXL, 30*TAILLE_CASE_PXL , "cadre.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );//probleme au niveau de l'affichage surement du à un soucis de Y X et cette fonction est en X Y
		faire_rendu();

		SDL_Delay(5000);

		*/