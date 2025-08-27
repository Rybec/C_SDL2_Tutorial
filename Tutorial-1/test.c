#include <SDL2/SDL.h>
#include <stdio.h>


#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600



SDL_Window* window = NULL;
SDL_Surface* screen = NULL;

int main(int argc, char* args[]) {
	SDL_Init(SDL_INIT_VIDEO); // Returns 0 on success

	window = SDL_CreateWindow("SDL2 Tutorial",
	                          SDL_WINDOWPOS_UNDEFINED,
	                          SDL_WINDOWPOS_UNDEFINED,
	                          SCREEN_WIDTH,
	                          SCREEN_HEIGHT,
	                          SDL_WINDOW_SHOWN); // Returns NULL on fail

	screen = SDL_GetWindowSurface(window);

	SDL_Event e;
	uint8_t run = 1;
	while (run) {
		while (SDL_PollEvent(&e)) {
			if(e.type == SDL_QUIT)
				run = 0;
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
