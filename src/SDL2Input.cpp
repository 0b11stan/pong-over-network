//
// Created by tristan on 02/10/18.
//

#include <SDL_events.h>
#include "SDL2Input.h"

void SDL2Input::read(Action &action) {
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) action = Action::QUIT;
        else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    action = Action::PRESS_UP_ARROW;
                    break;
                case SDLK_DOWN:
                    action = Action::PRESS_DOWN_ARROW;
                    break;
                case SDLK_RETURN:
                    action = Action::RETURN;
                    break;
                default:
                    action = Action::NONE;
                    break;
            }
        } else action = Action::NONE;
    }
}
