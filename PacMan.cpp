#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>

#include "Player.hpp"
#include "Render.hpp"
#include "GameMap.hpp"
#include "Ghost.hpp"

namespace Pacman {
    bool inGame = false;
    bool exitConsole = false;
    int Tick = 250;
}



Ghost Blinky;

Player Pac;

void PlayerMovement() {
    SetConsoleTextAttribute(Handle, 6);
    char c = Pac.movingDirection;
    while (_kbhit()) {
        Pac.movingDirection = _getch();
    }
    gotoxy(Pac.x, Pac.y);
    std::cout << ' ';

    if (Pac.movingDirection == 'w' || Pac.movingDirection == 'W' || Pac.movingDirection == 'ц' || Pac.movingDirection == 'Ц' || Pac.movingDirection == (72)) {
        if (NewMap[Pac.y -1][Pac.x] != GameConst::WALL)
            Pac.y--;
        else Pac.movingDirection = c;
    }

    if (Pac.movingDirection == 's' || Pac.movingDirection == 'S' || Pac.movingDirection == 'ы' || Pac.movingDirection == 'Ы' || Pac.movingDirection == (80)) {
        if (NewMap[Pac.y+1][Pac.x] != GameConst::WALL)
            Pac.y++;
        else Pac.movingDirection = c;
    }

    if (Pac.movingDirection == 'a' || Pac.movingDirection == 'A' || Pac.movingDirection == 'ф' || Pac.movingDirection == 'Ф' || Pac.movingDirection == (75)) {
        if (NewMap[Pac.y][Pac.x-1] != GameConst::WALL) {
            
            Pac.x--;
            if (Pac.x == 0 && Pac.y == 14) {
                Pac.x = 27;
            }
        }
        else Pac.movingDirection = c;
    }

    if (Pac.movingDirection == 'd' || Pac.movingDirection == 'D' || Pac.movingDirection == 'в' || Pac.movingDirection == 'В' || Pac.movingDirection == (77)) {
        if (NewMap[Pac.y][Pac.x+1] != GameConst::WALL) {
            Pac.x++;
            if (Pac.x == 27 && Pac.y == 14) {
                Pac.x = 0;
            }
        }
        else Pac.movingDirection = c;

    }
    gotoxy(2, 32);
    std::cout << "     ";
    gotoxy(2, 32);
    std::cout << Pac.x << ' ' << Pac.y;
    gotoxy(Pac.x, Pac.y);
    std::cout << '0';
}

void Menu() {
    char c = '0';
    int chosen = 0;
    system("cls");

    while ((Pacman::inGame == false))
    {
        SetConsoleTextAttribute(Handle, 11);
        gotoxy(13, 9);
        std::cout << char(24);
        gotoxy(13, 10);
        std::cout << "W";

        gotoxy(13, 22);
        std::cout << char(25);
        gotoxy(13, 21);
        std::cout << "S";

        SetConsoleTextAttribute(Handle, 15);
        gotoxy(10, 14);
        std::cout << "NEW GAME";
        gotoxy(12, 17);
        std::cout << "EXIT";

        while (c != char(13))
        {
            SetConsoleTextAttribute(Handle, 10);
            gotoxy(7, 14 + chosen);
            std::cout << "->";
            gotoxy(19, 14 + chosen);
            std::cout << "<-";
            gotoxy(0, 0);
            c = _getch();
            gotoxy(7, 14 + chosen);
            std::cout << "  ";
            gotoxy(19, 14 + chosen);
            std::cout << "  ";
            if (c == 's'||c=='S' ||c=='ы' ||c=='Ы')
            {
                if (chosen < 3)
                {
                    chosen += 3;
                }
            }
            if (c == 'w'||c=='W' ||c=='ц' ||c=='Ц')
            {
                if (chosen > 0)
                {
                    chosen -= 3;
                }
            }
        }
        if (chosen == 0)
        {
            Pacman::inGame = true;

        }
        if (chosen == 3)
        {
            Pacman::exitConsole = true;
            exit(0);
        }
        c = ' ';
        
        system("cls");
    }

}
void StartGame() {
    NewMap = gameMap;
    Pac.score = 0;
    Pac.level = 1;
    Pac.dots = 0;
    Pac.lives = 3;
    Pac.Spawn();
    Blinky.Spawn();
}

void Live() {
    if (Pac.x==Blinky.GhostX && Pac.y == Blinky.GhostY) {
        if (Pac.energy == true) {
            Blinky.Spawn();
            Pac.Score(200);
        }
        else {
            Pac.lives--;
            Pac.Spawn();
            Blinky.Spawn();
            _getch();
        }
    }
    if (Pac.lives == 0) {
        Pacman::inGame = false;
        system("cls");
        gotoxy(10, 15);
        SetConsoleTextAttribute(Handle, 4);
        std::cout << "YOU LOSE";
        Sleep(3000);
    }
    SetConsoleTextAttribute(Handle, 6);
    for (int i = 0; Pac.lives > i; i++) {
        gotoxy(1+i,31);
        std::cout << '0';
    }
}



int main()
{ 
    InitializeRender();
    while (Pacman::exitConsole == false) {
        Menu();
        StartGame();
        while (Pacman::inGame == true) {
            drawLevel();
            Live();
            Pac.newLevel();
            
            PlayerMovement();
            Blinky.Move(Pac);
            Pac.energyOff();
            
            Pac.Score(0);
            
            Sleep(Pacman::Tick);

        }
    }
    return 0;
}
