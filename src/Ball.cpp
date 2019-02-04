//
// Created by tristan on 02/10/18.
//

#include <cmath>
#include <cstdio>
#include "Ball.h"


void Ball::display() const {
    // limit of a box containing the circle
    int minX = position.getX() - radius;
    int minY = position.getY() - radius;
    int maxX = position.getX() + radius;
    int maxY = position.getY() + radius;

    // iter inside this box to draw the circle when needed
    for (int y = minY; y <= maxY; y++)
        for (int x = minX; x <= maxX; x++) {
            Position point = Position(x, y);
            if (contains(point)) playerOutput.drawRedPoint(point);
        }
}

bool Ball::contains(Position point) const {
    return pow(point.getX() - position.getX(), 2) + pow(point.getY() - position.getY(), 2) <= pow(radius, 2);
}




