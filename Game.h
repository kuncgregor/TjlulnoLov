#pragma once


#include "SDL_image.h"

#include <iostream>

class Game {
private:
	int count = 0;
	float pos = 0;
	bool isRunning;
	SDL_Window* window;
	int tmp;
	int lv;
	


public:
	Game();
	~Game();

	struct pozicije
	{
		int x;
		int y;
	};

	void init(const char* ime, int x_pos, int y_pos, int sirina, int visina, bool fullscreen, int tmp, int lv);
		void dela();
		void update(int lv, bool repl);
		void lovljenje();
		void Dogajanje();
		void clean();
		
		int level();
		bool running() { return isRunning; }
		void okno() { SDL_DestroyWindow(window); }
	static SDL_Texture* texture;
	static SDL_Renderer* renderer;
	static SDL_Event event;
	static SDL_UserEvent user;
};