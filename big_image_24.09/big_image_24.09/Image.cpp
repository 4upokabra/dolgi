#include "Image.h"
#include <iostream> // Добавьте этот заголовочный файл

Image::Image(int w, int h) : width(w), height(h), pixels(h, std::vector<Pixel>(w, Pixel(Color(0, 0, 0)))) {}

void Image::setPixel(int x, int y, const Color& color) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        pixels[y][x] = Pixel(color);
    }
}

void Image::print() const {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            pixels[y][x].print();
        }
        std::cout << "\n";
    }
}
