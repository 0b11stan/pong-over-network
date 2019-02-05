//
// Created by tristan on 06/10/18.
//

#include "Room.h"


Room::Room(Ball &ball, Player &player, Player &opponent, PlayerOutput &playerOutput) : ball(ball), player(player),
                                                                                       opponent(opponent),
                                                                                       playerOutput(playerOutput) {
    width = playerOutput.getWidth();
    height = playerOutput.getHeight();
}

void Room::display() const {
    playerOutput.drawPurpleBox(Position(0, 0), playerOutput.getWidth(), playerOutput.getHeight(), thickness);
    ball.display();
    player.display();
    opponent.display();
}

void Room::process() {
    if (collidePlayer(player, ball)) ball.movement.horizontalRevert();
    else if (collide(ball)) ball.movement.horizontalRevert();
    ball.move();
}

void Room::handle(Action &action) {
    switch (action) {
        case Action::PRESS_UP_ARROW   :
            if (!collide(player, player.getUpMovement())) player.moveUp();
            break;
        case Action::PRESS_DOWN_ARROW :
            if (!collide(player, player.getDownMovement())) player.moveDown();
            break;
        default:
            break;
    }
}

const bool Room::collide(Ball &ball) const {
    int ballNextY = (ball.getPosition() + ball.movement).getY();
    bool ballIsBeforeRoomMinY = ballNextY - ball.getRadius() < thickness;
    bool ballIsAfterRoomMaxY = ballNextY + ball.getRadius() > height - thickness;

    return (ballIsBeforeRoomMinY or ballIsAfterRoomMaxY);
}

const bool Room::collide(const Player &player, Movement movement) const {
    int padNextY = (player.getPosition() + movement).getY();
    bool padIsBeforeRoomMinY = padNextY < thickness;
    bool padIsAfterRoomMaxY = padNextY + Player::height > height - thickness;

    return (padIsBeforeRoomMinY or padIsAfterRoomMaxY);
}

const bool Room::collidePlayer(Player &pad, Ball &ball) const {
    int ballNextY = (ball.getPosition() + ball.movement).getY();
    int ballNextX = (ball.getPosition() + ball.movement).getX();
    bool ballIsAfterPadMinY = ballNextY + ball.getRadius() > pad.getPosition().getY();
    bool ballIsAfterPadMaxX = ballNextX + ball.getRadius() > pad.getPosition().getX();
    bool ballIsBeforePadMaxY = ballNextY - ball.getRadius() < pad.getPosition().getY() + Player::height;

    return (ballIsAfterPadMinY and ballIsBeforePadMaxY and ballIsAfterPadMaxX);
}
