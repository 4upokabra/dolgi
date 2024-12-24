#pragma once

#include <iostream>

namespace Geometry {
    struct Point {
        int x;
        int y;

        Point(int x, int y);
        Point() = default;
    };

    class Bresenham {
    public:
        static void draw_line(const Point& p1, const Point& p2);
    };
}
