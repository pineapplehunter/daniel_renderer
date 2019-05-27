/*
MIT License

Copyright (c) 2019 Shogo Takata

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

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


