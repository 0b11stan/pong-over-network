//
// Created by tristan on 02/10/18.
//

#include "Movement.h"

Movement::Movement() : vertical(0), horizontal(0) {}

Movement::Movement(int vertical, int horizontal) : vertical(vertical), horizontal(horizontal) {}

int Movement::getX() { return vertical; }

int Movement::getY() { return horizontal; }

void Movement::revert() {
    vertical = -vertical;
    horizontal = -horizontal;
}


