#include "Matrix.h"

Matrix::Matrix(uint32_t rows, uint32_t columns, const std::vector<std::vector<int>>& data)
    : rows(rows), columns(columns), data(data) {
    if (data.size() != rows || data[0].size() != columns) {
        throw std::invalid_argument("Data size does not match rows and columns");
    }
}

Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || columns != other.columns) {
        throw std::invalid_argument("Matrices dimensions do not match for addition");
    }
    std::vector<std::vector<int>> result(rows, std::vector<int>(columns));
    for (uint32_t i = 0; i < rows; ++i) {
        for (uint32_t j = 0; j < columns; ++j) {
            result[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return Matrix(rows, columns, result);
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (columns != other.rows) {
        throw std::invalid_argument("Matrices dimensions do not match for multiplication");
    }
    std::vector<std::vector<int>> result(rows, std::vector<int>(other.columns, 0));
    for (uint32_t i = 0; i < rows; ++i) {
        for (uint32_t j = 0; j < other.columns; ++j) {
            for (uint32_t k = 0; k < columns; ++k) {
                result[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return Matrix(rows, other.columns, result);
}

void Matrix::print() const {
    for (const auto& row : data) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}
