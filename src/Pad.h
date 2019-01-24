//
// Created by tristan on 24/01/19.
//

#ifndef BROCKENBRICK_PAD_H
#define BROCKENBRICK_PAD_H


#include "Position.h"
#include "PlayerOutput.h"

class Pad {

public:
    Pad(Position position);
    const static int height = 200;
    const static int width = 40;
    void display(PlayerOutput &playerOutput);
    void move(Movement movement);
    Position getPosition();

private:
    Position position;

};


#endif //BROCKENBRICK_PAD_H
