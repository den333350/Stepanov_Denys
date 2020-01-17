#pragma once
#include <iostream>
#include <windows.h>
#include "Render.hpp"


class Player {
public:
    int x;
    int y;
    int lifes;
    char movingDirection;

    bool energy = false;
    int energyScore = 0;
    int lives;
    int score;
    int dots;
    int level;

    void energyOff() {
        if (energy == true) {
            energyScore++;
            if (energyScore == 36) {
                energy = false;
                energyScore = 0;
            }
        }
    }

    void Spawn() {
        gotoxy(x, y);
        std::cout << ' ';
        x = 13;
        y = 23;
    }

    void Score(int i) {
        SetConsoleTextAttribute(Handle, 5);
        gotoxy(10, -3);
        std::cout << "YOUR SCORE";
        if (NewMap[y][x] == '.' || NewMap[y][x] == '+') {

            if (NewMap[y][x] == '+') {
                score += 50;
                energy = true;
            }
            else {
                score += 10;
                dots++;
            }
            NewMap[y][x] = ' ';
        }
        score += i;
        gotoxy(3, -2);
        std::cout << score;
    }

    void newLevel() {

        SetConsoleTextAttribute(Handle, 2);
        gotoxy(20, -2);
        std::cout << 'L' << ' ' << level;
        if (dots == 240) {
            dots = 0;
            level++;
            system("cls");
            gotoxy(10, 15);
            std::cout << "LEVEL" << ' ' << level;
            NewMap= gameMap;
            Sleep(3000);

            system("cls");
            drawLevel();
            Spawn();
            _getch();
        }
    }
};