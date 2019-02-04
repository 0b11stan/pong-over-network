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
    Ball(Position &center, Movement &movement, int radius) : position(center), radius(radius), movement(movement) {}

    void display(PlayerOutput &playerOutput) const;

    void move() { position += movement; }

    Position getPosition() const { return position; }

    Movement &getMovement() const { return movement; }

    int getRadius() const { return radius; }

private:
    int radius;
    Movement &movement;
    Position &position;

    bool contains(Position point) const;

};


#endif //BROCKENBRICK_BALL_H
