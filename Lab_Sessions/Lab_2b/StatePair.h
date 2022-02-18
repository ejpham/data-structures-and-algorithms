#ifndef STATEPAIR
#define STATEPAIR

#include <iostream>

template<typename T1, typename T2>
class StatePair {
private:
	T1 key;
	T2 value;
public:
	StatePair();
	StatePair(T1 userKey, T2 userValue);
	void SetKey(T1 newKey);
	void SetValue(T2 newVal);
	T1 GetKey();
	T2 GetValue();
	void PrintInfo();
};

// TODO: Define a constructor, mutators, and accessors for StatePair
template<typename T1, typename T2>
StatePair<T1, T2>::StatePair(){}

template<typename T1, typename T2>
StatePair<T1, T2>::StatePair(T1 userKey, T2 userValue) {
	key = userKey;
	value = userValue;
}

template<typename T1, typename T2>
void StatePair<T1, T2>::SetKey(T1 newKey) {
	key = newKey;
}

template<typename T1, typename T2>
void StatePair<T1, T2>::SetValue(T2 newVal) {
	value = newVal;
}

template<typename T1, typename T2>
T1 StatePair<T1, T2>::GetKey() {
	return key;
}

template<typename T1, typename T2>
T2 StatePair<T1, T2>::GetValue() {
	return value;
}

// TODO: Define PrintInfo() method
template<typename T1, typename T2>
void StatePair<T1, T2>::PrintInfo() {
	std::cout << key << ": " << value << std::endl;
}

#endif