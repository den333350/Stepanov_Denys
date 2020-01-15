
#include"GameMechanics.hpp"

void GameMechanics::energyOff() {
    if (energy == true) {
        energyScore++;
        if (energyScore == 36) {
            energy = false;
            energyScore = 0;
        }
    }
}

void GameMechanics::Score(int i) {
    score += i;
}
