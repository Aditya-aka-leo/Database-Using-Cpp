#ifndef QUERY_PARSER_H
#define QUERY_PARSER_H

#include<bits/stdc++.h>

using namespace std;

class QueryParser {
public:
    string queryBuffer;
    string queryIdentifier;

    void parse();
    void insert();
    void update();
    void deleteQuery();
    void select();
    vector<string> tokenGen();
    

};


#endif
