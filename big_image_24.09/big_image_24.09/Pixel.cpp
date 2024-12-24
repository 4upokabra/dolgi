#include "Pixel.h"

Pixel::Pixel(const Color& c) : color(c) {}

void Pixel::print() const {
    color.print();
}
