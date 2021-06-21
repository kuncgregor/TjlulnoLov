#pragma once

#include "meni.h"

class textura {

private:
public:
	static SDL_Texture* LoadTexture(std::string filePath);
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);

};