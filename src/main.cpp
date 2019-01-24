//
// Created by tristan on 01/10/18.
//

#include <SDL2/SDL.h>
#include "SDL2Output.h"
#include "SDL2Input.h"
#include "Position.h"
#include "Ball.h"
#include "Game.h"


int main( int argc, char* args[] )
{
    SDL2Input playerInput;
    SDL2Output playerOutput;
    Ball ball = Ball(Position(200, 200), 100);
    Room room = Room(ball, playerOutput.getWidth(), playerOutput.getHeight());

    Game game = Game(playerInput, playerOutput, room);
    game.run();

    return 0;

}


