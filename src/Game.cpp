//
// Created by tristan on 02/10/18.
//

#include <cstdio>
#include "Game.h"

Game::Game(PlayerInput &playerInput, PlayerOutput &playerOutput, Room room)
: playerInput(playerInput), playerOutput(playerOutput), room(room) {}


void Game::run()
{
    Action action;

    do {
        playerOutput.clear();
        display();
        playerOutput.render();
        playerInput.read(action);
    }
    while( handle(action) );

    playerOutput.close();

}

void Game::display() {
    room.display(playerOutput);
}


bool Game::handle(Action &action) {
    switch (action) {
        case Action::PRESS_UP_ARROW :
        case Action::PRESS_DOWN_ARROW :
        case Action::PRESS_LEFT_ARROW :
        case Action::PRESS_RIGHT_ARROW :
            room.handle(action);
            return true;
        case NONE: return true;
        case QUIT:
        default:
            return false;
    }
}
