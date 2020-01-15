#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <string>


#include "Render.h"
#include "GameMap.h"

using namespace std;

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
        x = 14;
        y = 27;
    }

    void Score(int i) {
        SetConsoleTextAttribute(Handle, 5);
        gotoxy(10, 1);
        cout << "YOUR SCORE";
        if (Newmap[y - 4][x - 1] == 0 || Newmap[y - 4][x - 1] == 3) {

            if (Newmap[y - 4][x - 1] == 3) {
                score += 50;
                energy = true;
            }
            else {
                score += 10;
                dots++;
            }
            Newmap[y - 4][x - 1] = 2;
        }
        score += i;
        gotoxy(3, 2);
        cout << score;
    }

    void newLevel() {

        SetConsoleTextAttribute(Handle, 2);
        gotoxy(20, 2);
        cout << 'L' << ' ' << level;
        if (dots == 240) {
            dots = 0;
            level++;
            system("cls");
            gotoxy(10, 18);
            cout << "LEVEL" << ' ' << level;
            memcpy(Newmap, gameMap, 3584);
            Sleep(3000);

            system("cls");
            drawLevel();
            _getch();
            Spawn();
        }
    }
};

class Ghost {
public:
    int x;
    int y;
    int directionX;
    int directionY;
    int spawnX;
    int spawnY;

    void Spawn() {
        x = 14;
        y = 16;
    }

    string SelectDirection(int x, int y, int dx, int dy) {
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

    void Move(Player Pac) {
        directionX = x;
        directionY = x;
        gotoxy(x, y);
        cout << ' ';
        if (Pac.energy == true) {
            SetConsoleTextAttribute(Handle, 11);
        }
        else {
            string MoveB;
            SetConsoleTextAttribute(Handle, 4);
            MoveB = SelectDirection(x, y, Pac.x, Pac.y);
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
        cout << 'M';
        gotoxy(10, 35);
        cout << "        ";
        cout << x << ' ' << y;
    }
};

Ghost Blinky;

Player Pac;

bool inGame = false;
bool exitConsole = false;

void PlayerMovement() {
    SetConsoleTextAttribute(Handle, 6);
    char c = Pac.movingDirection;
    while (_kbhit()) {
        Pac.movingDirection = _getch();
    }
    gotoxy(Pac.x, Pac.y);
    cout << ' ';

    if (Pac.movingDirection == 'w' || Pac.movingDirection == 'W') {
        if (Newmap[Pac.y - 5][Pac.x - 1] != 1)
            Pac.y--;
        else Pac.movingDirection = c;
    }

    if (Pac.movingDirection == 's' || Pac.movingDirection == 'S') {
        if (Newmap[Pac.y - 3][Pac.x - 1] != 1)
            Pac.y++;
        else Pac.movingDirection = c;
    }

    if (Pac.movingDirection == 'a' || Pac.movingDirection == 'A') {
        if (Newmap[Pac.y - 4][Pac.x - 2] != 1) {
            Pac.x--;
            if (Pac.x == 1 && Pac.y == 18) {
                Pac.x = 28;
            }
        }
        else Pac.movingDirection = c;
    }

    if (Pac.movingDirection == 'd' || Pac.movingDirection == 'D') {
        if (Newmap[Pac.y - 4][Pac.x] != 1) {
            Pac.x++;
            if (Pac.x == 28 && Pac.y == 18) {
                Pac.x = 1;
            }
        }
        else Pac.movingDirection = c;

    }

    gotoxy(Pac.x, Pac.y);
    cout << '0';
}

void Menu() {
    char c = '0';
    int chosen = 0;
    system("cls");

    while ((inGame == false))
    {
        SetConsoleTextAttribute(Handle, 11);
        gotoxy(13, 12);
        cout << char(24);
        gotoxy(13, 13);
        cout << "W";

        gotoxy(13, 25);
        cout << char(25);
        gotoxy(13, 24);
        cout << "S";

        SetConsoleTextAttribute(Handle, 15);
        gotoxy(10, 17);
        cout << "NEW GAME";
        gotoxy(12, 20);
        cout << "EXIT";

        while (c != char(13))
        {
            SetConsoleTextAttribute(Handle, 10);
            gotoxy(7, 17 + chosen);
            cout << "->";
            gotoxy(19, 17 + chosen);
            cout << "<-";
            gotoxy(0, 0);
            c = _getch();
            gotoxy(7, 17 + chosen);
            cout << "  ";
            gotoxy(19, 17 + chosen);
            cout << "  ";
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
    Pac.score = 0;
    Pac.level = 1;
    Pac.dots = 0;
    Pac.lives = 3;
    Pac.Spawn();
    Blinky.Spawn();
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
        }
    }
    if (Pac.lives == 0) {
        inGame = false;
        system("cls");
        gotoxy(11, 18);
        SetConsoleTextAttribute(Handle, 4);
        cout << "YOU LOSE";
        Sleep(3000);
    }
    SetConsoleTextAttribute(Handle, 6);
    gotoxy(2, 35);
    cout << "000";
    for (int i = 5; Pac.lives + 1 < i; i--) {
        gotoxy(i,35);
        cout << ' ';
    }
}



int main()
{ 
    InitializeRender();
    while (exitConsole == false) {
        Menu();
        StartGame();
        while (inGame == true) {
            drawLevel();
            Pac.newLevel();
            Live();
            PlayerMovement();
            Pac.energyOff();
            
            Pac.Score(0);
            Blinky.Move(Pac);
            Sleep(250);

        }
    }
    return 0;
}
