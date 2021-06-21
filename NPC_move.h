#include "Game.h"
#include "GameObject.h"
#include "GameObject.h"
#include <iostream>

class move {

public:
	GameObject* vol;
	GameObject* pos;
	GameObject* hrana;
	move(GameObject* miha, GameObject* igralec, GameObject* tjuln) {
		vol = miha;
		pos = igralec;
		hrana = tjuln;
	}

	void update1() {
		//std::cout << "to se \n";
		if (Game::event.user.data1 == 0) {
			switch (pos->position.x > vol->position.x)
			{
			case 1:
				vol->volocity.x = 1;
				break;
			case 0:
				vol->volocity.x = -1;
				break;

			default:
				break;
			}
			switch (pos->position.y > vol->position.y)
			{
			case 1:
				vol->volocity.y = 1;
				break;
			case 0:
				vol->volocity.y = -1;
				break;
			default:
				break;
			}
			/*switch (pos->position.x > vol2->position.x)
			{
			case 1:
				vol2->volocity.x = 1;
				break;
			case 0:
				vol2->volocity.x = -1;
				break;

			default:
				break;
			}
			switch (pos->position.y > vol2->position.y)
			{
			case 1:
				vol2->volocity.y = 1;
				break;
			case 0:
				vol2->volocity.y = -1;
				break;
			default:
				break;
			}
			switch (pos->position.x > vol3->position.x)
			{
			case 1:
				vol3->volocity.x = 1;
				break;
			case 0:
				vol3->volocity.x = -1;
				break;

			default:
				break;
			}
			switch (pos->position.y > vol3->position.y)
			{
			case 1:
				vol3->volocity.y = 1;
				break;
			case 0:
				vol3->volocity.y = -1;
				break;
			default:
				break;
			}
		}
		/*else {
			switch (hrana->position.x > vol->position.x)
			{
			case 1:
				vol->volocity.x = 1;
				break;
			case 0:
				vol->volocity.x = -1;
				break;

			default:
				break;
			}
			switch (hrana->position.y > vol->position.y)
			{
			case 1:
				vol->volocity.y = 1;
				break;
			case 0:
				vol->volocity.y = -1;
				break;
			default:
				break;
			}
		}*/

		/*else {

			switch (hrana->position.x > vol->position.x)
			{
			case 1:
				vol->volocity.x = 1;
				break;
			case 0:
				vol->volocity.x = -1;
				break;

			default:
				break;
			}
			switch (hrana->position.y > vol->position.y)
			{
			case 1:
				vol->volocity.y = 1;
				break;
			case 0:
				vol->volocity.y = -1;
				break;
			default:
				break;
			}
		}*/
		}
	}

	void update2(){
		//std::cout << "to se izvaja\n";
			switch (hrana->position.x > vol->position.x )
			{
			case 1:
				vol->volocity.x = 1;

				break;
			case 0:
				vol->volocity.x = -1;

				break;

			default:
				break;
			}
			switch (hrana->position.y > vol->position.y )
			{
			case 1:
				vol->volocity.y = 1;
				break;
			case 0:
				vol->volocity.y = -1;
				break;
			default:
				break;
			}
	}
};