#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        return EXIT_FAILURE;
    }
	SDL_Surface *texte=NULL, *image=NULL;
    	SDL_Window* pWindow = NULL;   
    	SDL_Renderer *pRenderer=NULL;
	SDL_Rect txtDestRect,imgDestRect;

 	pWindow = SDL_CreateWindow("Prog",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,640,480,SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);
 	
	if(!pWindow){
		fprintf(stderr, "Erreur à la création de la fenetre : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
	
	if(pRenderer == NULL){
		fprintf(stderr, "Erreur à la création du renderer\n");
		exit(EXIT_FAILURE);
	}

	SDL_Surface* image = IMG_Load("image.png");
	if(!image){
    	printf("Erreur de chargement de l'image : %s",SDL_GetError());
    	return -1;
	}


	if( pWindow ){
		int running = 1; 
		while(running) {
			SDL_Event events;
			while (SDL_PollEvent(&events)) {
        		switch(events.type){
        			case SDL_WINDOWEVENT:
            		if (events.window.event == SDL_WINDOWEVENT_CLOSE)
                		running = SDL_FALSE;
                		break;
        			case SDL_KEYDOWN:
            		SDL_Log("+key");
            		if (events.key.keysym.scancode == SDL_SCANCODE_W)
                		SDL_Log("Scancode W");
            		if (events.key.keysym.scancode == SDL_SCANCODE_A)
                		SDL_Log("Scancode A");
            		if (events.key.keysym.scancode== SDL_SCANCODE_S)
                		SDL_Log("Scancode S");
					if (events.key.keysym.scancode == SDL_SCANCODE_D)
                		SDL_Log("Scancode D");
                	if (events.key.keysym.scancode == SDL_SCANCODE_F1)
                		SDL_Log("Scancode F1");
            		break;
			
        			case SDL_KEYUP: 
            			SDL_Log("-key");
            			break;
        			case SDL_MOUSEBUTTONDOWN: // Click de souris 
            			SDL_Log("+clic");
            			break;
        			case SDL_MOUSEBUTTONUP: // Click de souris relâché
            			SDL_Log("-clic");
            			break;
        			case SDL_MOUSEWHEEL: // Scroll de la molette
            			SDL_Log("wheel");
            			break;
        		}
    		}
		}
	} 
	else {
		fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
	}

	//Destruction de la fenetre
	SDL_DestroyWindow(pWindow);
    SDL_Quit();	

    return EXIT_SUCCESS;
}
