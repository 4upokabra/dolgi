#include "Note.h"
#include <iostream>

Note::Note(const std::string& title, const std::string& content)
    : title(title), content(content) {}

void Note::display() const {
    std::cout << "Title: " << title << "\nContent: " << content << std::endl;
}

std::string Note::serialize() const {
    return title + "\n" + content;
}

void Note::deserialize(const std::string& data) {
    std::istringstream iss(data);
    std::getline(iss, title);
    std::getline(iss, content);
}

Note::~Note() {}
