#include "PasswordNote.h"
#include <iostream>

PasswordNote::PasswordNote(const std::string& title, const std::string& content, const std::string& password)
    : Note(title, content), password(password) {}

void PasswordNote::display() const {
    std::string inputPassword;
    std::cout << "Enter password to view note: ";
    std::cin >> inputPassword;
    if (inputPassword == password) {
        Note::display();
    }
    else {
        std::cout << "Incorrect password!" << std::endl;
    }
}

std::string PasswordNote::serialize() const {
    return Note::serialize() + "\n" + password;
}

void PasswordNote::deserialize(const std::string& data) {
    std::istringstream iss(data);
    std::getline(iss, title);
    std::getline(iss, content);
    std::getline(iss, password);
}
