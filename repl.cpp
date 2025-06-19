#include <bits/stdc++.h>
#include "./interfaces/interface.h"
#include "./interfaces/metaCmdHandler.h"
#include "./interfaces/queryParser.h"
#include "./interfaces/virtualMachine.h"
#include "./interfaces/pager.h"

using namespace std;

int main()
{
    Interface ui;

    metaCmdHandler metaCmd;

    auto pager = make_unique<Pager>("mydb.db");

    virtualMachine vm(pager.get());

    QueryParser queryParser(&vm);

    while (true) {
        ui.printDefaultPrompt();

        ui.userInput();

        if (ui.inputBuffer.empty()) {
            cout << "No command entered." << endl;

            continue;
        }

        if (ui.inputBuffer[0] == '.') {
            metaCmd.userInputBuffer = ui.inputBuffer;

            if (metaCmd.parser()) break;
        }
        else {
            queryParser.queryBuffer = ui.inputBuffer;

            queryParser.parse();
        }
    }

    return 0;
}
