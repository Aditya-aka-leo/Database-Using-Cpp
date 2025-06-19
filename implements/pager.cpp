#include "../interfaces/pager.h"

Pager::Pager(const string& filename): fileLength(0), pages(TABLE_MAX_PAGES, nullptr) {
    openDBFile(filename);
}

void Pager::openDBFile(const string &fileName) {
    dbFile.open(fileName, ios::in | ios::out | ios::binary);

    if (!dbFile.is_open()) {
        dbFile.open(fileName, ios::out | ios::binary);

        dbFile.close();

        dbFile.open(fileName, ios::in | ios::out | ios::binary);
    }

    dbFile.seekg(0, ios::end);

    fileLength = dbFile.tellg();
}

char* Pager::getPage(int pageNum) {
    if (pageNum < 0 || pageNum >= TABLE_MAX_PAGES)  throw out_of_range("Page number out of range");

    if (pages[pageNum] == nullptr) {
        pages[pageNum] = new char[PAGE_SIZE];

        int numPagesInFile = fileLength / PAGE_SIZE;

        if (fileLength % PAGE_SIZE != 0) numPagesInFile++;

        if (pageNum < numPagesInFile) {
            dbFile.seekg(pageNum * PAGE_SIZE, std::ios::beg);

            dbFile.read(pages[pageNum], PAGE_SIZE);

        }

        else memset(pages[pageNum], 0, PAGE_SIZE);
        
    }

    return pages[pageNum];
}

void Pager::flushPage(int page_num) {
    if (pages[page_num] == nullptr) throw std::runtime_error("Attempted to flush null page");

    dbFile.seekp(page_num * PAGE_SIZE, std::ios::beg);

    dbFile.write(pages[page_num], PAGE_SIZE);

    dbFile.flush();
}

Pager::~Pager() {
    for (int i = 0; i < TABLE_MAX_PAGES; ++i) {
        if (pages[i]) {
            flushPage(i);

            delete[] pages[i];

            pages[i] = nullptr;
        }
    }

    if (dbFile.is_open()) dbFile.close();
}