#include <iostream>
#include "stack.h"

using namespace std;

void printBinary(int n) {
	Stack<int> binary;

	//complete function
	while (n > 0) {
		binary.push(n % 2);
		n /= 2;
	}

	while (!binary.isEmpty()) {
		cout << binary.top();
		binary.pop();
	}
}

int main() {
	int test;

	cin >> test;

	printBinary(test);
	return 0;
}