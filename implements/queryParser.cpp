#include "../interfaces/queryParser.h"

void QueryParser::tokenGen() {

    tokens.clear();

    stringstream ss(queryBuffer);

    string token;

    while (ss >> token) this->tokens.push_back(token);

    for(auto i : tokens) {
        cout << i << " ";
    }

    return;
}

void QueryParser::parse() {

    tokenGen();


    this->queryIdentifier = this->tokens[0];

    if (queryIdentifier == "insert") insert();

    else if (queryIdentifier == "update") update();

    else if (queryIdentifier == "delete") deleteQuery();

    else if (queryIdentifier == "select") select();

    else cout << "Unknown query identifier: " << queryIdentifier << endl;
    
}

void QueryParser::insert() {
    cout << "Processing INSERT query: " << queryBuffer << endl;
}

void QueryParser::update() {
    cout << "Processing UPDATE query: " << queryBuffer << endl;
}

void QueryParser::deleteQuery() {
    cout << "Processing DELETE query: " << queryBuffer << endl;
}

void QueryParser::select() {
    cout << "Processing SELECT query: " << queryBuffer << endl;
}
