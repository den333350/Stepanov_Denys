#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>

#include "Render.hpp"
#include "Player.hpp"
#include "Blinky.hpp"
#include "Pinky.hpp"

namespace Pacman {
    bool inGame = false;
    bool exitConsole = false;
    int Tick = 250;
}


GameMap CreateMap;
Render DrawMap;
Player Pac;
ClassBlinky Blinky;
ClassPinky Pinky;


void StartGame() {
    Pac.score = 0;
    Pac.level = 1;
    Pac.dots = 0;
    Pac.lives = 3;
    
}

void Live() {
    if (Pac.x==Blinky.x && Pac.y == Blinky.y) {
        if (Pac.energy == true) {
            Blinky.Spawn();
            Pac.Score(200);
        }
        else {
            Pac.lives--;
            Pac.Spawn();
            Blinky.Spawn();
            Pinky.Spawn();
            _getch();
        }
    }
    if (Pac.lives == 0) {
        DrawMap.inGame = false;
        system("cls");
        DrawMap.gotoxy(10, 15);
        SetConsoleTextAttribute(DrawMap.Handle, 4);
        std::cout << "you lose";
        Sleep(3000);
    }
    SetConsoleTextAttribute(DrawMap.Handle, 6);
    DrawMap.gotoxy(1, 31);
    std::cout << "    ";
    for (int i = 0; Pac.lives > i; i++) {
        DrawMap.gotoxy(1+i,31);
        
        std::cout << '0';
    }
}



int main()
{ 
    while (DrawMap.exitConsole == false) {
        DrawMap.Menu();
        StartGame();
        while (DrawMap.inGame == true) {
            Live();
            DrawMap.drawLevel(Pac.x,Pac.y);
           
            Pac.newLevel();
            
            Pac.Movement();
            Blinky.Movement(Pac.x,Pac.y,Pac.energy);
            Pinky.Movement(Pac.PinkyX, Pac.PinkyY, Pac.dots, Pac.energy);
            Pac.energyOff();
            
            Pac.Score(0);
            
            Sleep(Pacman::Tick);

        }
    }
    return 0;
}
