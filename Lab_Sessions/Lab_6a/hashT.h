#ifndef HASHT_H
#define HASHT_H

#include <string>
#include <iostream>
#include <sstream>

using namespace std;


enum IndexStatus
{
	TRUE,
	FALSE,
	DELETED
};

template <class elemType>
class hashT
{
public:
	hashT(int size = 101);
	void insert(const elemType& rec);
	int search(const elemType& rec, bool& found) const;
	void remove(const elemType& rec);
	string print() const;
	~hashT();

protected:
	int nextProbingPlace(int place_now, int probing_time) const;
	int hashFunction(const elemType& key) const;
	bool isItemAtEqual(int hashIndex, const elemType& rec) const;

private:
	elemType* HTable;		 //pointer to the hash table
	int* indexStatusList;	 //pointer to the array indicating the status of a position in the hash table
	int length;				 //number of items in the hash table
	int HTSize;              //maximum size of the hash table
};

#endif


template <class elemType>
hashT<elemType>::hashT(int size)
{
	// Write your code here
	if (size <= 0) size = 101;
	HTSize = size;
	length = 0;
	HTable = new elemType[HTSize];
	indexStatusList = new int[HTSize];

	for (int i = 0; i < HTSize; i++) {
		indexStatusList[i] = FALSE;
	}
}

template <class elemType>
int hashT<elemType>::hashFunction(const elemType& key) const     // get insert location
{
	ostringstream oss;
	oss << key;
	string key_str = oss.str();
	int sum = 0;

	for (int j = 0; j < key_str.size(); j++) {
		sum = sum + static_cast<int>(key_str.at(j));
	}

	return (sum % HTSize);
}

template <class elemType>
int hashT<elemType>::nextProbingPlace(int place_now, int probing_time) const
{
	int result = (place_now + 1) % HTSize;                          // For linear probing
	return result;
}

template <class elemType>
bool hashT<elemType>::isItemAtEqual(int hashIndex, const elemType& rec) const
{
	if (hashIndex < 0 || hashIndex >= HTSize || indexStatusList[hashIndex] != TRUE) {
		return false;
	}

	return HTable[hashIndex] == rec;
}

template <class elemType>
void hashT<elemType>::insert(const elemType& rec)
{
	int hashIndex = hashFunction(rec);

	// Complete the function
	int probed = 1;

	while (indexStatusList[hashIndex] == TRUE && HTable[hashIndex] != rec && probed < HTSize) {
		hashIndex = nextProbingPlace(hashIndex, probed);
		probed++;
	}
	if (indexStatusList[hashIndex] != TRUE) {
		HTable[hashIndex] = rec;
		indexStatusList[hashIndex] = TRUE;
		length++;
	}
	else if (HTable[hashIndex] == rec) {
		cerr << "Error: No duplicates are allowed." << endl;
	}
	else {
		cerr << "Error: The table is full. Unable to resolve the collision." << endl;
	}
}

template <class elemType>
int hashT<elemType>::search(const elemType& rec, bool& found) const
{
	int hashIndex = hashFunction(rec);

	// Complete the function
	int probed = 1;
	while (!isItemAtEqual(hashIndex, rec) && probed < HTSize && indexStatusList[hashIndex] != FALSE) {
		hashIndex = nextProbingPlace(hashIndex, probed);
		probed++;
	}

	if (isItemAtEqual(hashIndex, rec)) {
		found = true;
	}
	else {
		found = false;
	}

	return probed;
}

template <class elemType>
void hashT<elemType>::remove(const elemType& rec)
{
	int hashIndex = hashFunction(rec);

	// Complete the function
	int probed = 0;
	while (!isItemAtEqual(hashIndex, rec) && probed < HTSize && indexStatusList[hashIndex] != FALSE) {
		hashIndex = nextProbingPlace(hashIndex, probed);
		probed++;
	}
	if (isItemAtEqual(hashIndex, rec)) {
		indexStatusList[hashIndex] = DELETED;
		length--;
	}
}

template <class elemType>
string hashT<elemType>::print() const
{
	string result;
	for (int i = 0; i < HTSize; i++) {
		if (indexStatusList[i] == TRUE) {
			if (result != "") {
				result += " ";
			}
			stringstream ss;
			ss << HTable[i];
			string temp;
			ss >> temp;
			result += temp;
		}
	}

	std::cout << result << std::endl;
	return result;
}

template <class elemType>
hashT<elemType>::~hashT()
{
	delete[] HTable;
	delete[] indexStatusList;
}