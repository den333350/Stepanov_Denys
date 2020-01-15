#pragma once

#include <iostream>
#include <windows.h>
#include <conio.h>


class GameMechanics {
public:
	bool energy;
	int energyScore;
	int score;
	int dots;
	int level;

    
	void energyOff();
	void Score(int i);
    /*void Score(int y, int x);
    void newLevel();*/
};