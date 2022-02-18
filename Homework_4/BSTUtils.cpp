#include <fstream>
#include <string>
#include <algorithm>
#include "BSTUtils.h"

string* file_to_array(string f_name, int *l)
{
	//implement function
	ifstream input;

	string temp;
	*l = 0;
	input.open(f_name);
	while (input >> temp)
		(*l)++;
	input.clear();
	input.seekg(ios::beg);
	string* arr = new string[*l];
	for (int i = 0; i < *l; i++)
		input >> arr[i];
	input.close();
	
	return arr;
}

void array_to_bst(string key_arr[], int len, BSTree* i_bst)
{
	//implement function
	for (int i = 0; i < len; i++)
		i_bst->addNode(key_arr[i]);
}

void recur(string* in_arr, int left, int right, string* final_arr, int& i) {
   if (left > right)
      return;
	int mid = left + (right - left) / 2;
	final_arr[i++] = in_arr[mid];
	recur(in_arr, left, mid - 1, final_arr, i);
	recur(in_arr, mid + 1, right, final_arr, i);
}

string* presort_array(string in_arr[], int len)
{
	//implement function
	sort(in_arr, in_arr + len);
	
	string* final_arr = new string[len];
	
	int i = 0;
	recur(in_arr, 0, len - 1, final_arr, i);
	
	return final_arr;
}