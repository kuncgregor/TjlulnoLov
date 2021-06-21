#include "GameObject.h"
#include "Game.h"
#include "TextureManager.h"
#include "Meni_texture.h"
#include "Tvector.h"
#include "meni.h"
#include <fstream>



GameObject::GameObject(const char* texturesheet, float x, float y, int h, int w) {

	objTexture = TextureManager::LoadTexture(texturesheet);

	position.x = x;
	position.y = y;
	srcRect.h = h;
	srcRect.w = w;
}

GameObject::~GameObject()
{
}

void GameObject::Update(float speed, bool repl) {


	if (repl!=true){
	position.x += volocity.x * speed;
	position.y += volocity.y * speed;


	}
	else{
	//std::cout << position.y << std::endl;
	struct Game::pozicije a;
	std::ifstream plejr("igralec.bin", std::ios::binary);
	if (plejr.is_open()) {
		while (plejr.read((char*)&a, sizeof(a))) {
			position.x = a.x;
			position.y = a.y;
		}
	}
	}

	srcRect.x = 0;
	srcRect.y = 0;
	xpos = position.x;
	ypos = position.y;


	//std::cout << xpos << std::endl;
	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;

	
	//std::cout << xpos << ypos << std::endl;
}

int GameObject::GetOriginX() { return xpos; }// + radius; }
int GameObject::GetOriginY() { return ypos; }// + radius; }
int GameObject::GetOriginqX() { return xpos - radius; }
int GameObject::GetOriginqY() { return ypos - radius; }


void GameObject::Render() {

SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}