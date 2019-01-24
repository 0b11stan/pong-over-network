//
// Created by tristan on 02/10/18.
//

#ifndef BROCKENBRICK_MOVEMENT_H
#define BROCKENBRICK_MOVEMENT_H


class Movement {

public:
    Movement();
    Movement(signed int vertical, signed int horizontal);
    void revert();
    signed int getX();
    signed int getY();

private:
    signed int vertical;
    signed int horizontal;

};


#endif //BROCKENBRICK_MOVEMENT_H
