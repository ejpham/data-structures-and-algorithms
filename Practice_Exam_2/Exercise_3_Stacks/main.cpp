#include <iostream>
#include <string>
//#include <sstream>
#include "Stack.h"

using namespace std;

string reverseString(string input)
{
	// implement the funciton.
	Stack<string> stack;
	string reverse = "";

	int index = input.find(' ');

	while (index != -1) {
		stack.push(input.substr(0, index));
		input = input.substr(index + 1, string::npos);
		index = input.find(' ');
	}

	stack.push(input.substr(0, string::npos));

	while (!stack.isEmpty()) {
		if (!reverse.empty()) reverse += ' ';
		reverse += stack.top();
		stack.pop();
	}

	return reverse;

	/*istringstream iss(input);
	do {
		string word;
		iss >> word;
		stack.push(word);
	} while (iss);

	while (!stack.isEmpty()) {
		reverse += stack.top();
		stack.pop();
		if (!stack.isEmpty() && !reverse.empty()) reverse += " ";
	}*/
}

int main()
{
	std::string input;

	getline(cin, input);
	std::string output = reverseString(input);
	std::cout << output << std::endl;

	return 0;
}