#ifndef virtualMachine_h
#define virtualMachine_h

#include<bits/stdc++.h>
#include "row.h"

using namespace std;

class virtualMachine {
public:
    vector<row> rows;

    void insertRow(vector<string> tokens);
    
    void deleteRow();

    void updateRow(vector<string> tokens);

    void selectRow();

};

#endif
