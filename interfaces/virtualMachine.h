#pragma once

#include<bits/stdc++.h>
#include "row.h"
#include "pager.h"

using namespace std;

class virtualMachine {
public:
    vector<Row> rows;

    static const int MAX_PAGES = TABLE_MAX_PAGES;

    Pager* pager;

    virtualMachine(Pager* pager);
    
    int numRows = 0;

    void insertRow(vector<string> tokens);
    
    void deleteRow();

    void updateRow(vector<string> tokens);

    void selectRow();

    
private:
    char* getRowSlot(int rowNum);
};