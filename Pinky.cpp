#include "Pinky.hpp"



void ClassPinky::Spawn(Render r) {
	r.gotoxy(x, y);
	std::cout << ' ';
	x = PINKY::SPAWN_X;
	y = PINKY::SPAWN_Y;

}

void ClassPinky::Movement(int dots, bool energy, GameMap m, Render r, Player pl) {
	if (dots > PINKY::DOTS_LIM) {

		directionX = pl.PinkyX;
		directionY = pl.PinkyY;
		Move(m, r, energy, 13);
	}
}
