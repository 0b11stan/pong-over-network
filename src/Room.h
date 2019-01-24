//
// Created by tristan on 06/10/18.
//

#ifndef BROCKENBRICK_ROOM_H
#define BROCKENBRICK_ROOM_H


#include "PlayerOutput.h"
#include "Ball.h"
#include "PlayerInput.h"

class Room {

public:
    Room(Ball ball, int width, int height);
    void display(PlayerOutput &playerOutput);
    void handle(Action &action);
    bool collide(Ball ball, Movement movement);

private:
    int thickness;
    int width;
    int height;
    Ball ball;

};


#endif //BROCKENBRICK_ROOM_H
