//
// Created by tristan on 06/10/18.
//

#include "Room.h"

Room::Room(Ball ball, int width, int height) : ball(ball), thickness(10), width(width), height(height) {}

void Room::display(PlayerOutput &playerOutput)
{
    playerOutput.drawPurpleBox(Position(0,0), playerOutput.getWidth(), playerOutput.getHeight(), thickness);
    ball.display(playerOutput);
}

void Room::handle(Action &action) {
    Movement movement;
    switch (action) {
        case Action::PRESS_UP_ARROW :
            movement = { 0, -10 };
            if (!collide(ball, movement)) ball.move(movement);
            break;
        case Action::PRESS_DOWN_ARROW :
            movement = { 0, 10 };
            if (!collide(ball, movement)) ball.move(movement);
            break;
        case Action::PRESS_LEFT_ARROW :
            movement = { -10, 0 };
            if (!collide(ball, movement)) ball.move(movement);
            break;
        case Action::PRESS_RIGHT_ARROW :
            movement = { 10, 0 };
            if (!collide(ball, movement)) ball.move(movement);
            break;
        default:
            break;
    }
}


bool Room::collide(Ball ball, Movement movement) {
    bool ball_is_after_room_min_x_limit = (ball.getPosition() + movement).getX() - ball.getRadius() > thickness;
    bool ball_is_before_room_max_x_limit = (ball.getPosition() + movement).getX() + ball.getRadius() < width - thickness;
    bool ball_is_after_room_min_y_limit = (ball.getPosition() + movement).getY() - ball.getRadius() > thickness;
    bool ball_is_before_room_max_y_limit = (ball.getPosition() + movement).getY() + ball.getRadius() < height - thickness;

    return not (
            ball_is_after_room_min_x_limit and
            ball_is_after_room_min_y_limit and
            ball_is_before_room_max_x_limit and
            ball_is_before_room_max_y_limit);
}

