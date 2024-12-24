#pragma once

#include <string>
#include <vector>
#include <windows.h>

class PEParser {
public:
    PEParser(const std::string& filePath);
    ~PEParser();

    bool Parse();
    void PrintImportedFunctions();

private:
    std::string filePath;
    HANDLE fileHandle;
    HANDLE fileMapping;
    LPVOID fileBase;
    PIMAGE_DOS_HEADER dosHeader;
    PIMAGE_NT_HEADERS ntHeaders;

    bool MapFile();
    void UnmapFile();
    bool ValidatePE();
    void ParseImports();

    std::vector<std::string> importedFunctions;
};
