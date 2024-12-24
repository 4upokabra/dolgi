#include "MatrixInput.h"
#include <fstream>
#include <iostream>

void readMatrixFromConsole(Matrix& matrix) {
    uint32_t rows, columns;
    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of columns: ";
    std::cin >> columns;
    std::vector<std::vector<int>> data(rows, std::vector<int>(columns));
    std::cout << "Enter matrix elements: " << std::endl;
    for (uint32_t i = 0; i < rows; ++i) {
        for (uint32_t j = 0; j < columns; ++j) {
            std::cin >> data[i][j];
        }
    }
    matrix = Matrix(rows, columns, data);
}

void readMatrixFromFile(Matrix& matrix, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file");
    }
    uint32_t rows, columns;
    file >> rows >> columns;
    std::vector<std::vector<int>> data(rows, std::vector<int>(columns));
    for (uint32_t i = 0; i < rows; ++i) {
        for (uint32_t j = 0; j < columns; ++j) {
            file >> data[i][j];
        }
    }
    file.close();
    matrix = Matrix(rows, columns, data);
}
