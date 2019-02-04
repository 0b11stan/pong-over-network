//
// Created by tristan on 06/10/18.
//

#include "Room.h"


Room::Room(Ball &ball, Player &player, Player &opponent, int width, int height, int thickness,
           PlayerOutput &playerOutput) : ball(ball), player(player), opponent(opponent), width(width), height(height),
                                         thickness(thickness), playerOutput(playerOutput) {}

void Room::display() const {
    playerOutput.drawPurpleBox(Position(0, 0), playerOutput.getWidth(), playerOutput.getHeight(), thickness);
    ball.display(playerOutput);
    player.display(playerOutput);
    opponent.display(playerOutput);
}

void Room::process() {
    if (collidePlayer(player, ball)) ball.getMovement().horizontalRevert();
    else if (collide(ball)) ball.getMovement().horizontalRevert();
    ball.move();
}

void Room::handle(Action &action) {
    switch (action) {
        case Action::PRESS_UP_ARROW   : if (!collide(player, player.getMovement())) player.moveUp(); break;
        case Action::PRESS_DOWN_ARROW : if (!collide(player, player.getMovement())) player.moveDown(); break;
        default:
            break;
    }
}

const bool Room::collide(Ball &ball) const {
    int ballNextY = (ball.getPosition() + ball.getMovement()).getY();
    bool ballIsBeforeRoomMinY = ballNextY - ball.getRadius() < thickness;
    bool ballIsAfterRoomMaxY = ballNextY + ball.getRadius() > height - thickness;

    return (ballIsBeforeRoomMinY or ballIsAfterRoomMaxY);
}

const bool Room::collide(const Player &player, const Movement &movement) const {
    int padNextY = (player.position + movement).getY();
    bool padIsBeforeRoomMinY = padNextY < thickness;
    bool padIsAfterRoomMaxY = padNextY + Player::height > height - thickness;

    return (padIsBeforeRoomMinY or padIsAfterRoomMaxY);
}

const bool Room::collidePlayer(Player &pad, Ball &ball) const {
    int ballNextY = (ball.getPosition() + ball.getMovement()).getY();
    int ballNextX = (ball.getPosition() + ball.getMovement()).getX();
    bool ballIsAfterPadMinY = ballNextY + ball.getRadius() > pad.position.getY();
    bool ballIsAfterPadMaxX = ballNextX + ball.getRadius() > pad.position.getX();
    bool ballIsBeforePadMaxY = ballNextY - ball.getRadius() < pad.position.getY() + Player::height;

    return (ballIsAfterPadMinY and ballIsBeforePadMaxY and ballIsAfterPadMaxX);
}
