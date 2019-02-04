//
// Created by tristan on 04/02/19.
//

#ifndef PONG_OVER_NETWORK_HUD_H
#define PONG_OVER_NETWORK_HUD_H


#include "Server.h"
#include "PlayerOutput.h"

class HUD {

public:
    explicit HUD(Server &server, PlayerOutput &playerOutput);

    void display();

private:
    Server &server;
    PlayerOutput &playerOutput;

};


#endif //PONG_OVER_NETWORK_HUD_H
