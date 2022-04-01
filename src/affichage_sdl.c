#include "affichage_sdl.h"
#include "fonction_sdl.h"
#include "string.h"
#include <SDL2/SDL.h>

TTF_Font *police;
SDL_Color jaune = {204, 154, 0};

int afficher_menu(char menu[4][30]){
  //afficher_image_menu("images/menu.jpeg");
  drawImage(0,0,"menu",1920,1080);// ou dm.x , dm.y 
  char * text;
  int largeur = SCREEN_WIDTH;
  printf("hauteur = %d\n",SCREEN_HEIGHT);
  printf("largeur = %d\n",SCREEN_WIDTH);
  text = "W O L F P I N E";
  int w;
	TTF_SizeText(police,text,&w,NULL);
  drawText((largeur-w)/2, 40, text, 45, 15, jaune);
  
  
  for(int i = 0, y=200; i<4; i++, y+=150){
    drawImage( 700, y, "button.png", 475, 130);
    drawText(800, y+45, menu[i], 25, 12, jaune);
  }
  faire_rendu();
  SDL_Event event;
  int running = -1;
  int souris_x=0, souris_y=0;
  SDL_GetMouseState(&souris_x, &souris_y);
  while(running == -1){
    if (SDL_WaitEvent(&event) != 0) {
      switch(event.type){
        case SDL_MOUSEBUTTONDOWN:
          SDL_GetMouseState(&souris_x, &souris_y);
          if((souris_x >= 700 && souris_x <=1175) && (souris_y >= 200 && souris_y <=330)){// ecart de 20 entre chaque cases et une case = 130
            running = 0; break;
          }
          if((souris_x >= 700 && souris_x <=1175) && (souris_y >= 350 && souris_y <=480)){
            running = 1;break;
          }
          if((souris_x >= 700 && souris_x <=1175) && (souris_y >= 500 && souris_y <=630)){
            running = 2; break;
          }
          if((souris_x >= 700 && souris_x <=1175) && (souris_y >= 650 && souris_y <=780)){
            running=3; break;
          }
      }
    }
  }
  return running;
}



#define TAILLE_MAX 1000 

void affichage_dialogue(char * id_PNJ){
  char  list[5][500];
  char id_perso[5];
  int i,j=0;
  FILE * fichier_dialogue;
  fichier_dialogue=fopen("dialogue.txt","r");
  for(i=0;i<7;i++){
    fscanf(fichier_dialogue, "%s", id_perso);
    if(strcmp(id_PNJ,id_perso) == 0){
          printf("\naffichage 1 : %s\n",id_perso);
          fgets(list[0], TAILLE_MAX, fichier_dialogue);
    }
    fscanf(fichier_dialogue, "%*[^\n]");
  }
  fclose(fichier_dialogue);
  printf("\naffichage 4: %s\n",list[0]);
}

