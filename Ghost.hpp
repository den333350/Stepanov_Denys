#pragma once

#include <vector>
#include <cstring>
#include "Render.hpp"

const int& Row = GameConst::gameRow;
const int& Col = GameConst::gameCol;

class Ghost {
public:
    int GhostX;
    int GhostY;
    int directionX;
    int directionY;
    int spawnX;
    int spawnY;

    int GhostMap[Row][Col];
   
    int px[Row*Col], py[Row*Col];
    int lenght;

    void Spawn() {
        GhostX = 13;
        GhostY = 12;
    }


   void FillGhostMap() {
       for (int x = 0; x < GameConst::gameCol; x++) {
            for (int y = 0; y < GameConst::gameRow; y++) {
               if (gameMap[y][x] == GameConst::WALL) {
                   GhostMap[y][x] = -1;
               }
               else GhostMap[y][x] = -5;
           }
        }
    }

    void CreatePath() {
        
        int CheckX[4] = { 1, 0, -1, 0 };
        int CheckY[4] = { 0, 1, 0, -1 };
        int d, k;
        int x, y;
        bool stop;
        d = 0;
        GhostMap[GhostX][GhostY] = 0;
        do {
            stop = true;
            for(y = 0; y < Row; ++y){
                for (x = 0; x < Col; x++) {
                    if (GhostMap[y][x] == d) {
                        for (k = 0; k < 4; ++k) {
                            int iy = y + CheckY[k], ix = x + CheckX[k];
                            if (iy >= 0 && iy < Row && ix >= 0 && ix < Col && GhostMap[iy][ix] == -5) {
                                stop = false;


                                GhostMap[iy][ix] = d + 1;
                            }
                        }
                    }
                }
            }
            d++;
        } while (!stop && GhostMap[directionY][directionX] == -5);
        lenght = GhostMap[directionY][directionX];
        y = directionY;
        x = directionX;
        d = lenght;

        while (d > 0) {
            px[d] = x;
            py[d] = y;
            d--;
            for (k = 0; k < 4; ++k) {
                int iy = y + CheckY[k], ix = x + CheckX[k];
                if (iy >= 0 && iy < Row && ix >= 0 && ix < Col && GhostMap[iy][ix] == d)
                {
                    x = x + CheckX[k];
                    y = y + CheckY[k];
                    break;
                }
            }
        }
        px[0] = GhostX;
        py[0] = GhostY;
        
    }

    void Move(Player Pac) {
        directionX = Pac.x;
        directionY = Pac.y;
        gotoxy(GhostX, GhostY);
        std::cout << ' ';
        if (Pac.energy == true) {
            SetConsoleTextAttribute(Handle, 11);
        }
        else {
            FillGhostMap();
            CreatePath();
                GhostX = px[1];
                GhostY = py[1];
           
        }
        gotoxy(GhostX, GhostY);
        std::cout << 'M';
    }
};