#include "../interfaces/metaCmdHandler.h"

bool metaCmdHandler::parser() {
    if (userInputBuffer == ".exit") return exitConsole();

    else {
        cout << "Unrecognized command: " << userInputBuffer << std::endl;
        return false;
    }
}

bool metaCmdHandler::exitConsole() {
    cout << "Exiting the console. Goodbye!" <<endl;
    return true; 
}
