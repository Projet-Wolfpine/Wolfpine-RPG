#include "../lib/affichage_sdl.h"
#include "../lib/fonction_sdl.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include  "../lib/game.h"

/**
 * \file menu_principal.c
 * \brief Fonctions d'affichage du menu
 * \author Thibault.C
 * \version 1.0
 * \date 04 avril 2022
 */

TTF_Font *police;

/**
 * \fn void Menu()
 * \brief Fonction permettant de charger le menu
 */
void Menu(){
	SDL_Color rouge = {192, 0, 26};
	SDL_DisplayMode dm;
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
		//charger_jeu(mat,&joueur,nom_map);
		//printf("%d,%d,%s",joueur.anc_coord_y,joueur.anc_coord_x,nom_map);
		drawImage( 700, 350, "button.png", 475, 130);
    	drawText(800, 395, "Pas de sauvegarde ", 25, 12, rouge);
		faire_rendu();
		SDL_Delay(1000);
		SDL_RenderClear(renderer);
		Menu();
	}
	if(running==2){
		fond_vert();
		SDL_Delay(1000);
	}
	if(running==3){
		quitter_affichage();
	}
}