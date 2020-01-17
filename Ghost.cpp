#include "Ghost.hpp"

void Ghost::FillGhostMap() {
    for (int x = 0; x < Col; x++) {
        for (int y = 0; y < Row; y++) {
            if (ReturnMapSymbol(x,y) == Wall) {
                GhostMap[y][x] = -1;
            }
            else GhostMap[y][x] = -5;
        }
    }
}

void Ghost::CreatePath() {

    int CheckX[4] = { 1, 0, -1, 0 };
    int CheckY[4] = { 0, 1, 0, -1 };
    int d, k;
    int cx, cy;
    bool stop;
    d = 0;
    GhostMap[y][x] = 0;
    GhostMap[directionY][directionY] = -5;
    do {
        stop = true;
        for (cy = 0; cy < Row; ++cy) {
            for (cx = 0; cx < Col; ++cx) {
                if (GhostMap[cy][cx] == d) {
                    for (k = 0; k < 4; ++k) {
                        int iy = cy + CheckY[k], ix = cx + CheckX[k];
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
    cy = directionY;
    cx = directionX;
    d = lenght;

    while (d > 0) {
        px[d] = cx;
        py[d] = cy;
        d--;
        for (k = 0; k < 4; ++k) {
            int iy = cy + CheckY[k], ix = cx + CheckX[k];
            if (iy >= 0 && iy < Row && ix >= 0 && ix < Col && GhostMap[iy][ix] == d)
            {
                cx = cx + CheckX[k];
                cy = cy + CheckY[k];
                break;
            }
        }
    }
    px[0] = x;
    py[0] = y;

}

void Ghost::SelectRandDirection() {
    switch (rand() % 4) {
    case 1:
        if (ReturnMapSymbol(x-1,y) != Wall) {
            x--;
        }
        break;
    case 2:
        if (ReturnMapSymbol(x + 1, y) != Wall) {
            x++;
        }
        break;
    case 3:
        if (ReturnMapSymbol(x , y - 1)!= Wall) {
            y--;
        }
        break;
    case 4:
        if (ReturnMapSymbol(x , y+1) != Wall) {
            y++;
        }
        break;
    }


}

void Ghost::Move(bool energy, int color) {
    gotoxy(x, y);
    std::cout << ' ';
    if (energy == true) {
        SetConsoleTextAttribute(Handle, 11);
        SelectRandDirection();
    }
    else {
        SetConsoleTextAttribute(Handle, color);
        FillGhostMap();
        CreatePath();
        if (px[1] > 0 && px[1] < 27 && py[1] > 0 && py[1] < 31) {

            x = px[1];
            y = py[1];
        }
    }
    gotoxy(x, y);
    std::cout << 'M';
}