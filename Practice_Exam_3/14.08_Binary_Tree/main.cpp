#include <iostream>
#include "binaryTree.h"

using namespace std;

int main() {
    //use this code for test case or change for your own testing
    binaryTree test;

    test.insert(10);
    test.insert(12);
    test.insert(3);
    test.insert(4);

    //test.preorderTraversal();
    int sum = test.getSumOfAllNodesOnSameLevel(1);
    cout << " Sum for level 1 is " << sum << endl;
    return 0;
}