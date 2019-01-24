//
// Created by tristan on 06/10/18.
//

#include "Room.h"

Room::Room(Ball ball, Pad padPlayer, Pad padOpponent, int width, int height) :
    ball(ball), padPlayer(padPlayer), padOpponent(padOpponent),
    thickness(10), width(width), height(height), ballMovement(5,1) {}

void Room::display(PlayerOutput &playerOutput)
{
    playerOutput.drawPurpleBox(Position(0,0), playerOutput.getWidth(), playerOutput.getHeight(), thickness);
    if (collidePlayer(padPlayer, ball, ballMovement)) ballMovement.revert();
    ball.move(ballMovement);
    ball.display(playerOutput);
    padPlayer.display(playerOutput);
    padOpponent.display(playerOutput);
}

void Room::handle(Action &action) {
    Movement movement;
    switch (action) {
        case Action::PRESS_UP_ARROW :
            movement = { 0, -5 };
            if (!collide(padPlayer, movement)) padPlayer.move(movement);
            break;
        case Action::PRESS_DOWN_ARROW :
            movement = { 0, 5 };
            if (!collide(padPlayer, movement)) padPlayer.move(movement);
            break;
        default:
            break;
    }
}

bool Room::collide(Ball ball, Movement movement) {
    int ballNextY = (ball.getPosition() + movement).getY();
    int ballNextX = (ball.getPosition() + movement).getX();
    bool ball_is_after_room_min_x_limit = ballNextX - ball.getRadius() > thickness;
    bool ball_is_before_room_max_x_limit = ballNextX + ball.getRadius() < width - thickness;
    bool ball_is_after_room_min_y_limit = ballNextY - ball.getRadius() > thickness;
    bool ball_is_before_room_max_y_limit = ballNextY + ball.getRadius() < height - thickness;

    return not (
            ball_is_after_room_min_x_limit and
            ball_is_after_room_min_y_limit and
            ball_is_before_room_max_x_limit and
            ball_is_before_room_max_y_limit);
}

bool Room::collide(Pad pad, Movement movement) {
    bool pad_is_after_room_min_y = (pad.getPosition() + movement).getY() > thickness;
    bool pad_is_before_room_max_y = (pad.getPosition() + movement).getY() + Pad::height < height - thickness;

    return not ( pad_is_after_room_min_y and pad_is_before_room_max_y );
}

bool Room::collidePlayer(Pad pad, Ball ball, Movement movement) {
    int ballNextY = (ball.getPosition() + movement).getY();
    int ballNextX = (ball.getPosition() + movement).getX();

    bool ball_is_after_pad_min_y = ballNextY + ball.getRadius() > pad.getPosition().getY();
    bool ball_is_before_pad_max_y = ballNextY - ball.getRadius() < pad.getPosition().getY() + Pad::height;
    bool ball_is_after_pad_max_x = ballNextX + ball.getRadius() > pad.getPosition().getX();

    return (ball_is_after_pad_min_y and
            ball_is_before_pad_max_y and
            ball_is_after_pad_max_x);
}



