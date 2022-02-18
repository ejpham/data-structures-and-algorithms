#include <iostream>
#include <string>
#include <sstream>
#include "stack.h"

using namespace std;

int main() {
    Stack<int> stack1(100);
    Stack<int> stack2(100);
    int temp;

    //This portion of code stores the input in stack1
    string input;
    getline(cin, input);
    stringstream ss(input);
    while (ss >> temp)
        stack1.push(temp);

    //DO NOT MODIFY CODE ABOVE

    //Write your solution here
    while (!stack1.isEmpty()) {
        if (stack2.isEmpty() || stack1.top() <= stack2.top()) {
            stack2.push(stack1.top());
            stack1.pop();
            continue;
        }
        else if (stack1.top() >= stack2.top()) {
            temp = stack1.top();
            stack1.pop();
            stack1.push(stack2.top());
            stack2.pop();
            stack1.push(temp);
        }
    }

    //DO NOT MODIFY CODE BELOW

    //This segment prints the content of stack2
    while (!stack2.isEmpty())
    {
        cout << stack2.top() << " ";
        stack2.pop();
    }
    return 0;
}