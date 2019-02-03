//
// Created by tristan on 02/10/18.
//

#include <cstdio>
#include <unistd.h>
#include "Game.h"

Game::Game(PlayerInput &playerInput, PlayerOutput &playerOutput, Room room, Server &server)
        : playerInput(playerInput), playerOutput(playerOutput), room(room), server(server) {}


void Game::run() {
    Action action;

    do {
        playerOutput.clear();
        display();
        playerOutput.render();
        playerInput.read(action);
        usleep(5000);
    } while (handle(action));

    playerOutput.close();

}

void Game::display() {
    room.process();
    room.display(playerOutput);
    std::string ping = "ping : " + std::to_string(server.ping());
    playerOutput.write(ping);
}


bool Game::handle(Action &action) {
    switch (action) {
        case Action::PRESS_UP_ARROW :
        case Action::PRESS_DOWN_ARROW :
            room.handle(action);
            return true;
        case NONE:
            return true;
        case QUIT:
        default:
            return false;
    }
}
