//
// Created by tristan on 04/02/19.
//

#ifndef PONG_OVER_NETWORK_REMOTEPLAYER_H
#define PONG_OVER_NETWORK_REMOTEPLAYER_H


#include "Player.h"

class RemotePlayer : public Player {

public:
    RemotePlayer(int apiKey, PlayerOutput &playerOutput) :
            Player(apiKey, Position(50, playerOutput.getHeight() / 2 - Player::height / 2), playerOutput) {}

    void updateY(int y) { position.setY(y); }
};


#endif //PONG_OVER_NETWORK_REMOTEPLAYER_H
