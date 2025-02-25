#pragma once

#include <fstream>
#include <stdexcept>
#include <string>

class Logger {
public:
    Logger(const std::string& filename);
    ~Logger();
    void log(const std::string& message);

private:
    std::ofstream logFile;
};
