//
// Created by tristan on 04/02/19.
//

#include <SDL_timer.h>
#include "PlayerPicker.h"

void PlayerPicker::run() {
    Action action;
    do {
        playerOutput.clear();
        display();
        playerOutput.render();
        playerInput.read(action);
        SDL_Delay(10);
    } while(handle(action));
}

bool PlayerPicker::handle(Action &action) {
    switch (action) {
        case PRESS_UP_ARROW :
            selectTopChoice();
            return true;
        case PRESS_DOWN_ARROW :
            selectBottomChoice();
            return true;
        case NONE:
            return true;
        case QUIT:
        default:
            return false;
    }
}

void PlayerPicker::display() const {
    string first("player " + to_string(topChoice));
    string second("player " + to_string(bottomChoice));

    first = selected == topChoice ? ">  " + first : "   " + first;
    playerOutput.write(first);

    second = selected == bottomChoice ? ">  " + second : "   " + second;
    playerOutput.write(second, 0, 30);
}
