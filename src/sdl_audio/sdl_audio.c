#include <stdio.h>
#include <SDL2/SDL.h> 
#include <stdlib.h>

int main(int argc, char* argv[]) 
{
    if (SDL_Init(SDL_INIT_AUDIO) < 0)
        return -1;

    SDL_AudioSpec spec;

    SDL_memset(&spec, 0, sizeof(spec));

    spec.freq = 96000; // 4 100 Hz, 48 000 Hz, 96 000 Hz, 192 000 Hz (standard) 
    spec.format = AUDIO_F32SYS;
    spec.channels = 1;
    spec.samples = 4096; // Oublier pas que ce sa doit être en puissance de deux 2^n
	spec.callback = [](void* param, Uint8* stream, int len)
	{
		// Envoyez les données dans notre buffer...
		int samples = len / sizeof(float); // 4096

		for (auto i = 0; i < samples; i++)
		{
		    reinterpret_cast<float*>(stream)[i] = 0.5 * SDL_sinf(2 * M_PI * i / 1000);
		}
	};

    SDL_AudioDeviceID dev = SDL_OpenAudioDevice(nullptr, 0, &spec, &spec, SDL_AUDIO_ALLOW_FREQUENCY_CHANGE);

    SDL_PauseAudioDevice(dev, SDL_FALSE);

    for (;;); // boucle infinie

    SDL_Quit();

    return 0;
}
