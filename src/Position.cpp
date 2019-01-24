//
// Created by tristan on 02/10/18.
//

#include "Position.h"

Position::Position(int x, int y) : abscissa(x), ordinate(y) {}

int Position::getX() { return abscissa; }
int Position::getY() { return ordinate; }

Position& Position::operator+=(Movement &movement) {
    *this = *this + movement;
    return *this;
}

Position Position::operator+(Movement &movement)
{
    return { abscissa + movement.getX(), ordinate + movement.getY() };
}

Position Position::operator+(const int margin) const
{
    return { abscissa + margin, ordinate + margin };
}

