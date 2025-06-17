#ifndef INTERFACE_H
#define INTERFACE_H

#include<bits/stdc++.h>
using namespace std;

class Interface {
public:
    string inputBuffer;
    string defaultPrompt;

    Interface();

    void printDefaultPrompt();

    void userInput();

};

#endif
