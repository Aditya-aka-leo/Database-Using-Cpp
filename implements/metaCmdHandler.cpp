#include "../interfaces/metaCmdHandler.h"

void metaCmdHandler::parser() {
    if(userInputBuffer == ".exit") exitConsole();

    else cout << "Unrecognized command: " << userInputBuffer << endl;
}

void metaCmdHandler::exitConsole() {
    cout << "Exiting the console. Goodbye!" << endl;
    exit(0);
}