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
    Room(Ball &ball, Player &player, Player &opponent, PlayerOutput &playerOutput);

    static const int thickness = 10;

    void display() const;

    void process();

    void handle(Action &action);

    const bool collideBottomWall(Ball &ball) const;
    
    const bool collideTopWall(Ball &ball) const;

    const bool collide(const Player &player, Movement movement) const;

    const bool collidePlayer(Player &pad, Ball &ball) const;

    const Player getPlayer() const { return player; }

    const Player getOpponent() const { return opponent; }

private:
    int width;
    int height;
    PlayerOutput &playerOutput;
    Ball &ball;
    Player &player;
    Player &opponent;

};


#endif //BROCKENBRICK_ROOM_H
