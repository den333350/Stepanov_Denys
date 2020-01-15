#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <string>

#include "GameMechanics.hpp"
#include "Render.hpp"
#include "GameMap.hpp"
#include "Ghost.hpp"
#include "Player.hpp"



const int WaitToTick = 250;
const int Lifes = 3;




Render Zaebalo;
GameMechanics Game;
Player Pac;
Ghost Blinky;

bool inGame = false;
bool exitConsole = false;


void Score(int y, int x) {
    SetConsoleTextAttribute(Handle, 5);
    gotoxy(10, 1);
    std::cout << "YOUR SCORE";
    if (Newmap[y - 4][x - 1] == 0 || Newmap[y - 4][x - 1] == 3) {

        if (Newmap[y - 4][x - 1] == 3) {
            Game.score += 50;
            Game.energy = true;
        }
        else {
            Game.score += 10;
            Game.dots++;
        }
        Newmap[y - 4][x - 1] = 2;
    }

    gotoxy(3, 2);
    std::cout << Game.score;
}
void newLevel() {

    SetConsoleTextAttribute(Handle, 2);
    gotoxy(20, 2);
    std::cout << 'L' << ' ' << Game.level;
    if (Game.dots == 240) {
        Game.dots = 0;
        Game.level++;
        system("cls");
        gotoxy(10, 18);
        std::cout << "LEVEL" << ' ' << Game.level;
        memcpy(Newmap, gameMap, 3584);
        Sleep(3000);

        system("cls");
        Zaebalo.drawLevel();
        _getch();
    }
}


void Menu() {
    char c = '0';
    int chosen = 0;
    system("cls");

    while ((inGame == false))
    {
        SetConsoleTextAttribute(Handle, 11);
        gotoxy(13, 12);
        std::cout << char(24);
        gotoxy(13, 13);
        std::cout << "W";

        gotoxy(13, 25);
        std::cout << char(25);
        Zaebalo.gotoxy(13, 24);
        std::cout << "S";

        SetConsoleTextAttribute(Handle, 15);
        Zaebalo.gotoxy(10, 17);
        std::cout << "NEW GAME";
        Zaebalo.gotoxy(12, 20);
        std::cout << "EXIT";

        while (c != char(13))
        {
            SetConsoleTextAttribute(Handle, 10);
            Zaebalo.gotoxy(7, 17 + chosen);
            std::cout << "->";
            Zaebalo.gotoxy(19, 17 + chosen);
            std::cout << "<-";
            Zaebalo.gotoxy(0, 0);
            c = _getch();
            Zaebalo.gotoxy(7, 17 + chosen);
            std::cout << "  ";
            Zaebalo.gotoxy(19, 17 + chosen);
            std::cout << "  ";
            if (c == 's'||c=='S' ||c=='ы' ||c=='Ы' || c==(80))
            {
                if (chosen < 3)
                {
                    chosen += 3;
                }
            }
            if (c == 'w'||c=='W' ||c=='ц' ||c=='Ц'|| c==(72))
            {
                if (chosen > 0)
                {
                    chosen -= 3;
                }
            }
        }
        if (chosen == 0)
        {
            inGame = true;

        }
        if (chosen == 3)
        {
            exitConsole = true;
            exit(0);
        }
        c = ' ';
        
        system("cls");
    }

}
void StartGame() {
    memcpy(Newmap,gameMap, 3584);
    Game.energy = false;
    Game.score = 0;
    Game.level = 1;
    Game.dots = 0;
    Pac.lives = Lifes;
    Pac.Spawn();
    Blinky.Spawn();
}

void Live() {
    if (Pac.x==Blinky.x && Pac.y == Blinky.y) {
        if (Game.energy == true) {
            Blinky.Spawn();
            Game.Score(200);
        }
        else {
            Pac.lives--;
            Pac.Spawn();
            Blinky.Spawn();
        }
    }
    if (Pac.lives == 0) {
        inGame = false;
        system("cls");
        gotoxy(11, 18);
        SetConsoleTextAttribute(Handle, 4);
        std::cout << "YOU LOSE";
        Sleep(3000);
    }
    SetConsoleTextAttribute(Handle, 6);
    gotoxy(2, 35);
    for (int i = Pac.lives; i >=0 ; i--) {
        gotoxy(i,35);
        std::cout << ' ';
    }
}



int main()
{ 
    Zaebalo.InitializeRender();
    while (exitConsole == false) {
        Menu();
        StartGame();
        while (inGame == true) {
            Zaebalo.drawLevel();
            Live();
            newLevel();
            Pac.Movement(gameMap[gameRow][gameCol]);
            Game.energyOff();
            Score(Pac.x, Pac.y);
            /*Blinky.Move(Pac.x,Pac.y,Game.energy);*/
            Sleep(WaitToTick);
        }
    }
    return 0;
}
