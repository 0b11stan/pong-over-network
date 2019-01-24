//
// Created by tristan on 02/10/18.
//

#ifndef BROCKENBRICK_PLAYERINPUT_H
#define BROCKENBRICK_PLAYERINPUT_H


enum Action {
    PRESS_UP_ARROW,
    PRESS_DOWN_ARROW,
    QUIT,
    NONE
};

class PlayerInput {

public:
    virtual void read(Action &action) = 0;

};


#endif //BROCKENBRICK_PLAYERINPUT_H
