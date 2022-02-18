#ifndef STACK_H
#define STACK_H

template<class T>
class Stack
{
private:
	T* list;
	int maxStackSize;
	int stackTop;

public:
	Stack(int n = 100);
	void push(const T& input);
	void pop();
	T& top() const;
	bool isEmpty() const;
	~Stack();
};

#endif


template <class T>
Stack<T>::Stack(int n)
{
	maxStackSize = n;

	if (maxStackSize < 0)
		maxStackSize = 100;

	list = new T[maxStackSize];
	stackTop = 0;
}

template <class T>
void Stack<T>::push(const T& input)
{
	if (stackTop == maxStackSize)
		std::cout << "Can not push in a full stack." << std::endl;
	else
		list[stackTop++] = input;
}

template <class T>
void Stack<T>::pop()
{
	if (stackTop == 0)
		std::cout << "Can not pop from an empty stack." << std::endl;
	else
		stackTop--;
}


template <class T>
bool Stack<T>::isEmpty() const
{
	return stackTop == 0;
}

template <class T>
T& Stack<T>::top() const
{
	return list[stackTop - 1];
}

template <class T>
Stack<T>::~Stack()
{
	delete[] list;
}