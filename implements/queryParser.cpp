#include "../interfaces/queryParser.h"

vector<string> QueryParser::tokenGen() {
    vector<string> tokens;

    stringstream ss(queryBuffer);

    string token;

    while (ss >> token) tokens.push_back(token);

    return tokens;
}

void QueryParser::parse() {

    vector<string> tokens;

    tokens = tokenGen();

    this->queryIdentifier = tokens[0];

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
