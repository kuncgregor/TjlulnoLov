#include "Meni_texture.h"
#include <cmath>



SDL_Texture* textura::LoadTexture(std::string filePath) {
	SDL_Surface* tempSurface = IMG_Load(filePath.c_str());
	SDL_Texture* tex = SDL_CreateTextureFromSurface(meni::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}

void textura::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest) {
	SDL_RenderCopy(meni::renderer, tex, &src, &dest);

}