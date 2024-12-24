#include "NoteManager.h"
#include <fstream>
#include <iostream>

NoteManager::NoteManager(const std::string& filename) : filename(filename) {
    loadNotes();
}

NoteManager::~NoteManager() {
    for (Note* note : notes) {
        delete note;
    }
}

void NoteManager::addNote(Note* note) {
    notes.push_back(note);
}

void NoteManager::displayNotes() const {
    for (const Note* note : notes) {
        note->display();
    }
}

void NoteManager::saveNotes() const {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const Note* note : notes) {
            outFile << note->serialize() << "\n---\n";
        }
        outFile.close();
    }
    else {
        std::cerr << "Unable to open file for writing!" << std::endl;
    }
}

void NoteManager::loadNotes() {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        std::string line, data;
        while (std::getline(inFile, line)) {
            if (line == "---") {
                if (!data.empty()) {
                    Note* note = createNoteFromData(data);
                    if (note) {
                        notes.push_back(note);
                    }
                    data.clear();
                }
            }
            else {
                data += line + "\n";
            }
        }
        inFile.close();
    }
    else {
        std::cerr << "Unable to open file for reading!" << std::endl;
    }
}

Note* NoteManager::createNoteFromData(const std::string& data) const {
    std::istringstream iss(data);
    std::string title, content, password;
    std::getline(iss, title);
    std::getline(iss, content);
    if (std::getline(iss, password)) {
        return new PasswordNote(title, content, password);
    }
    else {
        return new Note(title, content);
    }
}
