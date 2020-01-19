#include "Player.hpp"

void Player::Movement(GameMap m, Render r) {
    SetConsoleTextAttribute(r.Handle, 6);
    char c = _movingDirection;
    while (_kbhit()) {
        _movingDirection = _getch();
    }
    r.gotoxy(_x, _y);
    std::cout << ' ';

    if (_movingDirection == 'w' || _movingDirection == 'W' || _movingDirection == 'ö' || _movingDirection == 'Ö' || _movingDirection == (72)) {
        if (m.ReturnMapSymbol(_x, _y - 1) != m.Wall) {
            _y--;
            PinkyX = _x;
            PinkyY = _y - 4;
        }
        else _movingDirection = c;
    }

    if (_movingDirection == 's' || _movingDirection == 'S' || _movingDirection == 'û' || _movingDirection == 'Û' || _movingDirection == (80)) {
        if (m.ReturnMapSymbol(_x, _y + 1) != m.Wall) {
            _y++;
            PinkyX = _x;
            PinkyY = _y + 4;
        }

        else _movingDirection = c;
    }

    if (_movingDirection == 'a' || _movingDirection == 'A' || _movingDirection == 'ô' || _movingDirection == 'Ô' || _movingDirection == (75)) {
        if (m.ReturnMapSymbol(_x - 1, _y) != m.Wall) {

            _x--;
            if (_x == 0 && _y == 14) {
                _x = 27;
                PinkyX = _x - 4;
                PinkyY = _y;
            }
        }
        else _movingDirection = c;
    }

    if (_movingDirection == 'd' || _movingDirection == 'D' || _movingDirection == 'â' || _movingDirection == 'Â' || _movingDirection == (77)) {
        if (m.ReturnMapSymbol(_x + 1, _y) != m.Wall) {
            _x++;
            if (_x == 27 && _y == 14) {
                _x = 0;
                PinkyX = _x + 4;
                PinkyY = _y;
            }
        }
        else _movingDirection = c;

    }
    r.gotoxy(_x, _y);
    std::cout << '0';
}

void Player::Spawn(Render r) {
    r.gotoxy(_x, _y);
    std::cout << ' ';
    _x = 13;
    _y = 23;
}

int Player::ReturnPositionX()
 {
    return _x;
}
int Player::ReturnPositionY() {
    return _y;
 }