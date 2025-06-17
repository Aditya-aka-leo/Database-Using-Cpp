#include "../interfaces/queryParser.h"

void QueryParser::tokenGen() {

    tokens.clear();

    stringstream ss(queryBuffer);

    string token;

    while (ss >> token) this->tokens.push_back(token);

    return;
}

void QueryParser::parse() {

    tokenGen();

    if(tokens.empty()) {
        cout << "No query provided." << endl;
        return;
    }

    this->queryIdentifier = this->tokens[0];

    if (queryIdentifier == "insert") insert();

    else if (queryIdentifier == "update") update();

    else if (queryIdentifier == "delete") deleteQuery();

    else if (queryIdentifier == "select") select();

    else cout << "Unknown query identifier: " << queryIdentifier << endl;
    
}

void QueryParser::insert() {
    cout << "Processing INSERT query: " << queryBuffer << endl;

    if (tokens.size() < 4) {
        cout << "Invalid INSERT query. Usage: insert <name> <email>" << endl;

        return;
    }

    vm->insertRow(tokens);
}

void QueryParser::update() {
    cout << "Processing UPDATE query: " << queryBuffer << endl;
}

void QueryParser::deleteQuery() {
    cout << "Processing DELETE query: " << queryBuffer << endl;
}

void QueryParser::select() {
    cout << "Processing SELECT query: " << queryBuffer << endl;

    if (tokens.empty()) {
        cout << "No rows available." << endl;
        return;
    }

    vm->selectRow();
}
