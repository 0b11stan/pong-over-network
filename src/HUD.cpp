//
// Created by tristan on 04/02/19.
//

#include "HUD.h"

HUD::HUD(Server &server, PlayerOutput &playerOutput) : server(server), playerOutput(playerOutput) {}

void HUD::display() {
    std::string ping = "ping : " + std::to_string(server.getPing());
    playerOutput.write(ping);
}
