//
// Created by tristan on 04/02/19.
//

#ifndef PONG_OVER_NETWORK_LOCALPLAYER_H
#define PONG_OVER_NETWORK_LOCALPLAYER_H


#include "Player.h"

class LocalPlayer : public Player {

public:
    LocalPlayer(int apiKey, PlayerOutput &playerOutput) :
            Player(apiKey, Position(playerOutput.getWidth() - 50 - Player::width,
                                    playerOutput.getHeight() / 2 - Player::height / 2), playerOutput) {}

};


#endif //PONG_OVER_NETWORK_LOCALPLAYER_H
