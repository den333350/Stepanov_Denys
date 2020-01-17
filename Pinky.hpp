#pragma once
#include "Ghost.hpp"


class ClassPinky :public Ghost {
public:
	ClassPinky() {
		Spawn();
	}
	void Spawn();
	void Movement(int x, int y, int dots, bool energy);
};