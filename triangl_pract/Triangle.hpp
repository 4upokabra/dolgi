#pragma once

#include <iostream>
#include "Bresenham.hpp"

namespace Geometry {
    class Triangle {
    public:
        Triangle(Point points[3]);
        void print() const;
        void draw() const; // Новая функция для рисования треугольника
    private:
        Point points[3];
        friend std::ostream& operator<<(std::ostream& os, Triangle& obj);
    };

    std::ostream& operator<<(std::ostream& os, Triangle& obj);
}
