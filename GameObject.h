#pragma once

#include "Game.h"
#include "Tvector.h"

class GameObject {

private:

	float xpos;
	float ypos;
	//int speed = 0;
	int radius = 100;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;


public:

	Vector2D position;
	Vector2D volocity;
	



	GameObject(const char* texturesheet, float x, float y, int h, int w);
	~GameObject();


	void Update(float speed, bool repl);

	void Render();

	/*void premikanje() {

		position.x += volocity.x * speed;
		position.y += volocity.y * speed;

		volocity.x = 0;
		volocity.y = 0;


	}*/

	int GetOriginX();
	int GetOriginY();
	int GetOriginqX();
	int GetOriginqY();


};