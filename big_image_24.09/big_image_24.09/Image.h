#pragma once

#include <vector>
#include "Pixel.h"

class Image {
public:
    int width;
    int height;
    std::vector<std::vector<Pixel>> pixels;

    Image(int w, int h);
    void setPixel(int x, int y, const Color& color);
    void print() const;
};
