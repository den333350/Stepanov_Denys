#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Render.hpp"

class Player:public Render {
public:
    int x;
    int y;
    int lifes;
    char movingDirection;
    int lives;

    void Spawn();

    void Movement(int map[gameRow][gameCol]);
};