#include "Pinky.hpp"

namespace PINKY {
	const int SPAWN_X = 14;
	const int SPAWN_Y = 14;
	const int DOTS_LIM = 15;
}

void ClassPinky::Spawn() {
	x = PINKY::SPAWN_X;
	y = PINKY::SPAWN_Y;

}

void ClassPinky::Movement(int x, int y, int dots, bool energy) {
	if (dots > PINKY::DOTS_LIM) {

		directionX = x;
		directionY = y;
		Move(energy, 13);
	}
}
