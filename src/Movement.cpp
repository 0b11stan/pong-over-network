//
// Created by tristan on 02/10/18.
//

#include "Movement.h"

Movement::Movement() : horizontal(0), vertical(0) {}

Movement::Movement(int vertical, int horizontal) : horizontal(vertical), vertical(horizontal) {}

int Movement::getX() { return horizontal; }

int Movement::getY() { return vertical; }

void Movement::revert() {
    horizontal = -horizontal;
}


