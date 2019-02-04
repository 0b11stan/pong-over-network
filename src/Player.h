//
// Created by tristan on 24/01/19.
//

#ifndef BROCKENBRICK_PAD_H
#define BROCKENBRICK_PAD_H


#include "Position.h"
#include "PlayerOutput.h"

class Player {

public:
    Player(int apiKey, Position position, PlayerOutput &playerOutput) : position(position), apiKey(apiKey),
                                                                         playerOutput(playerOutput) {}

    const static int height = 200;
    const static int width = 40;

    void display() const { playerOutput.drawRect(position, width, height); }

    const Position &getPosition() const { return position; }

    const Movement &getMovement() const { return movement; }

    const int &getKey() const { return apiKey; }


    void moveUp() { position += Movement(0, -movement.getY()); }

    void moveDown() { position += movement; }


private:
    Movement movement = Movement(0, 5);
    PlayerOutput &playerOutput;
    const int apiKey;

protected:
    Position position;

};


#endif //BROCKENBRICK_PAD_H
