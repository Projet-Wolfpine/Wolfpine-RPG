#include <SDL2/SDL.h>
#include <ncurses.h>
#include <SDL2/SDL_ttf.h>

int SCREEN_HEIGHT;
int SCREEN_WIDTH;
int SPRITE_W;

void * fenetre;
SDL_Window*pWindow;
SDL_Renderer*renderer;
SDL_Surface *image;
SDL_DisplayMode dm;

void setcolor(int, int);
void drawText (int , int , char *, int, int);
void drawImage (int , int , char *, int, int );
void init_affichage();
void loadImages();
void unloadImages();
void showWindow();
void fond_blanc();
void fond_rouge();
void fond_vert();
void fond_bleu();
void faire_rendu();
void quitter_sdl();
void quitter_affichage();
void afficher_image_menu(SDL_PRINTF_FORMAT_STRING char *nom);
