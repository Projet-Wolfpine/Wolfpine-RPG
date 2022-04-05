#include <SDL2/SDL.h>
#include <ncurses.h>
#include <SDL2/SDL_ttf.h>

/**
 * \file fonction_sdl.c
 * \brief Prototypes des fonctions d'affichage en SDL
 * \author Thibault.c
 * \version 1.1
 * \date 03/04/2022
 */

int SCREEN_HEIGHT;
int SCREEN_WIDTH;

void * fenetre;
SDL_Window*pWindow;
SDL_Renderer*renderer;
SDL_Surface *image;
SDL_DisplayMode dm;

void setcolor(int, int);

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
void drawText (int , int , char *, int, int, SDL_Color);

/**
 * \fn void drawImage (int x, int y, char * nom, int w, int h)
 * \brief Affiche de l'image d'une certaine taille à des coordonnées données
 * \param[in] Abscisse de l'image
 * \param[in] Ordonnée de l'image
 * \param[in] Nom de l'image
 * \param[in] Hauteur de l'image
 * \param[in] Largeur de l'image
 */
void drawImage (int , int , char *, int, int );

/**
 * \fn void init_affichage()
 * \brief Affiche la fenêtre du jeu en fonction en plein ecran avec les fonctions de rendu de police et de chargement des images 
 */
void init_affichage();

/**
 * \fn void loadImages()
 * \brief Chargement de toutes les textures présent dans le dossier ./images
 */
void loadImages();

/**
 * \fn void unloadImages()
 * \brief free de toutes les textures présent dans le tableau images[i]
 */
void unloadImages();
void showWindow();

/**
 * \fn void fond_blanc()
 * \brief fenêtre en blanc
 */
void fond_blanc();

/**
 * \fn void fond_rouge()
 * \brief fenêtre en rouge
*/
void fond_rouge();

/**
 * \fn void fond_vert()
 * \brief fenêtre en vert
*/
void fond_vert();

/**
 * \fn void fond_bleu()
 * \brief fenêtre en bleu
*/
void fond_bleu();

/**
 * \fn void faire_rendu()
 * \brief Mise a jour de l'etat de rendu de l'ecran
 */
void faire_rendu();
void quitter_sdl();

/**
 * \fn void quitter_affichage()
 * \brief fonction qui permet de quitter le jeu proprement
 */
void quitter_affichage();

/**
 * \fn afficher_image_menu(SDL_PRINTF_FORMAT_STRING char *nom)
 * \brief affiche l'image du fond dans le menu pricipal
 * \param[in] nom de l'image
 */
void afficher_image_menu(SDL_PRINTF_FORMAT_STRING char *nom);
