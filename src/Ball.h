//
// Created by tristan on 02/10/18.
//

#ifndef BROCKENBRICK_BALL_H
#define BROCKENBRICK_BALL_H


#include "PlayerOutput.h"
#include "Position.h"
#include "Movement.h"

class Ball {

public:
    Ball(Position center, int radius);
    void display(PlayerOutput &playerOutput);
    void move(Movement movement);
    Position getPosition();
    int getRadius();

private:
    int radius;
    Position position;
    bool contains(Position point);

};


#endif //BROCKENBRICK_BALL_H
