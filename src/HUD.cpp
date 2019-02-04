//
// Created by tristan on 04/02/19.
//

#include "HUD.h"

void HUD::display() const {
    std::string ping = "ping : " + std::to_string(server.getPing());
    playerOutput.write(ping);
}
