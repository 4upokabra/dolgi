#pragma once

#include <vector>
#include <stdexcept>
#include <iostream>

class Matrix {
public:
    Matrix(uint32_t rows, uint32_t columns, const std::vector<std::vector<int>>& data);
    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    void print() const;

private:
    uint32_t rows;
    uint32_t columns;
    std::vector<std::vector<int>> data;
};
