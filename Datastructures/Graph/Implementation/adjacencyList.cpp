#include <iostream>
#include <list>

using namespace std;

class Graph{
	int vertices;
	list<int> *adj_list;

public:
	Graph(int vertices) {
		this->vertices = vertices;
		adj_list = new list<int>[vertices];
	}
	// assuming bidirected by default
	void addEdge(int u, int v) {
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	void printGraph() {
		for (int i = 0; i < vertices; i++) {
			cout << i << "--->";
			for (auto x: adj_list[i]) {
				cout << x << " ";
			}
			cout << endl;
		}
	}
};

int main() {
	Graph g(6);
	g.addEdge(0, 4);
	g.addEdge(0, 3);
	g.addEdge(1, 2);
	g.addEdge(1, 4);
	g.addEdge(1, 5);
	g.addEdge(2, 3);
	g.addEdge(2, 5);
	g.addEdge(5, 4);
	g.addEdge(5, 3);

	g.printGraph();
	cout << endl;
	return 0;
}