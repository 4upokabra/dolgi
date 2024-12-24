#include "NoteManager.h"

int main() {
    NoteManager manager("notes.txt");

    // ������ ���������� �������
    manager.addNote(new Note("Shopping List", "Buy milk and bread"));
    manager.addNote(new PasswordNote("Secret Note", "This is a secret", "1234"));

    // ���������� ������� � ����
    manager.saveNotes();

    // ����������� �������
    manager.displayNotes();

    return 0;
}
