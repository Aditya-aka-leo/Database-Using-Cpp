#pragma once

#include<bits/stdc++.h>
#include "virtualMachine.h"

using namespace std;

class QueryParser {
public:
    string queryBuffer, queryIdentifier;

    vector<string> tokens;

    virtualMachine* vm;

    QueryParser(virtualMachine* vmInstance) : vm(vmInstance) {}

    void parse();
    
private:
    void tokenGen();

    void insert();

    void update();

    void deleteQuery();

    void select();
};
