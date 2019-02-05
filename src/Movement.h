//
// Created by tristan on 02/10/18.
//

#ifndef BROCKENBRICK_MOVEMENT_H
#define BROCKENBRICK_MOVEMENT_H


class Movement {

public:
    Movement() : x(0), y(0) {}

    Movement(int vertical, int horizontal) : x(vertical), y(horizontal) {}

    void horizontalRevert() { x = -x; }

    void verticalRevert() { y = -y; }

    int getX() const { return x; }

    int getY() const { return y; }

private:
    int x;
    int y;

};


#endif //BROCKENBRICK_MOVEMENT_H
