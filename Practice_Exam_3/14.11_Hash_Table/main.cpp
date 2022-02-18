#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "hashTable.h"

using namespace std;

void getAllStudentsFromFile(string filename, hashTable& allStudents)
{

    istringstream inSS;

    ifstream input(filename);
    if (input.is_open()) {
        Student newStudent;
        while (input >> newStudent.name >> newStudent.major >> newStudent.id) {
            allStudents.insert(newStudent);
        }
    }
    else {
        cout << "Error! File not found." << endl;
    }
}

int main(int argc, char** argv)
{
    string filename = "students.txt";
    int size = 10;
    hashTable allStudents(size);

    getAllStudentsFromFile(filename, allStudents);
    allStudents.printAll();

    return 0;
}