//
// Created by tristan on 06/10/18.
//

#ifndef BROCKENBRICK_ROOM_H
#define BROCKENBRICK_ROOM_H


#include "PlayerOutput.h"
#include "Ball.h"
#include "PlayerInput.h"
#include "Pad.h"

class Room {

public:
    Room(Ball ball, Pad padPlayer, Pad padOpponent, int width, int height);

    void display(PlayerOutput &playerOutput);

    void process();

    void handle(Action &action);

    bool collide(Ball ball);

    bool collide(Pad pad, Movement padMovement);

    bool collidePlayer(Pad pad, Ball ball);

private:
    int thickness;
    int width;
    int height;
    Ball ball;
    Pad padPlayer;
    Pad padOpponent;

};


#endif //BROCKENBRICK_ROOM_H
