
#include "Player.hpp"



    const int SpawnY = 27;
    const int SpawnX = 14;


void Player::Movement(int map[gameRow][gameCol]) {
    SetConsoleTextAttribute(Handle, 6);
    char c = movingDirection;
    while (_kbhit()) {
        movingDirection = _getch();
    }
    gotoxy(x, y);
    std::cout << ' ';

    if (movingDirection == 'w' || movingDirection == 'W' || movingDirection == (72) || movingDirection == 'ö' || movingDirection == 'Ö') {
        if (map[y - 5][x - 1] != 1)
            y--;
        else movingDirection = c;
    }

    if (movingDirection == 's' || movingDirection == 'S' || movingDirection == (80) || movingDirection == 'û' || movingDirection == 'Û') {
        if (map[y - 3][x - 1] != 1)
            y++;
        else movingDirection = c;
    }

    if (movingDirection == 'a' || movingDirection == 'A' || movingDirection == (75) || movingDirection == 'ô' || movingDirection == 'Ô') {
        if (map[y - 4][x - 2] != 1) {
            x--;
            if (x == 1 && y == 18) {
                x = 28;
            }
        }
        else movingDirection = c;
    }

    if (movingDirection == 'd' || movingDirection == 'D' || movingDirection == (77) || movingDirection == 'â' || movingDirection == 'Â') {
        if (map[y - 4][x] != 1) {
            x++;
            if (x == 28 && y == 18) {
                x = 1;
            }
        }
        else movingDirection = c;

    }

    gotoxy(x, y);
    std::cout << '0';
}

void Player::Spawn() {
    y = SpawnY;
    x = SpawnX;
}