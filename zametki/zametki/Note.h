#pragma once

#include <string>
#include <sstream>

class Note {
protected:
    std::string title;
    std::string content;

public:
    Note(const std::string& title, const std::string& content);
    virtual void display() const;
    virtual std::string serialize() const;
    virtual void deserialize(const std::string& data);
    virtual ~Note();
};
