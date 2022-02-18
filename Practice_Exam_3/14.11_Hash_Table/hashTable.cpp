#include <iostream>
#include "hashTable.h"

hashTable::hashTable(int tableSize) {
    count = tableSize;
    students = new Student[count];
    for (int i = 0; i < count; i++)
        students[i].id = EmptySinceStart;
}

hashTable::~hashTable() {
    delete[] students;
}

int hashTable::length() const {
    return count;
}

bool hashTable::insert(const Student& newItem) {
    // Implement this function using the alternating linear probing approach
    int pos = newItem.id % count;
    int bucketsProbed = 0;
    int offset = 0;

    while (bucketsProbed < count) {
        if ((pos + offset) < count && (students[pos + offset].id == EmptySinceStart || students[pos + offset].id == EmptyAfterRemoval)) {
            students[pos + offset] = newItem;
            break;
        }

        if ((pos - offset) >= 0 && (students[pos - offset].id == EmptySinceStart || students[pos - offset].id == EmptyAfterRemoval)) {
            students[pos - offset] = newItem;
            break;
        }
        if (offset == 0) bucketsProbed++;
        else bucketsProbed += 2;
        offset++;
    }
    if (bucketsProbed >= count) return false;
    return true;
}

// DO NOT MODIFY FUNCTIONS BELOW
int hashTable::getPos(const int id) {
    for (int pos = 0; pos < count; pos++)
        if (students[pos].id == id) return pos;
    return -1;
}

void hashTable::printAll() const {
    for (auto i = 0; i < count; i++) {
        if (students[i].id != EmptySinceStart || students[i].id == EmptyAfterRemoval)
            std::cout << i << " : " << students[i].name << " Id " << students[i].id << endl;
    }
}