//
// Created by tristan on 04/02/19.
//

#ifndef PONG_OVER_NETWORK_PLAYERPICKER_H
#define PONG_OVER_NETWORK_PLAYERPICKER_H


#include "PlayerInput.h"
#include "PlayerOutput.h"

class PlayerPicker {

public:
    PlayerPicker(PlayerInput &playerInput, PlayerOutput &playerOutput) : playerInput(playerInput),
                                                                         playerOutput(playerOutput) {}

    void run();

    const int topChoice = 123;
    const int bottomChoice = 456;
    int selected = 123;

private:
    PlayerInput &playerInput;
    PlayerOutput &playerOutput;

    bool handle(Action &action);

    void selectTopChoice() { selected = topChoice; }

    void selectBottomChoice() { selected = bottomChoice; }

    void display() const;

};


#endif //PONG_OVER_NETWORK_PLAYERPICKER_H
