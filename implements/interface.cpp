#include "../interfaces/interface.h"

Interface::Interface() : inputBuffer(""), defaultPrompt("db> ") {}

void Interface::printDefaultPrompt() {
    cout << defaultPrompt;
}

void Interface::userInput() {
    inputBuffer.clear();
    getline(cin, inputBuffer);

    if (inputBuffer.empty()) {
        cout << "No command entered." << endl;
        return;
    }
}