#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "Tvector.h"
#include "Keyboard.h"
#include "NPC_move.h"
#include <fstream>
#include <cmath>
#include <iostream>


float x = 0.0;
float y = 0.0;
Map* map = nullptr;
GameObject* igralec;
GameObject* mama;
GameObject* tjulen;
GameObject* tjulen2;
GameObject* tjulen3;
GameObject* farma = nullptr;
GameObject* bad;
GameObject* bad2;
Controller* ploscek = nullptr;
move* sovraznik = nullptr;
move* sovraznk2 = nullptr;
move* sovraznk3 = nullptr;
int lv;


SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
SDL_UserEvent Game::user;



Game::Game() {
	
}

Game::~Game() {

}

void Game::init(const char* ime, int x_pos, int y_pos, int sirina, int visina, bool fullscreen, int tmp, int lv) {
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

	
	//meni_text = SDL_CreateTextureFromSurface(renderer, tmpSurface);


	
	if (lv == 1) {
		mama = new GameObject("slikce/Old_woman.png", 500.0f, 500.0f, 100, 100);
		bad = new GameObject("slikce/Old_woman.png", 20.0f, 500.0f, 100, 100);
		bad2 = new GameObject("slikce/Old_woman.png", 100.0f, 500.0f, 100, 100);
		tjulen = new GameObject("slikce/tjulen.png", 300.0f, 300.0f, 50, 50);
		tjulen2 = new GameObject("slikce/tjulen.png", 300.0f, 100.0f, 50, 50);
		tjulen3 = new GameObject("slikce/tjulen.png", 500.0f, 50.0f, 50, 50);
	}
	else if (lv == 2) {
		mama = new GameObject("slikce/Old_woman.png", 500.0f, 500.0f, 100, 100);
		bad = new GameObject("slikce/Old_woman.png", 300.0f, 300.0f, 100, 100);
		bad2 = new GameObject("slikce/Old_woman.png", 100.0f, 500.0f, 100, 100);
		tjulen = new GameObject("slikce/tjulen.png", 300.0f, 300.0f, 50, 50);
		tjulen2 = new GameObject("slikce/tjulen.png", 300.0f, 100.0f, 50, 50);
		tjulen3 = new GameObject("slikce/tjulen.png", 500.0f, 50.0f, 50, 50);
	}
	else if (lv == 3) {
		mama = new GameObject("slikce/Old_woman.png", 500.0f, 500.0f, 100, 100);
		bad = new GameObject("slikce/Old_woman.png", 20.0f, 500.0f, 100, 100);
		bad2 = new GameObject("slikce/Old_woman.png", 100.0f, 500.0f, 100, 100);
		tjulen = new GameObject("slikce/tjulen.png", 300.0f, 300.0f, 50, 50);
		tjulen2 = new GameObject("slikce/tjulen.png", 300.0f, 100.0f, 50, 50);
		tjulen3 = new GameObject("slikce/tjulen.png", 500.0f, 50.0f, 50, 50);
	}


	igralec = new GameObject("slikce/Woodcutter.png", 0.0f, 0.0f, 100, 100); //tuki ustavs pot do igralca
	farma = new GameObject("slikce/farm.png", 0.0f, 0.0f, 100, 100);
	map = new Map();
	ploscek = new Controller(igralec);
	sovraznik = new move(mama, igralec, tjulen);
	sovraznk2 = new move(bad, igralec, tjulen2);
	sovraznk3 = new move(bad2, igralec, tjulen3);
	

	//radij = new collider(igralec);
	//Controller ploscek(igralec);
}

void Game::dela() {



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



void Game::update(int lv, bool repl) {
	
	ploscek->update();
	tjulen->Update(0,repl);
	tjulen2->Update(0,repl);
	tjulen3->Update(0,repl);
	igralec->Update(3,repl);
	farma->Update(0,repl);
	

	
	int speed = 0;
	if (lv == 1) {
		mama->Update(0.5,repl);
		bad->Update(0.5,repl);
		bad2->Update(0.5,repl);
	}
	else if (lv == 2) {
		mama->Update(1,repl);
		bad->Update(1,repl);
		bad2->Update(1,repl);
	}
	else if (lv == 3) {
		mama->Update(1.5,repl);
		bad->Update(1.5,repl);
		bad2->Update(1.5,repl);
	}
	
	pozicije a;
	std::ofstream plejr("igralec.bin", std::ios::binary | std::ios::app);
	a.x = igralec->GetOriginqX();
	a.y = igralec->GetOriginqY();
	plejr.write((char*)&a, sizeof(a));
	plejr.close();
}
	

//preverjanje ali je igralec v blizini naspretnika in ko ga opazi ga začne loviti
void Game::lovljenje() {
	int radius = 100;
	/*if (sqrt(pow(igralec->GetOriginX() - mama->GetOriginX(), 2) + pow(igralec->GetOriginY() - mama->GetOriginY(), 2)) >= radius + radius)
	{
		//SDL_SetTextureColorMod(texture, 255, 255, 255);
		return false;
		std::cout << "lepa";
	}
	//SDL_SetTextureColorMod(texture, 255, 0, 0);
	std::cout << "haha";
	return true;*/
	if (sqrt(pow(igralec->GetOriginX() - mama->GetOriginX(), 2) + pow(igralec->GetOriginY() - mama->GetOriginY(), 2)) >= radius + radius) {
		//std::cout << "lepa\n";
		tjulen->position.x;
		tjulen->position.y;
		sovraznik->update2();
	}
	else {
		igralec->position.x;
		igralec->position.y;
		//std::cout << "haha\n";
		event.user.data1 = 0; 
		sovraznik->update1();

	}
	if (sqrt(pow(igralec->GetOriginX() - bad->GetOriginX(), 2) + pow(igralec->GetOriginY() - bad->GetOriginY(), 2)) >= radius + radius) {
		//std::cout << "lepa\n";
		tjulen->position.x;
		tjulen->position.y;
		sovraznk2->update2();
	}
	else {
		igralec->position.x;
		igralec->position.y;
		//std::cout << "haha\n";
		event.user.data1 = 0;
		sovraznk2->update1();

	}
	if (sqrt(pow(igralec->GetOriginX() - bad2->GetOriginX(), 2) + pow(igralec->GetOriginY() - bad2->GetOriginY(), 2)) >= radius + radius) {
		//std::cout << "lepa\n";
		tjulen->position.x;
		tjulen->position.y;
		sovraznk3->update2();
	}
	else {
		igralec->position.x;
		igralec->position.y;
		//std::cout << "haha\n";
		event.user.data1 = 0;
		sovraznk3->update1();

	}
}



void Game::Dogajanje() {
	SDL_RenderClear(renderer);

	//std::cout << igralec->GetOriginqX()<<" || "<< igralec->GetOriginqY() << std::endl;
	map->DrawMap();
	
	farma->Render();
	mama->Render();
	bad2->Render();
	bad->Render();
	tjulen->Render();
	tjulen2->Render();
	tjulen3->Render();
	igralec->Render();
	
	//Igralca naspretnik ubije
	if (sqrt(pow(igralec->GetOriginX() - mama->GetOriginX(), 2) + pow(igralec->GetOriginY() - mama->GetOriginY(), 2)) >= 20 + 25 ){
	//SDL_SetTextureColorMod(texture, 255, 255, 255);
	igralec->Render();
	//std::cout << igralec->GetOriginqX() <<std:: endl;
	}
	else {
		//SDL_SetTextureColorMod(texture, 255, 0, 0);
		//std::cout << "-";
		event.type = SDL_QUIT;

	}
	if (sqrt(pow(igralec->GetOriginX() - bad->GetOriginX(), 2) + pow(igralec->GetOriginY() - bad->GetOriginY(), 2)) >= 20 + 25 ) {
		//SDL_SetTextureColorMod(texture, 255, 255, 255);
		igralec->Render();
		//std::cout << igralec->GetOriginqX() <<std:: endl;
	}
	else {
		//SDL_SetTextureColorMod(texture, 255, 0, 0);
		//std::cout << "-";
		event.type = SDL_QUIT;

	}
	if (sqrt(pow(igralec->GetOriginX() - bad2->GetOriginX(), 2) + pow(igralec->GetOriginY() - bad2->GetOriginY(), 2)) >= 20 + 25 ) {
		//SDL_SetTextureColorMod(texture, 255, 255, 255);
		igralec->Render();
		//std::cout << igralec->GetOriginqX() <<std:: endl;
	}
	else {
		//SDL_SetTextureColorMod(texture, 255, 0, 0);
		//std::cout << "-";
		event.type = SDL_QUIT;

	}
	
	///////////////////////////////////////////////////////////////////////////////
	//Če se dotakne igralec/nasprotnik tjulna se premakne ali na farmo ali pa ga ukradejo
	if (sqrt(pow(mama->GetOriginX() - tjulen->GetOriginX(), 2) + pow(mama->GetOriginY() - tjulen->GetOriginY(), 2)) >= 20 + 25) {
		tjulen->Render();
		if (sqrt(pow(igralec->GetOriginX() - tjulen->GetOriginX(), 2) + pow(igralec->GetOriginY() - tjulen->GetOriginY(), 2)) >= 20 + 25) {
			//SDL_SetTextureColorMod(texture, 255, 255, 255);
		}
		else {
			//SDL_SetTextureColorMod(texture, 255, 0, 0)
			tjulen = new GameObject("slikce/tjulen.png", 0.0f, 0.0f, 50, 50);
			tmp++;
		}

	}
	else {
		//std::cout << "zogdil se je";
		tjulen = new GameObject("slikce/tjulen.png", 700.0f, 10.0f, 50, 50);
	}


	if (sqrt(pow(bad->GetOriginX() - tjulen2->GetOriginX(), 2) + pow(bad->GetOriginY() - tjulen2->GetOriginY(), 2)) >= 20 + 25) {
		tjulen2->Render();
		if (sqrt(pow(igralec->GetOriginX() - tjulen2->GetOriginX(), 2) + pow(igralec->GetOriginY() - tjulen2->GetOriginY(), 2)) >= 20 + 25) {
			//SDL_SetTextureColorMod(texture, 255, 255, 255);
		}

		else {
			//SDL_SetTextureColorMod(texture, 255, 0, 0)
			tjulen2 = new GameObject("slikce/tjulen.png", 0.0f, 0.0f, 50, 50);
			tmp++;
		}
	}
	else {
		tjulen2 = new GameObject("slikce/tjulen.png", 700.0f, 10.0f, 50, 50);
	}



	if (sqrt(pow(bad2->GetOriginX() - tjulen3->GetOriginX(), 2) + pow(bad2->GetOriginY() - tjulen3->GetOriginY(), 2)) >= 20 + 25) {
		tjulen3->Render();
		if (sqrt(pow(igralec->GetOriginX() - tjulen3->GetOriginX(), 2) + pow(igralec->GetOriginY() - tjulen3->GetOriginY(), 2)) >= 20 + 25) {
			//SDL_SetTextureColorMod(texture, 255, 255, 255);
		}

		else {
			//SDL_SetTextureColorMod(texture, 255, 0, 0);
			tjulen3 = new GameObject("slikce/tjulen.png", 0.0f, 0.0f, 50, 50);
			tmp++;
		}
	}
	else {
		tjulen3 = new GameObject("slikce/tjulen.png", 700.0f, 10.0f, 50, 50);
	}
	
	SDL_RenderPresent(renderer);
}

int Game::level() {
	if (tmp == 3)
		return 3;
}

void Game::clean() {

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
