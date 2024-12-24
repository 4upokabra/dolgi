#include "Matrix.h"
#include "MatrixInput.h"
#include "Logger.h"
#include <iostream>

int main() {
    Logger logger("operations.log");

    Matrix matrix1(0, 0, {});
    Matrix matrix2(0, 0, {});

    std::cout << "Choose input method for the first matrix (1 - console, 2 - file): ";
    int choice;
    std::cin >> choice;
    if (choice == 1) {
        readMatrixFromConsole(matrix1);
    }
    else if (choice == 2) {
        std::string filename;
        std::cout << "Enter filename: ";
        std::cin >> filename;
        readMatrixFromFile(matrix1, filename);
    }

    std::cout << "Choose input method for the second matrix (1 - console, 2 - file): ";
    std::cin >> choice;
    if (choice == 1) {
        readMatrixFromConsole(matrix2);
    }
    else if (choice == 2) {
        std::string filename;
        std::cout << "Enter filename: ";
        std::cin >> filename;
        readMatrixFromFile(matrix2, filename);
    }

    char operation;
    std::cout << "Enter operation (+ or *): ";
    std::cin >> operation;

    Matrix result(0, 0, {});
    if (operation == '+') {
        result = matrix1 + matrix2;
        logger.log("Matrix addition");
    }
    else if (operation == '*') {
        result = matrix1 * matrix2;
        logger.log("Matrix multiplication");
    }
    else {
        std::cerr << "Invalid operation" << std::endl;
        return 1;
    }

    std::cout << "Result:" << std::endl;
    result.print();

    return 0;
}
