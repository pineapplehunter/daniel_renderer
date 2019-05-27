#ifndef DANIEL_RENDERER
#define DANIEL_RENDERER

struct Screen{
	int width;
	int height;
};

struct Screen screen;

void init();
int quit();

void setColor(char r, char g, char b, char a);
void point(int x, int y);
void clear();
void show(void (*)(void));

#endif
