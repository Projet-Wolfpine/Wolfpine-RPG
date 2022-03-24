#include "gestion_deplacement_sdl.h"
#include "fonction_sdl.h"
#include <SDL2/SDL.h>

SDL_Event event;

int touche_detecter(){ 
    /*int touchev1=0;
    int touche=0;
    if(SDL_WaitEvent(&event) != 0){
        switch(event.type){
            case SDL_KEYDOWN:
                if((events.key.keysym.sym == SDL_SCANCODE_W) || (events.key.keysym.sym == SDLK_UP)){ // touche haut (W) en qwerty
                    printf("je suis la ! \n");
                    touche = 1; break;
                }
                if((events.key.keysym.sym == SDLK_s) || (events.key.keysym.sym == SDLK_DOWN)){ // touche bas (S) en qwerty
                    touche = 2; break;
                }
                if((events.key.keysym.sym == SDLK_d) || (events.key.keysym.sym == SDLK_RIGHT)){ // touche droite (D) en qwerty
                    touche = 3; break;
                }
                if((events.key.keysym.sym == SDLK_a) || (events.key.keysym.sym == SDLK_LEFT)){ // touche gauche (A) en qwerty
                    touche = 4; break;
                }
                if(events.key.keysym.sym == SDLK_ESCAPE){ // touche escap 
                    touche = 5; break;
                }
        }
    }state[SDL_SCANCODE_W])
    printf("sdl = %d\n",touche);*/
    /*int touche=0;
    const Uint8 *state = SDL_GetKeyboardState(NULL);
     if(state[SDL_SCANCODE_UP]){ // touche haut (Z)
        printf("la \n");
        touche = 1;
    }

    if(state[SDL_SCANCODE_F1]){ // touche bas (S)
        touche = 2;
    }

    if(state[SDL_SCANCODE_RIGHT]){ // touche droite (D)
        touche = 3;
                
    }
    if(state[SDL_SCANCODE_LEFT]){ // touche gauche (Q)
        touche = 4;
    }
    if(state[SDL_SCANCODE_ESCAPE]){ // touche escap 
        touche = 5;
    }
    
    printf("sdl = %d\n",touche);
    return touche;*/
    //SDL_Event event;
    if ( SDL_PollEvent(&event) ){
        switch(event.type){
            case SDL_KEYUP: // Événement de relâchement d'une touche clavier
                if ( event.key.keysym.sym == SDLK_UP){
                    return 1;
                }
                if ( event.key.keysym.sym == SDLK_DOWN){
                    return 2;
                }
                if ( event.key.keysym.sym == SDLK_RIGHT){
                    return 3;
                }
                 if ( event.key.keysym.sym == SDLK_LEFT){
                    return 4;
                }
                 if ( event.key.keysym.sym == SDLK_ESCAPE){
                    return 5;
                }
            break;
        }
    }
    return 0;

}