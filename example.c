#include <stdio.h>
#include <math.h>
#include "daniel_renderer.h"

int t = 0;

void render() {
	setColor(255,255,255,255);
	clear();
	setColor(255,0,0,255);

	for (int i=0; i < screen.width; i++){
		int x = i;
		int y = screen.height/2 + sin((float)(x*10+t)/1000.0)*100;
		point(x,y);
	}
	t++;
}

int main(void) {
	init();
	printf("screen = %d:%d\n", screen.width, screen.height);
	fflush(stdout);
	show(render);
	quit();
}


