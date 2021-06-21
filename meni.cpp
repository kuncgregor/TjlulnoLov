#include "Game.h"
#include "Meni_texture.h"
#include "GameObject.h"
#include "Map.h"
#include "Tvector.h"
#include "Keyboard.h"
#include "NPC_move.h"
#include "meni.h"
#include <cmath>
#include <iostream>


SDL_Renderer* meni::renderer = nullptr;
SDL_Event meni::event;
SDL_UserEvent meni::user;

SDL_Texture* meni_text;

bool enter;
int tmp = 0;

meni::meni() {

}

meni::~meni() {

}

void meni::init(const char* ime, int x_pos, int y_pos, int sirina, int visina, bool fullscreen, int tmp) {
	int ekran = 0;
	if (fullscreen) {
		ekran = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		//std::cout << "lul" << std::endl;

		window = SDL_CreateWindow(ime, x_pos, y_pos, sirina, visina, ekran);
		if (window) {
			//std::cout << "dela zaslon" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {

			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			//std::cout << "renderer dela" << std::endl;

		}
		isRunning = true;

	}
	else {
		isRunning = false;
	}
	//GameObject mama("slikce/Old_woman.png", 0, 0);
	//GameObject igralec("slikce/Woodcutter.png", 0.00, 0.00);


	
	SDL_Surface* tmpSurface = IMG_Load("slikce/MENI.png");
	meni_text = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	
	SDL_FreeSurface(tmpSurface);
	//kazalec = new GameObject("slikce/Woodcutter.png", 500.0f, 500.0f, 100, 100); //tuki ustavs pot do igralca
	//skrin = new GameObject("slikce/MENI.png", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640);
	//radij = new collider(igralec);
	//Controller ploscek(igralec);
}

void meni::dela() {


	SDL_PollEvent(&event);
	/*while (event.type != SDL_QUIT) {

	}*/
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
	default:
		break;
	}
}



void meni::update() {

	//kazalec->Update(0);
	//skrin->Update(0);
}



void meni::Dogajanje() {
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, meni_text, NULL, NULL);
	//skrin->Render();
	//kazalec->Render();
	
	if (meni::event.type == SDL_MOUSEBUTTONDOWN || meni::event.type == SDL_MOUSEMOTION) {

		if (meni::event.button.button == SDL_BUTTON_LEFT 
			&& meni::event.motion.x >= 273 && meni::event.motion.x <= 543
			&& meni::event.motion.y >= 200 && meni::event.motion.y <= 300) {
			
			//if (tmp != 0)
			tmp = 1;

			if (meni::event.key.keysym.sym == SDLK_KP_ENTER)
			enter = true;
		}
		if (meni::event.button.button == SDL_BUTTON_LEFT
			&& meni::event.motion.x >= 273 && meni::event.motion.x <= 543
			&& meni::event.motion.y >= 315 && meni::event.motion.y <= 380) {

			//if (tmp != 0)
			tmp = 2;
			std::cout << "kliknu";

			if (meni::event.key.keysym.sym == SDLK_KP_ENTER)
				enter = true;
		}
		if (meni::event.button.button == SDL_BUTTON_LEFT
			&& meni::event.motion.x >= 273 && meni::event.motion.x <= 543
			&& meni::event.motion.y >= 390 && meni::event.motion.y <= 480) {

			//if (tmp != 0)
			tmp = 3;
			
			if (meni::event.key.keysym.sym == SDLK_KP_ENTER)
				enter = true;
		}
	}


	
	SDL_RenderPresent(renderer);
}

int meni::stanje() {

	if (tmp == 1)
		return 1;
	if (tmp == 2)
		return 2;
	if (tmp == 3)
		return 3;

	
	//if (tmp == 2 && enter == true)
		//tocke();
}



void meni::clean() {

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
