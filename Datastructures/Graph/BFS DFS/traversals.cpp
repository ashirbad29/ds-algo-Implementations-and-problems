#include <iostream>
#include <map>
#include <queue>
#include <list>

using namespace std;

// Implementation of both bfs and dfs
class Graph {
	// adjacency List
	map <int, list<int>> l;
public:
	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void BFS(int src) {
		map<int, bool> visited;
		queue<int> q;

		q.push(src);

		// mark the source node as visited
		visited[src] = true;

		while (!q.empty()) {
			int node = q.front();
			q.pop();
			cout << node << " ";
			// find the neighbours of the node
			// push them to the queue and mark them visited
			for (auto nbr: l[node]) {
				if (!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
	}

	//Recursive function that will traverse the graph
	void dfs_helper(int src, map<int, bool> &visited) {
		cout << src << " ";
		visited[src] = true;

		// go to all neighbour of that node that is not visited one by one
		for (auto nbr: l[src]) {
			if (!visited[nbr]) {
				dfs_helper(nbr, visited);
			}
		}
	}

	void DFS(int src) {
		map<int, bool> visited;
		// mark all the nodes as not visited;
		for (auto x: l) {
			auto node = x.first;
			visited[node] = false;
		}
		// call the helper function
		dfs_helper(src, visited);
	}
};

int main() {
	Graph g;
	g.addEdge(2, 1);
	g.addEdge(2, 3);
	g.addEdge(0, 3);
	g.addEdge(0, 1);
	g.addEdge(4, 3);
	g.addEdge(4, 5);

	g.BFS(5);
	cout << endl;
	g.DFS(0);
	cout << endl;
	return 0;
}