#include "PEParser.h"
#include <iostream>

PEParser::PEParser(const std::string& filePath)
    : filePath(filePath), fileHandle(INVALID_HANDLE_VALUE), fileMapping(NULL), fileBase(NULL), dosHeader(NULL), ntHeaders(NULL) {}

PEParser::~PEParser() {
    UnmapFile();
}

bool PEParser::Parse() {
    if (!MapFile()) {
        return false;
    }

    if (!ValidatePE()) {
        UnmapFile();
        return false;
    }

    ParseImports();
    return true;
}

void PEParser::PrintImportedFunctions() {
    for (const auto& func : importedFunctions) {
        std::cout << func << std::endl;
    }
}

bool PEParser::MapFile() {
    fileHandle = CreateFileA(filePath.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (fileHandle == INVALID_HANDLE_VALUE) {
        std::cerr << "Failed to open file." << std::endl;
        return false;
    }

    fileMapping = CreateFileMappingA(fileHandle, NULL, PAGE_READONLY, 0, 0, NULL);
    if (fileMapping == NULL) {
        std::cerr << "Failed to create file mapping." << std::endl;
        CloseHandle(fileHandle);
        return false;
    }

    fileBase = MapViewOfFile(fileMapping, FILE_MAP_READ, 0, 0, 0);
    if (fileBase == NULL) {
        std::cerr << "Failed to map view of file." << std::endl;
        CloseHandle(fileMapping);
        CloseHandle(fileHandle);
        return false;
    }

    dosHeader = (PIMAGE_DOS_HEADER)fileBase;
    ntHeaders = (PIMAGE_NT_HEADERS)((LPBYTE)fileBase + dosHeader->e_lfanew);
    return true;
}

void PEParser::UnmapFile() {
    if (fileBase != NULL) {
        UnmapViewOfFile(fileBase);
    }
    if (fileMapping != NULL) {
        CloseHandle(fileMapping);
    }
    if (fileHandle != INVALID_HANDLE_VALUE) {
        CloseHandle(fileHandle);
    }
}

bool PEParser::ValidatePE() {
    if (dosHeader->e_magic != IMAGE_DOS_SIGNATURE) {
        std::cerr << "Invalid DOS signature." << std::endl;
        return false;
    }
    if (ntHeaders->Signature != IMAGE_NT_SIGNATURE) {
        std::cerr << "Invalid NT signature." << std::endl;
        return false;
    }
    return true;
}

void PEParser::ParseImports() {
    IMAGE_DATA_DIRECTORY importDirectory = ntHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
    PIMAGE_IMPORT_DESCRIPTOR importDescriptor = (PIMAGE_IMPORT_DESCRIPTOR)((LPBYTE)fileBase + importDirectory.VirtualAddress);

    while (importDescriptor->Characteristics != 0) {
        PIMAGE_THUNK_DATA thunk = (PIMAGE_THUNK_DATA)((LPBYTE)fileBase + importDescriptor->OriginalFirstThunk);
        PIMAGE_THUNK_DATA func;

        while (thunk->u1.AddressOfData != 0) {
            if (thunk->u1.Ordinal & IMAGE_ORDINAL_FLAG) {
                // Ordinal import
                func = (PIMAGE_THUNK_DATA)((LPBYTE)fileBase + importDescriptor->FirstThunk + (thunk - (PIMAGE_THUNK_DATA)((LPBYTE)fileBase + importDescriptor->OriginalFirstThunk)) * sizeof(IMAGE_THUNK_DATA));
                importedFunctions.push_back(std::to_string(func->u1.Ordinal & 0xFFFF));
            }
            else {
                // Name import
                PIMAGE_IMPORT_BY_NAME importByName = (PIMAGE_IMPORT_BY_NAME)((LPBYTE)fileBase + thunk->u1.AddressOfData);
                func = (PIMAGE_THUNK_DATA)((LPBYTE)fileBase + importDescriptor->FirstThunk + (thunk - (PIMAGE_THUNK_DATA)((LPBYTE)fileBase + importDescriptor->OriginalFirstThunk)) * sizeof(IMAGE_THUNK_DATA));
                importedFunctions.push_back(std::string((char*)importByName->Name));
            }
            thunk++;
        }
        importDescriptor++;
    }
}
