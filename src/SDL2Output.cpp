//
// Created by tristan on 01/10/18.
//

#include "SDL2Output.h"

SDL2Output::SDL2Output() {
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    } else {
        window = SDL_CreateWindow(
                "SDL Tutorial",
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                getWidth(),
                getHeight(),
                SDL_WINDOW_SHOWN);

        if (window == nullptr) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        } else {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer == nullptr) {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            } else {
                if (TTF_Init() == -1) {
                    printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
                    success = false;
                } else {
                    regularFont = TTF_OpenFont("../font/OpenSans-Regular.ttf", 28);
                    if (regularFont == nullptr) {
                        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
                        success = false;
                    }
                    boldFont = TTF_OpenFont("../font/OpenSans-ExtraBold.ttf", 28);
                    if (boldFont == nullptr) {
                        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
                        success = false;
                    }
                }
            }
        }
    }

    // TODO : throw an exception on succes = false
}


void SDL2Output::close() {
    TTF_CloseFont(regularFont);
    regularFont = nullptr;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = nullptr;
    renderer = nullptr;
    TTF_Quit();
    SDL_Quit();
}


void SDL2Output::drawRedPoint(Position position) {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderDrawPoint(renderer, position.getX(), position.getY());
}


void SDL2Output::clear() {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
}


void SDL2Output::render() {
    SDL_RenderPresent(renderer);
}


void SDL2Output::drawRect(Position center, int width, int height) {
    SDL_Rect rect = {center.getX(), center.getY(), width, height};
    SDL_RenderFillRect(renderer, &rect);
}


void SDL2Output::drawPurpleBox(Position position, int width, int height, int thickness) {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);
    drawRect(position, width, height);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    drawRect(position + thickness, width - thickness * 2, height - thickness * 2);
}

void SDL2Output::writeText(string &text, int x, int y, int width, int height) {
    SDL_Color color = {0, 0, 0};

    SDL_Surface *surface = TTF_RenderText_Solid(regularFont, text.c_str(), color);
    SDL_Texture *pingTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    double rotation = 0.0;
    SDL_Point *center = nullptr;
    SDL_RendererFlip flip = SDL_FLIP_NONE;

    if (width == 0 or height == 0) {
        width = surface->w;
        height = surface->h;
    }
    SDL_Rect renderQuad = {x, y, width, height};

    SDL_RenderCopyEx(renderer, pingTexture, nullptr, &renderQuad, rotation, center, flip);

    SDL_DestroyTexture(pingTexture);
}

