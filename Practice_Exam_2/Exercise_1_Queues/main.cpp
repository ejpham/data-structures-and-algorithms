#include <iostream>
#include <string>
#include <sstream>
#include "queue.h"

using namespace std;

int main() {
    queue<int> queue1(100);
    queue<int> queue2(100);
    int temp;

    //This portion of code stores the input in queue1
    string input;
    getline(cin, input);
    stringstream ss(input);
    while (ss >> temp)
        queue1.enqueue(temp);

    //DO NOT MODIFY CODE ABOVE

    //Write your solution here
    while (!queue1.is_empty()) {
        if (queue2.is_empty() || queue2.back() < queue1.front()) {
            queue2.enqueue(queue1.front());
            queue1.dequeue();
        }
        else {
            while (queue2.front() < queue1.front()) {
                queue2.enqueue(queue2.front());
                queue2.dequeue();
            }
            queue2.enqueue(queue1.front());
            queue1.dequeue();
            while (queue2.front() > queue2.back()) {
                queue2.enqueue(queue2.front());
                queue2.dequeue();
            }
        }
    }

    //DO NOT MODIFY CODE BELOW

    //This segment prints the content of queue2
    while (!queue2.is_empty())
    {
        cout << queue2.front() << " ";
        queue2.dequeue();
    }
    return 0;
}