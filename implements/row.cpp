#include "../interfaces/row.h" 

using namespace std;

void Row::serializeRow(const Row& source, char* destination) {
    memcpy(destination + ID_OFFSET, &source.rowId, ID_SIZE);
    strncpy(destination + USERNAME_OFFSET, source.name.c_str(), USERNAME_SIZE);
    strncpy(destination + EMAIL_OFFSET, source.email.c_str(), EMAIL_SIZE);
}

void Row::deserializeRow(char* source, Row& destination) {
    memcpy(&destination.rowId, source + ID_OFFSET, ID_SIZE);
    destination.name = string(source + USERNAME_OFFSET, USERNAME_SIZE);
    destination.email = string(source + EMAIL_OFFSET, EMAIL_SIZE);
}


