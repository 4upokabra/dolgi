#pragma once

#include "Note.h"

class PasswordNote : public Note {
private:
    std::string password;

public:
    PasswordNote(const std::string& title, const std::string& content, const std::string& password);
    void display() const override;
    std::string serialize() const override;
    void deserialize(const std::string& data) override;
};
