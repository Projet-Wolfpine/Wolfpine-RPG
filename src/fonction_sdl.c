#include <dirent.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "fonction_sdl.h"

SDL_Renderer * renderer; 
int nb_images=0;
TTF_Font *police;

SDL_Texture * images[200];
char ** noms;

void loadImages(){
	printf("Chargement des images...\n");
	DIR *d;
	struct dirent *dir;

	d = opendir("./images/");
	while ((dir = readdir(d)) != NULL) nb_images++;
	closedir(d);

	noms = malloc(sizeof(char*)*nb_images);

	d = opendir("./images/");
	for (int i=0;(dir = readdir(d)) != NULL; i++){
		noms[i] = malloc(sizeof(char)*strlen(dir->d_name)+1);
		strcpy(noms[i], dir->d_name);
	}
	closedir(d);
	for(int i=0; i<nb_images; i++){
		char nom[50] = "./images/";
		strcat(nom, noms[i]);
		images[i] = IMG_LoadTexture(renderer, nom);
		if(i==22){
			printf("%s\n", nom);
		}
	}
	printf("Nombre d'images : %d\n", nb_images);
}

void unloadImages(){
	for(int i=0; i<nb_images; i++){
		SDL_DestroyTexture(images[i]);
	}
}

void faire_rendu(){
	SDL_RenderPresent(renderer);
}

void fond_blanc(){
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	faire_rendu();
}
void fond_rouge(){
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderClear(renderer);
	faire_rendu();
}
void fond_vert(){
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderClear(renderer);
	faire_rendu();
}
void fond_bleu(){
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderClear(renderer);
	faire_rendu();
}

void quitter_affichage(){
	unloadImages();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(fenetre);
	TTF_CloseFont(police);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

void drawText (int x, int y, char * string, int h, int w, SDL_Color color){
	SDL_Surface *texte = TTF_RenderUTF8_Blended(police, string, color);
	SDL_Texture *texte_tex = SDL_CreateTextureFromSurface(renderer, texte);
	SDL_FreeSurface(texte); /* on a la texture, plus besoin du texte */
	/* Position ou sera mis le texte dans la fenêtre */
	SDL_Rect txtDestRect;
	txtDestRect.x = x;
	txtDestRect.y = y;
	txtDestRect.h = h;
	txtDestRect.w = w*strlen(string);
	SDL_RenderCopy(renderer, texte_tex, NULL, &txtDestRect);
	SDL_DestroyTexture(texte_tex);
}


void drawImage (int x, int y, char * nom, int w, int h){
	// x et y les coordonnées,
	SDL_Rect imgDestRect;
	imgDestRect.x = x;
	imgDestRect.y = y;
	imgDestRect.w = w;
	imgDestRect.h = h;
  	char nom2[50];
  	sprintf(nom2, "%s", nom);
  	if(!strstr(nom2, ".png")){
    	strcat(nom2, ".png");
  	}
	int i;
	//ici on recherche quel est l'indice de l'image qu'on veux afficher
	for(i=0; strcmp(noms[i], nom2)!=0 && i<nb_images; i++);
	//on l'affiche ensuite
	SDL_RenderCopy(renderer, images[i], NULL, &imgDestRect);
	//SDL_DestroyTexture(image_tex);
}

void init_affichage(){

	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	
	SDL_DisplayMode dm;
	SDL_GetCurrentDisplayMode(0, &dm);
	police = TTF_OpenFont("./font/times.ttf", 35);
	SCREEN_HEIGHT = dm.h;
	SCREEN_WIDTH = dm.w;
	/* Création de la fenêtre */
	fenetre = SDL_CreateWindow("Projet Wolpine",SDL_WINDOWPOS_UNDEFINED,
													SDL_WINDOWPOS_UNDEFINED,
													SCREEN_WIDTH,
													SCREEN_HEIGHT,
													SDL_WINDOW_SHOWN);

	renderer=SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetWindowFullscreen(fenetre, SDL_WINDOW_BORDERLESS);//SDL_WINDOW_FULLSCREEN
	loadImages();
	
}

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
