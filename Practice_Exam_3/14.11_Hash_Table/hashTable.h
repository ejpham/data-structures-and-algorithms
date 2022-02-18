#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>

using namespace std;

#define EmptySinceStart -1
#define EmptyAfterRemoval -2

class Student {
public:
	string name;
	string major;
	int id = EmptySinceStart;
};

class hashTable {
private:
	int count;
	Student* students;

public:
	hashTable(int tableSize = 10);
	~hashTable();
	int length() const;
	bool insert(const Student& newStudent);
	int getPos(const int id);
	void printAll() const;
};

#endif