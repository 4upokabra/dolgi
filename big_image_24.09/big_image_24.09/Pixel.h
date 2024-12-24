#pragma once

#include "Color.h"

class Pixel {
public:
    Color color;

    Pixel(const Color& c);
    void print() const;
};
