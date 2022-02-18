#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Graph {
private:
	vector<vector<int>> matrix;
	int size;
	vector<bool> visited;

public:
	Graph(int mySize) {
		//Implement function
		if (mySize <= 2) size = 2;
		else size = mySize;
		
		for (int i = 0; i < size; i++) {
			vector<int> arr;
			for (int j = 0; j < size; j++)
				arr.push_back(0);
			matrix.push_back(arr);
			visited.push_back(false);
		}
	}

	void resetVisited() {
		//Implement function
		for (int i = 0; i < visited.size(); i++)
			visited.at(i) = false;
	}

	void insertEdge(int v1, int v2, int weight) {
		//Implement function
		if (v1 >= 0 && v2 >= 0 && v1 < size && v2 < size) {
			matrix.at(v1).at(v2) = weight;
			matrix.at(v2).at(v1) = weight;
		}
	}

	void DFS(int vertex) {
		//Implement function
		vector<int> vec;
		vec.push_back(vertex);
		while (!vec.empty())
		{
			int current = vec.back();
			vec.pop_back();
			if (!visited.at(current)) {
				visited.at(current) = true;
				for (int i = 0; i < size; i++) {
					if (matrix.at(current).at(i) != 0)
						vec.push_back(i);
				}
			}
		}
	}

	bool edgeCheck() {
		//Implement function
		bool ch = true;
		for (int i = 0; i < size; i++) {
			if (!visited.at(i))
				ch = false;
		}
		return ch;
	}

	int MST() {
		//Implement function
		int numEdge = 0;
		int sumEdges = 0;
		visited.at(0) = true;
		while (numEdge < size - 1) {
			int min = 10000000;
			int x = 0;
			int y = 0;
			for (int i = 0; i < size; i++) {
				if (visited.at(i)) {
					for (int j = 0; j < size; j++) {
						if (!visited.at(j) && (matrix.at(i).at(j) > 0)) {
							if (min > matrix.at(i).at(j)) {
								min = matrix.at(i).at(j);
								x = i;
								y = j;
							}
						}
					}
				}
			}
			visited.at(y) = true;
			numEdge++;
			sumEdges += min;
		}

		return sumEdges;
	}
};