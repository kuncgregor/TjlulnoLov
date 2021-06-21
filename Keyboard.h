#pragma once

#include "Game.h"
#include "GameObject.h"

class Controller {

public:
	GameObject* premik;
	//GameObject* igralec;
	Controller(GameObject* miha) {
		premik = miha;
	}


	


	void update() {
		
			if (Game::event.type == SDL_KEYDOWN) {
				switch (Game::event.key.keysym.sym)
				{
				case SDLK_w:
					premik->volocity.y = -1;
					break;
				case SDLK_a:
					premik->volocity.x = -1;
					break;
				case SDLK_d:
					premik->volocity.x = 1;
					break;
				case SDLK_s:
					premik->volocity.y = 1;
					break;

				default:
					break;
				}
			}
			if (Game::event.type == SDL_KEYUP) {
				switch (Game::event.key.keysym.sym)
				{
				case SDLK_w:
					premik->volocity.y = 0;
					break;
				case SDLK_a:
					premik->volocity.x = 0;
					break;
				case SDLK_d:
					premik->volocity.x = 0;
					break;
				case SDLK_s:
					premik->volocity.y = 0;
					break;

				default:
					break;
				}

			}
		
	}

	


};