#include "Render.hpp"
#include "Player.hpp"
#include "Blinky.hpp"
#include "Pinky.hpp"
#ifndef GAMEMECHANICS_HPP
#define GAMEMECHANICS_HPP

class GameMechanics {

    bool energy = false;
    
    int lives = 3;
    int score = 0;
    int dots = 0;
    int level = 1;
    int energyScore = 0;

    void energyOff() {
        int energyScore = 0;
        if (energy == true) {
            energyScore++;
            if (energyScore > 36 - level * 3) {
                energy = false;
                energyScore = 0;
            }
        }
    }

    void newLevel(Render &r, GameMap &m, Player &pl, ClassBlinky &bl, ClassPinky &pi);
    void Score(GameMap m, Render r, Player p);
    void Score(int i);
    void Live(Player &pl, ClassBlinky &b, ClassPinky &pin, Render &r);
    void SpawnAll(Render &r,Player &pl, ClassBlinky &bl, ClassPinky &pi);
public:
    void GameLoop(GameMap &m, Render &r, Player &pl, ClassBlinky &bl, ClassPinky &pi);
};
#endif
