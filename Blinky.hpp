#ifndef BLINKY_HPP
#define BLINKY_HPP
#include "Ghost.hpp"

class ClassBlinky:public Ghost {
public:
	ClassBlinky(Render r) {
		Spawn(r);
	}
	void Spawn(Render r);
	void Movement(int x, int y, GameMap m, Render r, bool energy);
};
#endif