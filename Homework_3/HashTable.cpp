#include "HashTable.h"
#include <iostream>

HashTable::HashTable() {
	bucketArray = new HashBucket[10];
	maxBuckets = 10;
}

HashTable::~HashTable() {
	//free memory related to the table
	for (int i = 0; i < maxBuckets; i++)
		delete bucketArray[i].head;
}

int HashTable::hashFunc(string password) {
	int hashval = 0;
	for (unsigned int i = 0; i < password.size(); i++) {
		hashval = hashval + ((char)password[i]);
	}
	hashval = hashval % 10;
	return hashval;
}

int HashTable::numElementsInBucket(int bucketIndex) {
	//return number of passwords in specified bucket of hash table
	int count = 0;
	BucketNode* temp = bucketArray[bucketIndex].head;

	while (temp != nullptr) {
		count++;
		temp = temp->next;
	}

	return count;
}

void HashTable::addElement(string password, bool actualPassword) {
	//add password to correct bucket in hash table; also, indicate if password was from the actualPassword.txt file or attemptedPassword.txt file
	int bucketIndex = hashFunc(password);

	BucketNode* toAdd = new BucketNode;
	toAdd->password = password;
	toAdd->actualPassword = actualPassword;

	if (toAdd->actualPassword == true) {
		bucketArray[bucketIndex].head = toAdd;
	}
	else {
		if (bucketArray[bucketIndex].head == nullptr)
			bucketArray[bucketIndex].head = toAdd;
		else {
			BucketNode* temp = bucketArray[bucketIndex].head;
			while (temp->next != nullptr)
				temp = temp->next;
			temp->next = toAdd;
			toAdd->prev = temp;
		}
	}
}

void HashTable::removeElements() {
	//print all nodes in buckets consisting of only one element, then delete that element
	for (int i = 0; i < maxBuckets; i++) {
		if (numElementsInBucket(i) == 1) {
			cout << bucketArray[i].head->password << " deleted" << endl;
			bucketArray[i].head = nullptr;
		}
	}
}

void HashTable::printCollisions() {
	//print all compromised passwords
	for (int i = 0; i < maxBuckets; i++) {
		if (numElementsInBucket(i) > 1 && bucketArray[i].head->actualPassword == true)
			cout << bucketArray[i].head->password << ": " << numElementsInBucket(i) - 1 << " collisions" << endl;
	}
}