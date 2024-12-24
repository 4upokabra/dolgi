#include "Image.h"

int main() {
    Image image(3, 3);
    image.setPixel(0, 0, Color(255, 0, 0));
    image.setPixel(1, 1, Color(0, 255, 0));
    image.setPixel(2, 2, Color(0, 0, 255));
    image.print();
    return 0;
}
