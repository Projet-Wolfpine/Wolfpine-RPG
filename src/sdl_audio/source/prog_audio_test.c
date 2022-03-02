#include <SDL2/SDL.h>
#include "audio.h"

int main(void)
{
    /* Initialize only SDL Audio on default device */
    if(SDL_Init(SDL_INIT_AUDIO) < 0)
    {
        return 1; 
    }

    initAudio();
   

    playSound("son/punch.wav", SDL_MIX_MAXVOLUME / 4);
    SDL_Delay(1000);
    playSound("son/punch.wav", SDL_MIX_MAXVOLUME / 4);
    SDL_Delay(1000);
    playSound("son/punch.wav", SDL_MIX_MAXVOLUME / 4);
    SDL_Delay(100);
    playSound("son/punch.wav", SDL_MIX_MAXVOLUME / 4);
    SDL_Delay(100);
    playSound("son/punch.wav", SDL_MIX_MAXVOLUME / 4);
    SDL_Delay(100);
    playSound("son/punch.wav", SDL_MIX_MAXVOLUME / 4);
    SDL_Delay(500);
    playSound("son/punch.wav", SDL_MIX_MAXVOLUME / 4);
    SDL_Delay(500);
    playSound("son/punch.wav", SDL_MIX_MAXVOLUME / 4);
    SDL_Delay(300);
    playSound("son/punch.wav", SDL_MIX_MAXVOLUME / 4);
    SDL_Delay(300);
    playSound("son/punch.wav", SDL_MIX_MAXVOLUME / 4);
    SDL_Delay(300);
    playSound("son/punch.wav", SDL_MIX_MAXVOLUME / 4);
    SDL_Delay(300);
    playSound("son/punch.wav", SDL_MIX_MAXVOLUME / 4);
    SDL_Delay(500);
    playSound("son/punch.wav", SDL_MIX_MAXVOLUME / 4);
    SDL_Delay(150);
    playSound("son/punch.wav", SDL_MIX_MAXVOLUME / 4);
    SDL_Delay(150);
    playSound("son/punch.wav", SDL_MIX_MAXVOLUME / 4);
    SDL_Delay(300);
    playSound("son/punch.wav", SDL_MIX_MAXVOLUME / 4);
    SDL_Delay(300);
    playSound("son/punch.wav", SDL_MIX_MAXVOLUME / 4);
    SDL_Delay(300);
    playSound("son/punch.wav", SDL_MIX_MAXVOLUME / 4);
    SDL_Delay(300);
    playSound("son/punch.wav", SDL_MIX_MAXVOLUME / 4);
    SDL_Delay(150);
    playSound("son/punch.wav", SDL_MIX_MAXVOLUME / 4);
    SDL_Delay(150);
    
    
    endAudio();

    SDL_Quit();

    return 0;
}
