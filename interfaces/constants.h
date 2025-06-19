#pragma once

#include <bits/stdc++.h>  

using namespace std;

const size_t ID_SIZE = sizeof(uint32_t);
const size_t USERNAME_SIZE = 32;
const size_t EMAIL_SIZE = 255;

const size_t ID_OFFSET = 0;
const size_t USERNAME_OFFSET = ID_OFFSET + ID_SIZE;
const size_t EMAIL_OFFSET = USERNAME_OFFSET + USERNAME_SIZE;

const size_t ROW_SIZE = ID_SIZE + USERNAME_SIZE + EMAIL_SIZE;

const size_t PAGE_SIZE = 4096;
const size_t ROWS_PER_PAGE = PAGE_SIZE / ROW_SIZE;
const size_t TABLE_MAX_PAGES = 100; 