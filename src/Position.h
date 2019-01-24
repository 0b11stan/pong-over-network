//
// Created by tristan on 02/10/18.
//

#ifndef BROCKENBRICK_POSITION_H
#define BROCKENBRICK_POSITION_H


#include "Movement.h"

class Position {

public:
    Position(int x, int y);
    int getX();
    int getY();
    Position& operator+=(Movement &movement);
    Position operator+(Movement &movement);
    Position operator+(int margin) const;

private:
    int abscissa;
    int ordinate;

};


#endif //BROCKENBRICK_POSITION_H
