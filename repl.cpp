#include <bits/stdc++.h>
#include "./interfaces/interface.h"
#include "./interfaces/metaCmdHandler.h"
#include "./interfaces/queryParser.h"

using namespace std;

int main()
{
    Interface ui;
    metaCmdHandler metaCmd;
    QueryParser queryParser;

    while(1){

        ui.printDefaultPrompt();
        ui.userInput();

        if(ui.inputBuffer.empty()) {
            cout << "No command entered." << endl;
            
            continue;
        }
        
        if(ui.inputBuffer[0] == '.'){
            metaCmd.userInputBuffer = ui.inputBuffer;
            metaCmd.parser();
        }
        else{
            queryParser.queryBuffer = ui.inputBuffer;
            queryParser.parse();
        }
        
    }
    return 0;
}