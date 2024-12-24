#include "Color.h"
#include <iostream>

Color::Color(int r, int g, int b) : red(r), green(g), blue(b) {}

void Color::print() const {
    std::cout << "Color: (" << red << ", " << green << ", " << blue << ")\n";
}
