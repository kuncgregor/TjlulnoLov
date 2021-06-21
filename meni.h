#pragma once


#include "SDL_image.h"

#include <iostream>

class meni {
private:
	int count = 0;
	float pos = 0;
	bool isRunning;
	SDL_Window* window;
	int tmp;
	int lv;



public:
	meni();
	~meni();

	void init(const char* ime, int x_pos, int y_pos, int sirina, int visina, bool fullscreen, int tmp);
	void dela();
	void update();
	void Dogajanje();
	int stanje();
	void clean();
	
	bool running() { return isRunning; }
	void okno() { SDL_DestroyWindow(window); }
	static SDL_Texture* texture;
	static SDL_Renderer* renderer;
	static SDL_Event event;
	static SDL_UserEvent user;
}; 