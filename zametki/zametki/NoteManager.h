#pragma once

#include <vector>
#include <string>
#include "Note.h"
#include "PasswordNote.h"

class NoteManager {
private:
    std::vector<Note*> notes;
    std::string filename;

public:
    NoteManager(const std::string& filename);
    ~NoteManager();
    void addNote(Note* note);
    void displayNotes() const;
    void saveNotes() const;
    void loadNotes();

private:
    Note* createNoteFromData(const std::string& data) const;
};
