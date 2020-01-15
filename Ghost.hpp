#pragma once
#include <iostream>
#include <cstring>
#include "GameMap.hpp"

class Ghost:public Render {
public:
    int x;
    int y;
    int directionX;
    int directionY;

    /*std::string SelectDirection(int x, int y, int dx, int dy,) {
        if (dy < y) {
            if (Newmap[y - 5][x - 1] != 1)
                return "UP";
        }
        if (dy > y) {
            if (Newmap[y - 3][x - 1] != 1)
                return "DOWN";
        }
        if (dx < x) {
            if (Newmap[y - 4][x - 2] != 1) {
                return "LEFT";
            }
        }
        if (dx > x) {
            if (Newmap[y - 4][x] != 1)
                return "RIGHT";
        }

        return "0";
    }

    void Move(int Px, int Py, bool energy) {
        directionX = x;
        directionY = x;
        gotoxy(x, y);
        std::cout << ' ';
        if (energy == true) {
            SetConsoleTextAttribute(Handle, 11);
        }
        else {
            std::string MoveB;
            SetConsoleTextAttribute(Handle, 4);
            MoveB = SelectDirection(x, y, Px, Py);
            if (MoveB == "UP") {
                y--;
            }
            if (MoveB == "DOWN") {
                y++;
            }
            if (MoveB == "LEFT") {
                x--;
            }
            if (MoveB == "RIGHT") {
                x++;
            }
        }
        gotoxy(x, y);
        std::cout << 'M';
        gotoxy(10, 35);
        std::cout << "        ";
        std::cout << x << ' ' << y;
    }
    void Spawn() {
        x = 14;
        y = 17;
    }*/
};
