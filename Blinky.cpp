#include "Blinky.hpp"


void ClassBlinky::Spawn(Render r) {
	r.gotoxy(x, y);
	std::cout << ' ';
	x = BLINKY::SPAWN_X;
	y = BLINKY::SPAWN_Y;

}

void ClassBlinky::Movement(int x,int y, GameMap m, Render r, bool energy) {
	directionX = x;
	directionY = y;
	Move(m,r,energy, 4);
}