#include "GameMechanics.hpp"

void GameMechanics::Score(GameMap m, Render r,Player p) {
    SetConsoleTextAttribute(r.Handle, 5);
    r.gotoxy(10, -3);
    std::cout << "YOUR SCORE";
    if (m.ReturnMapSymbol(p.ReturnPositionX(), p.ReturnPositionY()) == '.' || m.ReturnMapSymbol(p.ReturnPositionX(), p.ReturnPositionY()) == 'o') {

        if (m.ReturnMapSymbol(p.ReturnPositionX(), p.ReturnPositionY()) == 'o') {
            Score(50);
            energy = true;
        }
        else {
            Score(10);
            dots++;
        }
        m.EditMapSymbol(p.ReturnPositionX(), p.ReturnPositionY(), ' ');
    }
    r.gotoxy(3, -2);
    std::cout << score;
}

void GameMechanics::Score(int i) {
    score += i;
}

void GameMechanics::SpawnAll(Render &r,Player &pl, ClassBlinky &bl, ClassPinky &pi) {
    pl.Spawn(r);
    bl.Spawn(r);
    pi.Spawn(r);
}

void GameMechanics::newLevel(Render &r, GameMap &m, Player &pl, ClassBlinky &bl, ClassPinky &pi) {

    SetConsoleTextAttribute(r.Handle, 2);
    r.gotoxy(20, -2);
    std::cout << 'L' << ' ' << level;
    if (dots == 240) {
        dots = 0;
        level++;
        system("cls");
        r.gotoxy(10, 15);
        std::cout << "LEVEL" << ' ' << level;
        m.CopyMap();
        Sleep(3000);
        SpawnAll(r,pl, bl, pi);
        system("cls");
        r.drawLevel(m,pl.ReturnPositionX(),pl.ReturnPositionY());

        _getch();
    }
}

void GameMechanics::Live(Player &pl,ClassBlinky &b, ClassPinky &pin, Render &r){
    if ((pl.ReturnPositionX()==b.ReturnPositionX() && pl.ReturnPositionY() == b.ReturnPositionY()) || (pl.ReturnPositionX() == pin.ReturnPositionX() && pl.ReturnPositionY() == pin.ReturnPositionY())) {
        if (energy == true) {
            if (pl.ReturnPositionX() == b.ReturnPositionX() && pl.ReturnPositionY() == b.ReturnPositionY()) {
                b.Spawn(r);
            }
            else pin.Spawn(r);
            Score(200);
        }
        else {
            lives--;
            pl.Spawn(r);
            b.Spawn(r);
            pin.Spawn(r);
            _getch();
        }
    }
    if (lives == 0) {
        r.inGame = false;
        
        
        SetConsoleTextAttribute(r.Handle, 4);
        system("cls");
        r.gotoxy(10, 15);
        std::cout << "You Lose";
        Sleep(3000);
    }
    SetConsoleTextAttribute(r.Handle, 6);
    r.gotoxy(1, 31);
    std::cout << "    ";
    for (int i = 0; lives > i; i++) {
        r.gotoxy(1 + i, 31);

        std::cout << '0';
    }
}

void GameMechanics::GameLoop(GameMap &m,Render &r,Player &pl, ClassBlinky &bl, ClassPinky &pi) {
    while (r.exitConsole == false) {
        r.Menu();
        while (r.inGame == true) {
            Score(m, r, pl);
            r.drawLevel(m, pl.ReturnPositionX(),pl.ReturnPositionY());
            Live(pl, bl, pi, r);
            
            pl.Movement(m, r);
            bl.Movement(pl.ReturnPositionX(), pl.ReturnPositionY(), m, r, energy);
            pi.Movement(dots, energy, m, r, pl);
            
            energyOff();
            newLevel(r, m, pl, bl, pi);
            Sleep(250);

        }
    }
}