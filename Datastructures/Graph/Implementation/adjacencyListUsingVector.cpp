#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Graph {
	int _vertices;
	vector<vector<bool>> *matrix;

public:
	Graph(int vertices) {
		_vertices = vertices;
		matrix = &vector<vector<bool>>(_vertices);
		for (int i = 0; i < vertices; i++) 
			for (int j = 0; j < vertices; j++) 
				matrix[i][j] = false;
	}

	// add edges
	void addEdge(int i, int j) {
		matrix[i][j] = true;
		matrix[j][i] = true;
	}

	void removeEdge(int i, int j) {
		matrix[i][j] = false;
		matrix[j][i] = false;
	}

	void printMatrix() {
		cout << "printing" << endl;
		for (int i = 0; i < _vertices; i++) {
			for (int j = 0; j < _vertices; j++)
				cout << matrix[i][j] << " ";
			cout << "\n";
		}
	}
};

int main() {
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.printMatrix();
	cout << endl;
	return 0;
}