#pragma once 

#include<bits/stdc++.h>
#include "constants.h"

using namespace std;

class Pager {
public:
    Pager(const string& filename);

    ~Pager();

    char* getPage(int pageNum);

    void flushPage(int pageNum);

    int getFileLength();

    int fileLength;
private:
    fstream dbFile;


    vector<char*> pages;

    void openDBFile(const string &fileName);
};
