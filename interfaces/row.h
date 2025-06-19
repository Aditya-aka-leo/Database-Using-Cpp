#pragma once

#include <bits/stdc++.h>  
#include "constants.h"
using namespace std;

class Row {
public:
    uint32_t rowId;

    string name, email;

    void serializeRow(const Row& source, char* destination);
    
    void deserializeRow(char* source, Row& destination);
};
