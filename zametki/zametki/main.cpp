#include "NoteManager.h"

int main() {
    NoteManager manager("notes.txt");

    // Пример добавления заметок
    manager.addNote(new Note("Shopping List", "Buy milk and bread"));
    manager.addNote(new PasswordNote("Secret Note", "This is a secret", "1234"));

    // Сохранение заметок в файл
    manager.saveNotes();

    // Отображение заметок
    manager.displayNotes();

    return 0;
}
