//
// Created by tristan on 01/10/18.
//

#include <SDL2/SDL.h>
#include "SDL2Output.h"
#include "SDL2Input.h"
#include "Position.h"
#include "Ball.h"
#include "Game.h"
#include "Player.h"
#include "HTTP.h"
#include "Server.h"
#include "HUD.h"


int main(int argc, char *args[]) {
    SDL2Input playerInput;
    SDL2Output playerOutput;

    Movement ballMovement = Movement(0, 0);
    Position ballPosition = Position(playerOutput.getWidth() / 2, playerOutput.getHeight() / 2);
    Ball ball = Ball(ballPosition, ballMovement, 50);

    Movement playerMovement = Movement(0, 5);
    Position playerPosition = Position(
            playerOutput.getWidth() - 50 - Player::width,
            playerOutput.getHeight() / 2 - Player::height / 2);
    Player player = Player(123, playerPosition, playerMovement);

    Movement opponentMovement = Movement(0, 5);
    Position opponentPosition = Position(50, playerOutput.getHeight() / 2 - Player::height / 2);
    Player opponent = Player(456, opponentPosition, opponentMovement);

    Server server = Server(player, opponent);

    Room room = Room(ball, player, opponent, playerOutput.getWidth(), playerOutput.getHeight(), 10, playerOutput);
    HUD hud = HUD(server, playerOutput);

    Game game = Game(playerInput, playerOutput, room, hud, server);

    game.run();
            /*
//const string HTTP::baseKEY = "255058";
    int playerKey = 456;
    int opponentKey = 123;


    Server server = Server(player, opponent);
    HUD hud = HUD(server, playerOutput);

    Ball ball = Ball(Position(200, 200), 50);

    Room room = Room(ball, player, opponent, playerOutput.getWidth(), playerOutput.getHeight());
    Game game = Game(playerInput, playerOutput, room, hud, server);
    game.run();
             */

    return 0;

}


