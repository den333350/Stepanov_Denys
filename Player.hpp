#pragma once
#include <iostream>
#include <windows.h>
#include "Render.hpp"


class Player:public Render {
public:
    int x;
    int y;
    int lifes;
    char movingDirection;
    int PinkyX;
    int PinkyY;

    bool energy = false;
    int energyScore = 0;
    int lives;
    int score;
    int dots;
    int level;

    Player() {
        Spawn();
    }

    void Movement() {
        SetConsoleTextAttribute(Handle, 6);
        char c = movingDirection;
        while (_kbhit()) {
            movingDirection = _getch();
        }
        gotoxy(x, y);
        std::cout << ' ';

        if (movingDirection == 'w' || movingDirection == 'W' || movingDirection == 'ö' || movingDirection == 'Ö' || movingDirection == (72)) {
            if (ReturnMapSymbol(x,y-1)!=Wall) {
                y--;
                PinkyX = x;
                PinkyY = y - 4;
            }
            else movingDirection = c;
        }

        if (movingDirection == 's' || movingDirection == 'S' || movingDirection == 'û' || movingDirection == 'Û' || movingDirection == (80)) {
            if (ReturnMapSymbol(x, y + 1) != Wall) {
                y++;
                PinkyX = x;
                PinkyY = y + 4;
            }

            else movingDirection = c;
        }

        if (movingDirection == 'a' || movingDirection == 'A' || movingDirection == 'ô' || movingDirection == 'Ô' || movingDirection == (75)) {
            if (ReturnMapSymbol(x - 1, y ) != Wall) {

                x--;
                if (x == 0 && y == 14) {
                    x = 27;
                    PinkyX = x - 4;
                    PinkyY = y;
                }
            }
            else movingDirection = c;
        }

        if (movingDirection == 'd' || movingDirection == 'D' || movingDirection == 'â' || movingDirection == 'Â' || movingDirection == (77)) {
            if (ReturnMapSymbol(x + 1, y) != Wall) {
                x++;
                if (x == 27 && y == 14) {
                    x = 0;
                    PinkyX = x + 4;
                    PinkyY = y;
                }
            }
            else movingDirection = c;

        }
        gotoxy(x, y);
        std::cout << '0';
    }

    void energyOff() {
        if (energy == true) {
            energyScore++;
            if (energyScore > 36 - level*3) {
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
        if (ReturnMapSymbol(x,y) == '.' || ReturnMapSymbol(x, y) == '+') {

            if (ReturnMapSymbol(x, y) == '+') {
                score += 50;
                energy = true;
            }
            else {
                score += 10;
                dots++;
            }
            EditMapSymbol(x,y,' ');
        }
        score += i;
        gotoxy(3, -2);
        std::cout << score;
    }

    void newLevel() {

        SetConsoleTextAttribute(Handle, 2);
        gotoxy(20, -2);
        std::cout << 'L' << ' ' << level;
        if (dots == 10) {
            dots = 0;
            level++;
            system("cls");
            gotoxy(10, 15);
            std::cout << "LEVEL" << ' ' << level;
            CopyMap();
            Sleep(3000);
            Spawn();
            system("cls");
            drawLevel(x,y);
            
            _getch();
        }
    }
};