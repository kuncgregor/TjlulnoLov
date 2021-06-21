
#include "npc.h"
#include "TextureManager.h"
#include <math.h>




NPC::NPC(const char* texturesheet, float x, float y, GameObject* igralec) {

	objTexture = TextureManager::LoadTexture(texturesheet);

	position.x = 0.0f;
	position.y = 0.0f;
}

void NPC::UpdateNPC(float xx, float yy) {

	
	igralec->RenderNPC();

	float razdalja = sqrt((xx - xpos) * (xx - xpos) + (yy - ypos) * (yy - ypos));

	if (razdalja < 50) {
		if(xx<xpos)
			position.x -= volocity.x * speed;
		else
			position.x -= volocity.x * speed;

		if(yy<ypos)
		    position.y -= volocity.y * speed;
		else
			position.y -= volocity.y * speed;
	}
	srcRect.h = 100;
	srcRect.w = 100;
	srcRect.x = 0;
	srcRect.y = 0;
	xpos = position.x;
	ypos = position.y;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;



	std::cout << "mama" << xpos << "," << ypos << std::endl;;
}

void NPC::RenderNPC() {

	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
