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

// TODO : utiliser stoi au lieux de isstringstream plus loin dans le code

int main(int argc, char *args[]) {
    SDL2Input playerInput;
    SDL2Output playerOutput;

    int localKey = 0;
    int remoteKey = 0;

    for (int n = 0; n < argc; n++) {
        if (args[n] == string("--local")) localKey = stoi(args[n+1]);
        if (args[n] == string("--remote")) remoteKey = stoi(args[n+1]);
    }

    if (localKey == 0 or remoteKey == 0) {
        printf("Player key is expected.\n\n  usage : ./pon --local <local key> --remote <remote key>\n\n");
        exit(EXIT_FAILURE);
    }

    Ball ball(playerOutput);
    LocalPlayer player(localKey, playerOutput);
    RemotePlayer opponent(remoteKey, playerOutput);
    Server server(player, opponent);

    Room room = Room(ball, player, opponent, playerOutput);
    HUD hud = HUD(server, playerOutput);

    Game game = Game(playerInput, playerOutput, room, hud, server);

    game.run();

    return 0;

}


