//
// Created by tristan on 02/10/18.
//

#ifndef BROCKENBRICK_SDL2INPUT_H
#define BROCKENBRICK_SDL2INPUT_H


#include "PlayerInput.h"


class SDL2Input : public PlayerInput {

public:
    void read(Action &action) override;

};


#endif //BROCKENBRICK_SDL2INPUT_H
