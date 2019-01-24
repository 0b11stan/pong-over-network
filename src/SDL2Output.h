//
// Created by tristan on 01/10/18.
//

#ifndef BROCKENBRICK_SDL2OUTPUT_H
#define BROCKENBRICK_SDL2OUTPUT_H


#include <SDL.h>
#include "PlayerOutput.h"

class SDL2Output : public PlayerOutput {

public:
    SDL2Output();
    int getWidth() override { return 1000; }
    int getHeight() override { return 1000; }
    void close() override;
    void clear() override;
    void drawRedPoint(Position position) override;
    void drawRect(Position center, int width, int height) override;
    void drawPurpleBox(Position position, int width, int height, int thickness) override;
    void render() override;

private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;


};


#endif //BROCKENBRICK_SDL2OUTPUT_H
