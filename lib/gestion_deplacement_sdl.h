#include <SDL2/SDL.h>

/**
 * \file gestion_deplacement_sdl.c
 * \brief Primitives des fonctions de gestion du déplacement en SDL.
 * \author Thibault.C
 * \version 1.0
 * \date 04 avril 2022
 */

SDL_Event events;

/**
 * \fn int touche_detecter()
 * \brief Fonction permettant la détection de touches
 * \return retourne la valeur relative à la touche utilisée
 */
int touche_detecter();