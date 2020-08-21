#include <iostream>
#include <list>
#include <limits.h>
using namespace std;

class Graph{
	int v;
	list<int> *adj;
public:
	Graph(int v) {
		this->v = v;
		// dynamic arra of type list<int> with size of v
		adj = new list<int>[v];
	}
	void addEdge(int x, int y) {
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	// Cycle detection using DFS
	bool cycle_helper(int node, bool visited[], int parent) {
		// mark the current nod as visited
		visited[node] = true;
	
		list<int>::iterator i; 
		for (i = adj[node].begin(); i != adj[node].end(); ++i) {
			// two cases
			if (!visited[*i]) {

				// go and recursivly visit the neighbour of the nod		
				if (cycle_helper(*i, visited, node))
					return true;
			}
			// the neighbour shoud't be a parent
			else if (*i != parent)
				return true;
		}
		return false;
	}

	bool contains_cycle() {
		// checking for cycle in a directed graph
		bool *visited = new bool[v];
		for (int i = 0; i < v; i++) {
			visited[i] = false;
		}

		for (int u = 0; u < v; u++)
			if (!visited[u])
				if (cycle_helper(u, visited, -1))
					return true;

		return false;
	}
};

int main() {
	Graph g(3);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	// g.addEdge(2, 1);
	// g.addEdge(0, 3);
	// g.addEdge(3, 4);

	g.contains_cycle()? cout << "true" << endl : 
						cout << "false" << endl;
	return 0;
}