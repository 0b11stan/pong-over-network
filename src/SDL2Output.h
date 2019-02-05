//
// Created by tristan on 01/10/18.
//

#ifndef BROCKENBRICK_SDL2OUTPUT_H
#define BROCKENBRICK_SDL2OUTPUT_H


#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include "PlayerOutput.h"

using namespace std;

class SDL2Output : public PlayerOutput {

public:
    SDL2Output();

    int getWidth() override { return 1000; }

    int getHeight() override { return 1000; }

    void close() override;

    void clear() override;

    void setBackground(BG_COLOR color) override { bg_color = color; }

    void drawRedPoint(Position position) override;

    void drawRect(Position center, int width, int height) override;

    void drawPurpleBox(Position position, int width, int height, int thickness) override;

    void render() override;

    void write(string &text) override { writeText(text); }

    void write(string &text, int x, int y) override { writeText(text, x, y); }

    void write(string &text, int x, int y, int width, int height) override {
        writeText(text, x, y, width, height);
    }


private:
    BG_COLOR bg_color = WHITE;
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    TTF_Font *regularFont;
    TTF_Font *boldFont;

    void writeText(string &text, int x = 0, int y = 0, int width = 0, int height = 0);
};


#endif //BROCKENBRICK_SDL2OUTPUT_H
