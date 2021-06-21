#include "TextureManager.h"
#include <cmath>



SDL_Texture* TextureManager::LoadTexture(std::string filePath) {
	SDL_Surface* tempSurface = IMG_Load(filePath.c_str());
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest) {
	SDL_RenderCopy(Game::renderer, tex, &src, &dest);

}