#include <iostream>
#include "PEParser.h"

int main() {
    PEParser parser("C:\\Users\\maybe\\OneDrive\\Рабочий стол\\C++\\dolgs\\PEparser\\PEparser\\exem\\RaylibGame.exe");
    if (!parser.Parse()) {
        std::cerr << "Failed to parse PE file." << std::endl;
        return 1;
    }

    parser.PrintImportedFunctions();
    return 0;
}
