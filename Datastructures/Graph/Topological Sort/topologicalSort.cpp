#include <iostream>
#include <list>
#include <map>
#include <stack>
using namespace std;

class Graph {
	int v;
	map<int, list<int>> adj;
public:
	Graph(int v) {
		this->v = v;
	}

	void addEdge(int v, int w) {
		adj[v].push_back(w);
	}

	void topologicalSortUtil(int node, stack<int> &stack, map<int, bool> &visited) {

		// mark the current node as visited
		visited[node] = true;

		// visit all its neighbours
 		for(auto ngbr: adj[node]) {
			if (!visited[ngbr])
				topologicalSortUtil(ngbr, stack, visited);
		}

		// push current vertex to stack
		stack.push(node);	
	}

	void topologicalSort() {
		map<int, bool> visited;		
		stack<int> stack;

		// mark all as not visited
		for(auto v: adj) {
			visited[v.first] = false;
		}

		// call the recursive function for all the node in adjancency list
		for(auto v: adj) 
			if(!visited[v.first])
				topologicalSortUtil(v.first, stack, visited);


		// print the stack to get the topological sort order
		while(!stack.empty()) {
			cout << stack.top() << " ";
			stack.pop();
		}
		cout << endl;
	}
};

int main() {
	Graph g(5); 
    g.addEdge(1, 2); 
    g.addEdge(1, 3); 
    g.addEdge(2, 3); 
    g.addEdge(2, 4); 
    g.addEdge(3, 4); 
    g.addEdge(3, 5);

    g.topologicalSort();
	return 0;
}