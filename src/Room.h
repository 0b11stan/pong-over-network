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
    Room(Ball &ball, Player &player, Player &opponent, int width, int height, int thickness,
         PlayerOutput &playerOutput);

    void display() const;

    void process();

    void handle(Action &action);

    const bool collide(Ball &ball) const;

    const bool collide(const Player &player, const Movement &movement) const;

    const bool collidePlayer(Player &pad, Ball &ball) const;

    const Player getPlayer() const { return player; }

    const Player getOpponent() const { return opponent; }

private:
    int thickness;
    int width;
    int height;
    PlayerOutput &playerOutput;
    Ball &ball;
    Player &player;
    Player &opponent;

};


#endif //BROCKENBRICK_ROOM_H
