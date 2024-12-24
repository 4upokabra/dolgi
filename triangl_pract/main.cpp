#include <iostream>
#include <fstream>

#include "Triangle.hpp"

int main() {
    try {
        Geometry::Point points[3] = {
            Geometry::Point(0, 0),
            Geometry::Point(3, 2),
            Geometry::Point(1, 1),
        };
        Geometry::Triangle t1(points);
        // t1.print();
        std::cout << t1 << std::endl;
        std::ofstream file("output.txt");
        file << t1 << std::endl;
        file.close();

        std::cout << "Drawing triangle:\n";
        t1.draw();
    }
    catch (std::string e) {
        ((std::cout << "ERROR: ") << e) << std::endl;
    }
    return 0;
}
