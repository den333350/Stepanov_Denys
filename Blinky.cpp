#include "Blinky.hpp"

namespace BLINKY {
	const int SPAWN_X = 13;
	const int SPAWN_Y = 12;
}
void ClassBlinky::Spawn() {
	x = BLINKY::SPAWN_X;
	y = BLINKY::SPAWN_Y;

}

void ClassBlinky::Movement(int x, int y, bool energy) {
	directionX = x;
	directionY = y;
	/*Move(energy, 4);*/
}