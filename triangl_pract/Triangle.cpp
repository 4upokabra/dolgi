#include "Triangle.hpp"

#include <iostream>
#include <cmath>

namespace Geometry {

    static inline float get_length_of_vec(const Point& p1, const Point& p2) {
        return static_cast<float>(std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)));
    }

    Point::Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    Triangle::Triangle(Point points[3]) {
        float l1 = get_length_of_vec(points[0], points[1]);
        float l2 = get_length_of_vec(points[2], points[1]);
        float l3 = get_length_of_vec(points[0], points[2]);

        if (l1 + l2 <= l3 || l1 + l3 <= l2 || l2 + l3 <= l1) {
            throw std::string("Is not a triangle");
        }

        this->points[0] = points[0];
        this->points[1] = points[1];
        this->points[2] = points[2];
    }

    void Triangle::print() const {
        std::cout << this->points[0].x << " " << this->points[0].y << std::endl;
        std::cout << this->points[1].x << " " << this->points[1].y << std::endl;
        std::cout << this->points[2].x << " " << this->points[2].y << std::endl;
    }

    std::ostream& operator<<(std::ostream& os, Triangle& obj) {
        os << obj.points[0].x << " " << obj.points[0].y << std::endl;
        os << obj.points[1].x << " " << obj.points[1].y << std::endl;
        os << obj.points[2].x << " " << obj.points[2].y;
        return os;
    }

    void Triangle::draw() const {
        Bresenham::draw_line(points[0], points[1]);
        Bresenham::draw_line(points[1], points[2]);
        Bresenham::draw_line(points[2], points[0]);
    }
}
