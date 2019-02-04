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

    int playerKey = 456;
    int opponentKey = 123;

    Position positionPlayer = Position(
            playerOutput.getWidth() - 50 - Player::width,
            playerOutput.getHeight() / 2 - Player::height / 2);

    Position positionOpponent = Position(50, playerOutput.getHeight() / 2 - Player::height / 2);

    Player player = Player(playerKey, positionPlayer);
    Player opponent = Player(opponentKey, positionOpponent);

    Server server = Server(player, opponent);
    HUD hud = HUD(server, playerOutput);

    Ball ball = Ball(Position(200, 200), 50);

    Room room = Room(ball, player, opponent, playerOutput.getWidth(), playerOutput.getHeight());
    Game game = Game(playerInput, playerOutput, room, hud, server);
    game.run();

    return 0;

}


