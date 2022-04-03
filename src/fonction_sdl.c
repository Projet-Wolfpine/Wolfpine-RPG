#include <dirent.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "../lib/fonction_sdl.h"


/**
 * \file fonction_sdl.c
 * \brief Fonction d'affichage en SDL
 * \author Thibault.c
 * \version 1.1
 * \date 03/04/2022
 * 
 * Fonction affichage et de creation de la fenetre en sdl
 * 
 */

SDL_Renderer * renderer; /*!< Pointeur de rendu */
SDL_Texture * images[300]; /*!< Tableau de texturess des images de taille 300 */
TTF_Font *police; /*!< Pointeur sur la police utilisée */

int nb_images=0; /*!< Nombre d'images load dans le dossier images */
char ** noms; /*!<permet de sauvegarder le noms d'images dans un tableau*/

/**
 * \fn void loadImages()
 * \brief Chargement de toutes les textures présent dans le dossier ./images
 */

void loadImages(){
	printf("Chargement des images...\n");
	DIR *d;
	struct dirent *dir;

	d = opendir("../images/");
	while ((dir = readdir(d)) != NULL) nb_images++;
	closedir(d);

	noms = malloc(sizeof(char*)*nb_images);

	d = opendir("../images/");
	for (int i=0;(dir = readdir(d)) != NULL; i++){
		noms[i] = malloc(sizeof(char)*strlen(dir->d_name)+1);
		strcpy(noms[i], dir->d_name);
	}
	closedir(d);
	for(int i=0; i<nb_images; i++){
		char nom[50] = "../images/";
		strcat(nom, noms[i]);
		images[i] = IMG_LoadTexture(renderer, nom);
		if(i==22){
			printf("%s\n", nom);
		}
	}
	printf("Nombre d'images : %d\n", nb_images);
}

/**
 * \fn void unloadImages()
 * \brief free de toutes les textures présent dans le tableau images[i]
 */

void unloadImages(){
	for(int i=0; i<nb_images; i++){
		SDL_DestroyTexture(images[i]);
	}
}

/**
 * \fn void faire_rendu()
 * \brief Mise a jour de l'etat de rendu de l'ecran
 */

void faire_rendu(){
	SDL_RenderPresent(renderer);
}

/**
 * \fn void fond_blanc()
 * \brief fenêtre en blanc
 */

void fond_blanc(){
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	faire_rendu();
}

/**
 * \fn void fond_rouge()
 * \brief fenêtre en rouge
*/

void fond_rouge(){
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderClear(renderer);
	faire_rendu();
}

/**
 * \fn void fond_vert()
 * \brief fenêtre en vert
*/

void fond_vert(){
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderClear(renderer);
	faire_rendu();
}

/**
 * \fn void fond_bleu()
 * \brief fenêtre en bleu
*/

void fond_bleu(){
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderClear(renderer);
	faire_rendu();
}

/**
 * \fn void quitter_affichage()
 * \brief fonction qui permet de quitter le jeu proprement
 */

void quitter_affichage(){
	unloadImages();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(fenetre);
	TTF_CloseFont(police);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

/**
 * \fn void drawText (int x, int y, char * string, int h, int w, SDL_Color color)
 * \brief Affiche du texte d'une certaine taille à des coordonnées données
 * \param[in] Abscisse du texte
 * \param[in] Ordonnée du texte
 * \param[in] Contenu du texte
 * \param[in] Hauteur du texte
 * \param[in] Largeur du texte
 * \param[in] couleur du texte
 */

void drawText (int x, int y, char * string, int h, int w, SDL_Color color){
	SDL_Surface *texte = TTF_RenderUTF8_Blended(police, string, color);
	SDL_Texture *texte_tex = SDL_CreateTextureFromSurface(renderer, texte);
	SDL_FreeSurface(texte); /* free du texte */
	/* Position ou sera mis le texte dans la fenêtre */
	SDL_Rect txtDestRect;
	txtDestRect.x = x; // Abscisse du texte
	txtDestRect.y = y; // Ordonnée du texte
	txtDestRect.h = h; // Hauteur du texte
	txtDestRect.w = w*strlen(string); // Largeur du texte
	SDL_RenderCopy(renderer, texte_tex, NULL, &txtDestRect);
	SDL_DestroyTexture(texte_tex);
}


/**
 * \fn void drawImage (int x, int y, char * nom, int w, int h)
 * \brief Affiche de l'image d'une certaine taille à des coordonnées données
 * \param[in] Abscisse de l'image
 * \param[in] Ordonnée de l'image
 * \param[in] Nom de l'image
 * \param[in] Hauteur de l'image
 * \param[in] Largeur de l'image
 */

void drawImage (int x, int y, char * nom, int w, int h){
	SDL_Rect imgDestRect;
	imgDestRect.x = x; // Abscisse de l'image
	imgDestRect.y = y; // Ordonnée de l'image
	imgDestRect.w = w; // Hauteur de l'image
	imgDestRect.h = h; // Largeur de l'image
  	char nom2[50]; //  Nom de l'image
  	sprintf(nom2, "%s", nom);
  	if(!strstr(nom2, ".png")){
    	strcat(nom2, ".png");
  	}
	int i; // indice de l'image
	//ici on recherche quel est l'indice de l'image qu'on veux afficher
	for(i=0; strcmp(noms[i], nom2)!=0 && i<nb_images; i++);
	//on l'affiche ensuite
	SDL_RenderCopy(renderer, images[i], NULL, &imgDestRect);
}

/**
 * \fn void init_affichage()
 * \brief Affiche la fenêtre du jeu en fonction en plein ecran avec les fonctions de rendu de police et de chargement des images 
 */

void init_affichage(){
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	SDL_DisplayMode dm;
	SDL_GetCurrentDisplayMode(0, &dm);
	police = TTF_OpenFont("../font/times.ttf", 35);
	SCREEN_HEIGHT = 1080;
	SCREEN_WIDTH = 1920;
	/* Création de la fenêtre */
	fenetre = SDL_CreateWindow("Wolfpine",SDL_WINDOWPOS_UNDEFINED,
													SDL_WINDOWPOS_UNDEFINED,
													SCREEN_WIDTH,
													SCREEN_HEIGHT,
													SDL_WINDOW_SHOWN);

	renderer=SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
	SDL_Surface* iconSurface;
	iconSurface = SDL_LoadBMP("../images/wolfy.bmp");
	SDL_SetWindowIcon(fenetre, iconSurface);
	SDL_SetWindowFullscreen(fenetre, SDL_WINDOW_BORDERLESS);//SDL_WINDOW_FULLSCREEN
	loadImages();
	
}



/**
 * \fn afficher_image_menu(SDL_PRINTF_FORMAT_STRING char *nom)
 * \brief affiche l'image du fond dans le menu pricipal
* \param[in] nom de l'image
 */


void afficher_image_menu(SDL_PRINTF_FORMAT_STRING char *nom){
    image = IMG_Load(nom);
    if(image  == NULL){
        printf( "Erreur de chargement de l'image  ! \n");
    }
    SDL_Texture* pTextureImage = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
    SDL_RenderCopy(renderer, pTextureImage, NULL, NULL);
    SDL_RenderPresent(renderer);
}
