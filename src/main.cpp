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
#include "LocalPlayer.h"
#include "RemotePlayer.h"
#include "PlayerPicker.h"


int main(int argc, char *args[]) {
    SDL2Input playerInput;
    SDL2Output playerOutput;

    PlayerPicker playerPicker(playerInput, playerOutput);
    playerPicker.run();

//    Ball ball(playerOutput);
//    LocalPlayer player(playerPicker.localPlayer, playerOutput);
//    RemotePlayer opponent(playerPicker.remotePlayer, playerOutput);
//    Server server(player, opponent);
//
//    Room room = Room(ball, player, opponent, playerOutput);
//    HUD hud = HUD(server, playerOutput);
//
//    Game game = Game(playerInput, playerOutput, room, hud, server);
//
//    game.run();

//    const string HTTP::baseKEY = "255058";
//    int playerKey = 456;
//    int opponentKey = 123;

    return 0;

}


