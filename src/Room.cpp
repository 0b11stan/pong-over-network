//
// Created by tristan on 06/10/18.
//

#include "Room.h"

Room::Room(Ball &ball, Player &player, Player &opponent, int width, int height) :
        ball(ball), player(player), opponent(opponent), thickness(10), width(width), height(height) {}

void Room::display(PlayerOutput &playerOutput) {
    playerOutput.drawPurpleBox(Position(0, 0), playerOutput.getWidth(), playerOutput.getHeight(), thickness);
    ball.display(playerOutput);
    player.display(playerOutput);
    opponent.display(playerOutput);
}

void Room::process() {
    if (collidePlayer(player, ball)) ball.getMovement().revert();
    else if (collide(ball)) ball.getMovement().revert();
    ball.move(ball.getMovement());
}

void Room::handle(Action &action) {
    Movement movement;
    switch (action) {
        case Action::PRESS_UP_ARROW :
            movement = {0, -5};
            if (!collide(player, movement)) player.move(movement);
            break;
        case Action::PRESS_DOWN_ARROW :
            movement = {0, 5};
            if (!collide(player, movement)) player.move(movement);
            break;
        default:
            break;
    }
}

bool Room::collide(Ball ball) {
    int ballNextY = (ball.getPosition() + ball.getMovement()).getY();
    bool ballIsBeforeRoomMinY = ballNextY - ball.getRadius() < thickness;
    bool ballIsAfterRoomMaxY = ballNextY + ball.getRadius() > height - thickness;

    return (ballIsBeforeRoomMinY or ballIsAfterRoomMaxY);
}

bool Room::collide(Player &player, Movement &movement) {
    int padNextY = (player.getPosition() + movement).getY();
    bool padIsBeforeRoomMinY = padNextY < thickness;
    bool padIsAfterRoomMaxY = padNextY + Player::height > height - thickness;

    return (padIsBeforeRoomMinY or padIsAfterRoomMaxY);
}

bool Room::collidePlayer(Player pad, Ball ball) {
    int ballNextY = (ball.getPosition() + ball.getMovement()).getY();
    int ballNextX = (ball.getPosition() + ball.getMovement()).getX();
    bool ballIsAfterPadMinY = ballNextY + ball.getRadius() > pad.getPosition().getY();
    bool ballIsAfterPadMaxX = ballNextX + ball.getRadius() > pad.getPosition().getX();
    bool ballIsBeforePadMaxY = ballNextY - ball.getRadius() < pad.getPosition().getY() + Player::height;

    return (ballIsAfterPadMinY and ballIsBeforePadMaxY and ballIsAfterPadMaxX);
}
