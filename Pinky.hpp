#include "Ghost.hpp"
#ifndef PINKY_HPP
#define PINKY_HPP


class ClassPinky :public Ghost {
public:
	ClassPinky(Render r) {
		Spawn(r);
	}
	void Spawn(Render r);
	void Movement(int dots, bool energy, GameMap m, Render r, Player pl);
};

#endif 