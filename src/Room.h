//
// Created by tristan on 06/10/18.
//

#ifndef BROCKENBRICK_ROOM_H
#define BROCKENBRICK_ROOM_H


#include "PlayerOutput.h"
#include "Ball.h"
#include "PlayerInput.h"
#include "Player.h"

class Room {

public:
    Room(Ball &ball, Player &player, Player &opponent, int width, int height);

    void display(PlayerOutput &playerOutput);

    void process();

    void handle(Action &action);

    bool collide(Ball ball);

    bool collide(Player &player, Movement &movement);

    bool collidePlayer(Player pad, Ball ball);

    const Player getPlayer() { return player; }

    const Player getOpponent() { return opponent; }


private:
    int thickness;
    int width;
    int height;
    Ball ball;
    Player &player;
    Player &opponent;

};


#endif //BROCKENBRICK_ROOM_H
