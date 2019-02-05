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
    Action action = NONE;

    server.clearQueue();
    server.startStateSharing();

    do {
        playerOutput.clear();
        if (server.localIsReady() and server.remoteIsReady()) {
            playerOutput.setBackground(WHITE);
            process();
            display();
        } else if (server.localIsReady() and not server.remoteIsReady()) {
            playerOutput.setBackground(RED);
        } else {
            playerOutput.setBackground(WHITE);
        }
        playerOutput.render();
        playerInput.read(action);
        SDL_Delay(10);
    } while (handle(action));

    playerOutput.close();
}

void Game::process() {
    room.process();
}

void Game::display() const {
    room.display();
    hud.display();
}

bool Game::handle(Action &action) {
    switch (action) {
        case PRESS_UP_ARROW :
        case PRESS_DOWN_ARROW :
            room.handle(action);
            return true;
        case RETURN:
            server.sendReadiness();
            return true;
        case NONE:
            return true;
        case QUIT:
        default:
            server.close();
            return false;
    }
}
