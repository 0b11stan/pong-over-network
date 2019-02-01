//
// Created by tristan on 01/10/18.
//

#include <SDL2/SDL.h>
#include "SDL2Output.h"
#include "SDL2Input.h"
#include "Position.h"
#include "Ball.h"
#include "Game.h"
#include "Pad.h"
#include "HTTP.h"
#include "Server.h"


int main(int argc, char *args[]) {
    SDL2Input playerInput;
    SDL2Output playerOutput;

    HTTP http("http://syllab.com/PTRE839", "255058");
    Server server(http);

//    printf("aide : %s", server.help().c_str());

    server.ping();
//    printf("ping : %s", server.ping().c_str());

//    remote.requestHelp();
//
//
//    Position positionPlayer = Position(
//            playerOutput.getWidth() - 50 - Pad::width,
//            playerOutput.getHeight() / 2 - Pad::height / 2);
//
//    Position positionOpponent = Position(50, playerOutput.getHeight() / 2 - Pad::height / 2);
//
//    Pad padPlayer = Pad(positionPlayer);
//    Pad padOpponent = Pad(positionOpponent);
//    Ball ball = Ball(Position(200, 200), 50);
//
//    Room room = Room(ball, padPlayer, padOpponent, playerOutput.getWidth(), playerOutput.getHeight());
//    Game game = Game(playerInput, playerOutput, room);
//    game.run();

    return 0;

}


