#pragma once
#include "Ghost.hpp"

class ClassBlinky:public Ghost {
public:
	ClassBlinky() {
		Spawn();
	}
	void Spawn();
	void Movement(int x, int y, bool energy);
};