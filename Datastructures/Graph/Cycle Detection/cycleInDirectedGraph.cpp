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
	}

	// Cycle detection using DFS
	bool cycle_helper(int node, bool visited[], bool *recStack) {
		if (!visited[node]) {
			// mark the node as visited
			visited[node] = true;
			recStack[node] = true;

			// for all its adjacent nodes
			for (auto x: adj[node]) {
				if (!visited[x] && cycle_helper(x, visited, recStack)) 
					return true;
				else if (recStack[x]) // if the node present in the current recStack then its a cycle
					return true;
			}
		}

		// marking the current node as false in recStack for next iteration
		recStack[node] = false;
		return false;
		
	}

	bool contains_cycle() {
		// checking for cycle in a directed graph
		bool *visited = new bool[v];
		bool *recStack = new bool[v];

		// mark down all elemeents as false
		for (int i = 0; i < v; i++) {
			visited[i] = false;
			recStack[i] = false;
		}

		// call for every vertex
		for (int i = 0; i < v; i++) {
			if (cycle_helper(i, visited, recStack)) 
				return true;
		}
		return false;
	}
};

int main() {
	Graph g(8);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(4, 1);
	g.addEdge(4, 5);
	g.addEdge(5, 6);
	g.addEdge(6, 4);
	g.addEdge(7, 1);
	g.addEdge(7, 4);

	g.contains_cycle()? cout << "Graph Contains a Cycle" << endl : 
						cout << "Graph dont have any cycle" << endl;
	return 0;
}