#include "../interfaces/virtualMachine.h"

virtualMachine::virtualMachine(Pager* pagerInstance) {
    this->pager = pagerInstance;

    int numFullPages = pager->fileLength / PAGE_SIZE;

    numRows = numFullPages * ROWS_PER_PAGE;

}

void virtualMachine::insertRow(vector<string> tokens) {
    if (tokens.size() < 4) {
        cout << "Invalid INSERT query. Usage: insert <name> <email>" << endl;
        return;
    }

    Row newRow = {static_cast<uint32_t>(stoi(tokens[1])), tokens[2], tokens[3]}; 

    if(numRows >= MAX_PAGES * ROWS_PER_PAGE) {
        cout << "Table is full. Cannot insert more rows." << endl;
        return;
    }

    char *slot = getRowSlot(numRows);

    newRow.serializeRow(newRow, slot);

    numRows++;

    cout << "Inserted row with ID: " << newRow.rowId << endl;

}

void virtualMachine::selectRow() {
     if (numRows == 0) {
        cout << "No rows available." << endl;
        return;
    }

    cout << "ID\tName\tEmail" << endl;
    
    for(int i = 0; i < numRows; i++) {
        char *slot = getRowSlot(i);

        Row row;
        row.deserializeRow(slot, row);

        if (row.rowId == 0 && row.name.empty() && row.email.empty()) continue;
    
        cout << row.rowId << "\t" << row.name << "\t" << row.email << endl;
    }
}

char*  virtualMachine::getRowSlot(int rowNum) {
    int pageNum = rowNum / ROWS_PER_PAGE;

    char* page = pager->getPage(pageNum);

    int rowOffset = rowNum % ROWS_PER_PAGE;

    return page + (rowOffset * ROW_SIZE);

}