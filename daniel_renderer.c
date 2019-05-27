#include <stdlib.h>
#include <unistd.h>
#include <SDL2/SDL.h>
#include <math.h>

#include "daniel_renderer.h"

char initialized = 0;
SDL_Renderer * renderer;
SDL_Event event;
SDL_Window *window;

struct Screen screen;

void init(){
	int i;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN, &window, &renderer);
	SDL_ShowCursor(SDL_DISABLE);
	
	SDL_GetRendererOutputSize(renderer, &screen.width, &screen.height);
	initialized = 1;
}

int quit(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);    
	SDL_Quit();
	return EXIT_SUCCESS;
}

void setColor(char r,char g,char b,char a){
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void clear(){
	SDL_RenderClear(renderer);
}

void point(int x, int y){
	SDL_RenderDrawPoint(renderer,x,y);
}

void show(void (*f)(void)){
	while(1){
		if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
			break;	
		f();
		SDL_RenderPresent(renderer);
	}
}


