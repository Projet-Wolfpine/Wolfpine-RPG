#include "gestion_deplacement_sdl.h"
#include "fonction_sdl.h"
#include <SDL2/SDL.h>

SDL_Event event;

int touche_detecter(){ 
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
