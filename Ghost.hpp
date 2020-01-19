#include <vector>
#include <cstring>

#include "Player.hpp"
#include "Render.hpp"
#ifndef GHOST_HPP
#define GHOST_HPP


class Ghost {
public:
    int x;
    int y;
    int directionX;
    int directionY;
    int ReturnPositionX();
    int ReturnPositionY();
    void Move(GameMap m, Render r, bool energy, int color);
    
private:
    
    const int& Col = GAME_CONSTANTS::GAME_COL;
    const int& Row = GAME_CONSTANTS::GAME_ROW;

    int GhostMap[GAME_CONSTANTS::GAME_ROW][GAME_CONSTANTS::GAME_COL];

    int px[GAME_CONSTANTS::TOTAL], py[GAME_CONSTANTS::TOTAL];
    int lenght;

    void FillGhostMap(GameMap m);

    void CreatePath();

    void SelectRandDirection(GameMap m);
    
};
#endif