//
// Created by tristan on 24/01/19.
//

#ifndef BROCKENBRICK_PAD_H
#define BROCKENBRICK_PAD_H


#include "Position.h"
#include "PlayerOutput.h"

class Player {

public:
    Player(int apiKey, Position &position, Movement &movement) :
            position(position), apiKey(apiKey), movement(movement) {}

    const static int height = 200;
    const static int width = 40;
    Position &position;

    void display(PlayerOutput &playerOutput) const { playerOutput.drawRect(position, width, height); }

    const int &getKey() const { return apiKey; }

    const Movement &getMovement() const { return movement; }

    void moveUp() { position += Movement(0, -movement.getY()); }

    void moveDown() { position += movement; }


private:
    Movement &movement;
    const int apiKey;

};


#endif //BROCKENBRICK_PAD_H
