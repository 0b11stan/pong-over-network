//
// Created by tristan on 01/10/18.
//

#ifndef BROCKENBRICK_PLAYEROUTPUT_H
#define BROCKENBRICK_PLAYEROUTPUT_H


#include <string>
#include "Position.h"

class PlayerOutput {

public:
    virtual void drawRedPoint(Position position) = 0;

    virtual void drawRect(Position position, int width, int height) = 0;

    virtual void drawPurpleBox(Position position, int width, int height, int thickness) = 0;

    virtual int getWidth() = 0;

    virtual int getHeight() = 0;

    virtual void close() = 0;

    virtual void clear() = 0;

    virtual void render() = 0;

    virtual void write(std::string &text, int x, int y) = 0;

};


#endif //BROCKENBRICK_PLAYEROUTPUT_H
