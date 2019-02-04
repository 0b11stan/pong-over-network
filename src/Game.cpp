//
// Created by tristan on 02/10/18.
//

#include <cstdio>
#include <unistd.h>
#include <SDL_timer.h>
#include "Game.h"

Game::Game(PlayerInput &playerInput, PlayerOutput &playerOutput, Room &room, HUD &hud, Server &server)
        : playerInput(playerInput), playerOutput(playerOutput), room(room), hud(hud), server(server) {}


void Game::run() {
    Action action;

    server.startStateSharing();

    do {
        playerOutput.clear();
        process();
        display();
        playerOutput.render();
        playerInput.read(action);
        SDL_Delay(10);
    } while (handle(action));

    playerOutput.close();
}

void Game::process() {
    room.process();
}

void Game::display() {
    room.display(playerOutput);
    hud.display();
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
            server.close();
            return false;
    }
}
