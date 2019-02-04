//
// Created by tristan on 02/10/18.
//

#ifndef BROCKENBRICK_POSITION_H
#define BROCKENBRICK_POSITION_H


#include "Movement.h"

class Position {

public:
    Position(int x, int y) : x(x), y(y) {}

    const int getX() const { return x; }

    const int getY() const { return y; }

    void setY(const int y) { this->y = y; }

    Position &operator+=(const Movement &movement) { *this = *this + movement; return *this; }

    Position operator+(const Movement &movement) const { return { x + movement.getX(), y + movement.getY() }; }

    Position operator+(const int margin) const { return { x + margin, y + margin }; }

private:
    int x;
    int y;

};


#endif //BROCKENBRICK_POSITION_H
