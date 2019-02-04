//
// Created by tristan on 24/01/19.
//

#include "Player.h"

Player::Player(int key, Position &position) : position(position), key(key) {}

void Player::display(PlayerOutput &playerOutput) { playerOutput.drawRect(position, width, height); }

void Player::move(Movement movement) { position += movement; }

