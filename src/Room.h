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
    void handle(Action &action);
    bool collide(Ball ball, Movement movement);
    bool collide(Pad pad, Movement movement);
    bool collidePlayer(Pad pad, Ball ball, Movement movement);

private:
    Movement ballMovement;
    int thickness;
    int width;
    int height;
    Ball ball;
    Pad padPlayer;
    Pad padOpponent;

};


#endif //BROCKENBRICK_ROOM_H
