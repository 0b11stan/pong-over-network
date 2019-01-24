//
// Created by tristan on 24/01/19.
//

#include "Pad.h"

Pad::Pad(Position position) : position(position) {}

void Pad::display(PlayerOutput &playerOutput) {
    playerOutput.drawRect(position, width, height);
}

void Pad::move(Movement movement) {
    position += movement;
}

Position Pad::getPosition() { return position; }
