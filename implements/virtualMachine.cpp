#include "../interfaces/virtualMachine.h"

void virtualMachine::insertRow(vector<string> tokens) {
    if (tokens.size() < 4) {
        cout << "Invalid INSERT query. Usage: insert <name> <email>" << endl;
        return;
    }

    row newRow = {stoi(tokens[1]), tokens[2], tokens[3]}; 

    rows.push_back(newRow);

    cout << "Inserted row with ID: " << newRow.rowId << endl;

}

void virtualMachine::selectRow() {
    if (rows.empty()) {
        cout << "No rows available." << endl;
        return;
    }

    cout << "ID\tName\tEmail" << endl;
    for (auto r : rows) {
        cout << r.rowId << "\t" << r.name << "\t" << r.email << endl;
    }
}
