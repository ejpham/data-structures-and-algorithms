#ifndef QUEUE_TYPE_H
#define QUEUE_TYPE_H

#include <iostream>
#include <cassert>
#include "queueADT.h"

using namespace std;

template <class Type>
class queueType : public queueADT<Type>
{
public:
	queueType(int queueSize = 100) {
   // implement constructor
		maxQueueSize = queueSize;
		initializeQueue();
	}

	~queueType() {
	// implement destructor
		delete[] list;
	}

	bool isEmptyQueue() const {
		return (count == 0);
	}

	bool isFullQueue() const {
		return (count == maxQueueSize);
	}
	
   int getSize() const {
      return count;
   }

   int getMaxCapacity() const {
      return maxQueueSize;
   }

	void initializeQueue() {
   // implement function
		list = new Type[maxQueueSize];
		queueFront = 0;
		queueRear = -1;
		count = 0;
	}

	Type front() const {
		assert(!isEmptyQueue());
		return list[queueFront];
	}

	Type back() const {
		assert(!isEmptyQueue());
		return list[queueRear];
	}

	void enQueue(const Type& queueElement) {
   // implement function
		if (isFullQueue()) cout << "Can not add to a full queue\n";
		else {
			queueRear = (queueRear + 1) % maxQueueSize;
			list[queueRear] = queueElement;
			count++;
			cout << "New client added. Queue now has " << count << " clients.\n";
		}
	}

	void deQueue() {
	// implement function
		if (isEmptyQueue()) cout << "Cannot remove from an empty queue\n";
		else {
			queueFront = (queueFront + 1) % maxQueueSize;
			count--;
			cout << "Client removed from queue. Queue now has " << count << " clients.\n";
		}
	}

private:
	int maxQueueSize; //variable to store the maximum queue size
	int count; //variable to store the number of
	int queueFront; //variable to point to the first
	int queueRear; //variable to point to the last
	Type* list; //pointer to the array that holds
};

#endif // !QUEUE_TYPE_H