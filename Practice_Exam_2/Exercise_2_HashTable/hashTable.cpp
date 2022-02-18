#include <iostream>
#include "hashTable.h"

hashTable::hashTable ( int tableSize )
{
    count = tableSize;
    students = new Student[count];
    for ( int i=0; i< count; i++ ) {
        students[i].id = EmptySinceStart;        
    }
}

hashTable::~hashTable ()
{
    delete[] students;
}

int hashTable::length() const
{
    return count;
}

bool hashTable::insert ( const Student &newItem )
{
   // Implement hashTable insert using linear Probing  using Student id as the key.
    int pos = newItem.id % count;
    int bucketsProbed = 0;
    while (bucketsProbed < count) {
        if (students[pos].id == EmptySinceStart ||
            students[pos].id == EmptyAfterRemoval) {
            break;
        }
        pos = (pos + 1) % count;
        bucketsProbed++;
    }

    if (bucketsProbed == count) {
        return false;
    }

    students[pos] = newItem;
    return true;
}

int hashTable::getPos( const int id )
{
    int pos = id %count;
    int bucketsProbed=0;
    while ( students[pos].id != EmptySinceStart &&
            bucketsProbed < count ) {
        if ( students[pos].id != EmptyAfterRemoval &&
            students[pos].id == id ) {
            return pos;
        }
        pos = (pos+1)%count;
        bucketsProbed++;
    }

    return -1;
}


void hashTable::printAll () const
{
    for ( auto i = 0; i < count; i++ ) {
        if ( students[i].id != EmptySinceStart || students[i].id == EmptyAfterRemoval ) {
            std::cout << i << " : " << students[i].name << " Id " << students[i].id << endl;
        }
    }
}
