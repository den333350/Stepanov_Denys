#include <iostream>
#include <windows.h>
#include "Render.hpp"

#ifndef PLAYER_HPP
#define PLAYER_HPP



class Player {
private:
    int _x;
    int _y;
    char _movingDirection;

public:
    
    int PinkyX;
    int PinkyY;

    

    Player(Render r) {
        Spawn(r);
    }

    void Movement(GameMap m, Render r);

    void Spawn(Render r);
    int ReturnPositionX();
    int ReturnPositionY();
};
#endif 