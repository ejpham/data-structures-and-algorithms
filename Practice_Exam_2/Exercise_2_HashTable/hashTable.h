#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>

using namespace std;

class Student {
public: 
  string name;
  string major;
  int id=-1;
};

#define EmptySinceStart -1
#define EmptyAfterRemoval -2

class hashTable {
private: 
  int count;
  Student *students;

public:
  hashTable(int tableSize=10);
  ~hashTable();
  int length() const;
  bool insert(const Student& newStudent);
  int getPos ( const int id);
  void printAll() const;
};

#endif