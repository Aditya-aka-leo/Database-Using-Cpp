#pragma once

#include<bits/stdc++.h>

using namespace std;

class Interface {
public:
    string inputBuffer, defaultPrompt;
    
    Interface();

    void printDefaultPrompt();

    void userInput();

};
