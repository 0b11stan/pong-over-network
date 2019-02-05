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
    explicit Ball(PlayerOutput &playerOutput) :
            position(Position(playerOutput.getWidth() / 2, playerOutput.getHeight() / 2)), playerOutput(playerOutput) {}

    void display() const;

    void move() { position += movement; }

    void bounceBottom() { movement.verticalRevert(); }

    void bounceTop() { movement.verticalRevert(); }

    void bounceLeft() { movement.horizontalRevert(); }

    void bounceRight() { movement.horizontalRevert(); }

    Movement getMovement() const { return movement; }

    Position getPosition() const { return position; }

    int getRadius() const { return radius; }

private:
    Movement movement = Movement(2, 5);
    const int radius = 50;
    PlayerOutput &playerOutput;
    Position position;

    bool contains(Position point) const;

};


#endif //BROCKENBRICK_BALL_H
