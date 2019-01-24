//
// Created by tristan on 02/10/18.
//

#ifndef BROCKENBRICK_GAME_H
#define BROCKENBRICK_GAME_H


#include "PlayerInput.h"
#include "PlayerOutput.h"
#include "Ball.h"
#include "Room.h"

class Game {

public:
    Game(PlayerInput &playerInput, PlayerOutput &playerOutput, Room room);

    void run();

private:
    PlayerInput &playerInput;
    PlayerOutput &playerOutput;
    Room room;

    void display();

    bool handle(Action &action);

};


#endif //BROCKENBRICK_GAME_H
