#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>


#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600



SDL_Window* window = NULL;
SDL_Surface* screen = NULL;

int main(int argc, char* args[]) {
	// Initialize video system
	SDL_Init(SDL_INIT_VIDEO); // Returns 0 on success

	window = SDL_CreateWindow("SDL2 Tutorial",
	                          SDL_WINDOWPOS_UNDEFINED,
	                          SDL_WINDOWPOS_UNDEFINED,
	                          SCREEN_WIDTH,
	                          SCREEN_HEIGHT,
	                          SDL_WINDOW_SHOWN); // Returns NULL on fail

	screen = SDL_GetWindowSurface(window);

	// Load image (returns NULL on fail)
	SDL_Surface* image = IMG_Load("assets/generic_platformer_tiles_1.png");

	SDL_Event e;
	uint8_t run = 1;
	while (run) {
		// Handle events
		while (SDL_PollEvent(&e)) {
			if(e.type == SDL_QUIT)
				run = 0;
		}

		// Render graphics
		SDL_FillRect(screen, NULL, 0x00000000);
		SDL_BlitSurface(image, NULL, screen, NULL);
		SDL_UpdateWindowSurface(window);
	}

	SDL_FreeSurface(image);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
