#include "Ghost.hpp"

void Ghost::FillGhostMap(GameMap m) {
    
    for (int x = 0; x < Col; x++) {
        for (int y = 0; y < Row; y++) {
            if (m.ReturnMapSymbol(x,y) == m.Wall) {
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

void Ghost::SelectRandDirection(GameMap m) {
    switch (rand() % 4) {
    case 1:
        if (m.ReturnMapSymbol(x-1,y) != m.Wall) {
            x--;
        }
        break;
    case 2:
        if (m.ReturnMapSymbol(x + 1, y) != m.Wall) {
            x++;
        }
        break;
    case 3:
        if (m.ReturnMapSymbol(x , y - 1)!= m.Wall) {
            y--;
        }
        break;
    case 4:
        if (m.ReturnMapSymbol(x , y+1) != m.Wall) {
            y++;
        }
        break;
    }


}

void Ghost::Move(GameMap m,Render r,bool energy, int color) {
    r.gotoxy(x, y);
    std::cout << ' ';
    if (energy == true) {
        SetConsoleTextAttribute(r.Handle, 11);
        SelectRandDirection(m);
    }
    else {
        SetConsoleTextAttribute(r.Handle, color);
        FillGhostMap(m);
        CreatePath();
        if (px[1] > 0 && px[1] < 27 && py[1] > 0 && py[1] < 31) {

            x = px[1];
            y = py[1];
        }
    }
    r.gotoxy(x, y);
    std::cout << 'M';
}

int Ghost::ReturnPositionX()
{
    return x;
}
int Ghost::ReturnPositionY() {
    return y;
}