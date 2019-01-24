//
// Created by tristan on 06/10/18.
//

#include "Room.h"

Room::Room(Ball ball, Pad padPlayer, Pad padOpponent, int width, int height) :
    ball(ball), padPlayer(padPlayer), padOpponent(padOpponent),
    thickness(10), width(width), height(height) {}

void Room::display(PlayerOutput &playerOutput)
{
    if (collidePlayer(padPlayer, ball)) ball.getMovement().revert();
    else if (collide(ball)) ball.getMovement().revert();
    ball.move(ball.getMovement());

    playerOutput.drawPurpleBox(Position(0,0), playerOutput.getWidth(), playerOutput.getHeight(), thickness);
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

bool Room::collide(Ball ball)
{
    int ballNextY = (ball.getPosition() + ball.getMovement()).getY();
    bool ballIsBeforeRoomMinY = ballNextY - ball.getRadius() < thickness;
    bool ballIsAfterRoomMaxY = ballNextY + ball.getRadius() > height - thickness;

    return (ballIsBeforeRoomMinY or ballIsAfterRoomMaxY);
}

bool Room::collide(Pad pad, Movement padMovement)
{
    int padNextY = (pad.getPosition() + padMovement).getY();
    bool padIsBeforeRoomMinY = padNextY < thickness;
    bool padIsAfterRoomMaxY = padNextY + Pad::height > height - thickness;

    return ( padIsBeforeRoomMinY or padIsAfterRoomMaxY );
}

bool Room::collidePlayer(Pad pad, Ball ball)
{
    int ballNextY = (ball.getPosition() + ball.getMovement()).getY();
    int ballNextX = (ball.getPosition() + ball.getMovement()).getX();
    bool ballIsAfterPadMinY = ballNextY + ball.getRadius() > pad.getPosition().getY();
    bool ballIsAfterPadMaxX = ballNextX + ball.getRadius() > pad.getPosition().getX();
    bool ballIsBeforePadMaxY = ballNextY - ball.getRadius() < pad.getPosition().getY() + Pad::height;

    return (ballIsAfterPadMinY and ballIsBeforePadMaxY and ballIsAfterPadMaxX);
}
