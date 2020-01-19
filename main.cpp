#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>

#include "GameMechanics.hpp"


int main()
{ 
    GameMap CreateMap;
    Render DrawMap;
    Render& DM = DrawMap;
    GameMechanics Game;
    Player Pac(DM);
    ClassBlinky Blinky(DM);
    ClassPinky Pinky(DM);
    Game.GameLoop(CreateMap,DrawMap,Pac,Blinky,Pinky);
    
    return 0;
}
