#include <iostream>
#include "Graph.h"

using namespace std;

int main(int argc, char* argv[]) {
	//Implement main function
	int numTeams;
	int invTeams = 0;
	int moved = 0;

	cin >> numTeams;
	for (int i = 0; i < numTeams; i++) {
		int numEmp;
		int vPrime=0;
		int v1;
		int v2;
		int weight;
		cin >> numEmp;
		Graph gr = Graph(numEmp);

		cin >> v1 >> v2 >> weight;
		gr.insertEdge(v1, v2, weight);
		vPrime = v1;
		while (!(v1 == -1 && v2 == -1 && weight == -1))
		{
			gr.insertEdge(v1, v2, weight);
			cin >> v1 >> v2 >> weight;
		}

		gr.DFS(0);
		if (!gr.edgeCheck()) {
			cout << "No path is formed from each location to every other" << endl << endl;
			invTeams++;
			gr.resetVisited();
		}
		else {
			gr.resetVisited();
			int oMST = gr.MST();
			int nMST;
			cout << "A path is formed!" << endl;
			cout << "Original MST was: " << oMST << endl;
			cin >> v1 >> v2 >> weight;
			gr.insertEdge(v1, v2, weight);
			gr.resetVisited();
			nMST = gr.MST();
			cout << "New MST is: " << nMST << endl;
			if (oMST > nMST) {
				cout << "Employee’s office should be moved" << endl;
				moved++;
			}
			else cout << "Employee's office should NOT be moved" << endl;
			cout << endl;
		}
	}
	cout << "Number of employees' offices with invalid paths: " << invTeams << "/" << numTeams << endl;
	cout << "Number of employees who would benefit from moving offices: " << moved << "/" << numTeams << endl;

	return 0;
}