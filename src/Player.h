//
// Created by tristan on 24/01/19.
//

#ifndef BROCKENBRICK_PAD_H
#define BROCKENBRICK_PAD_H


#include "Position.h"
#include "PlayerOutput.h"

class Player {

public:
    explicit Player(int key, Position &position);

    const static int height = 200;
    const static int width = 40;

    void display(PlayerOutput &playerOutput);

    const int getKey() { return key; }

    Position &getPosition() { return position; };

    void move(Movement movement);


private:
    Position &position;
    const int key;

};


#endif //BROCKENBRICK_PAD_H
