#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
using namespace std;

// using disjoint sets to find cycles in a graph

class disjointSet {
	int *rank, *parent, n;

public:
	// constructor to creat and initialize sets of n items
	disjointSet(int n) {
		rank = new int[n];
		parent = new int[n];
		this->n = n;
		makeSet();
	}

	void makeSet()
	{
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	int find(int x) {
		// returns the parent of a element
		if(parent[x] != x) {
			// if x is not his parnet itself
			// recursively search for his parent
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	void Union(int x, int y)
	{
		// find the current sets of x any y
		int xset = find(x);
		int yset = find(y);

		if (xset == yset) return;

		if (rank[xset] < rank[yset]) {
			parent[xset] = yset;
		}
		else if (rank[xset] > rank[yset]) {
			parent[yset] = xset;
		}
		else {
			parent[yset] = xset;
			rank[xset] = rank[xset] + 1;
		}
	}

	bool isAtSameSet(int x, int y){
		// find the current sets of x any y
		int xset = find(x);
		int yset = find(y);

		// if they are already in same set
		if (xset == yset) return true;
		return false;
	}
};

struct Edge {
	int weight;
	int src;
	int dest;
};

bool edgeComp(Edge a, Edge b) {
	return a.weight > b.weight;
}

class Graph {
	int v;
	map<int, list<pair<int, int>>> adj; // node , nbr, weight
public:
	Graph(int v) {
		this->v = v;
	}

	void addEdge(int x, int y) {
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	// uses disjoint set find if cyclic or not
	// bool isCyclic() {
	// 	disjointSet disSet(v);
	// 	for (auto x: adj) {
	// 		for (auto nbr: x.second) {
	// 			if(disSet.isAtSameSet(x.first, nbr)) return true;
	// 			else disSet.Union(x.first, nbr);
	// 		}
	// 	}
	// 	return false;
	// }

	void kruskalMST() {
		// store all the edges in a sorted order
		vector<Edge> edges;
		for (auto x: adj)
			for (auto nbr: x.second)
				edges.push_back({nbr.second, x.first, nbr.first});

		// sort the edges array
		sort(edges.begin(), edges.end(), edgeComp)

		// add the edges to to form MST
		disjointSet disSet(v);

		vector<int> mstWeight;

		while(mstWeight.size() == (v-1)) {
			
		}
	}
};

int main() {
	Graph g(7);
	g.addEdge(1, 2);
	g.addEdge(1, 6);
	g.addEdge(2, 3);
	g.addEdge(2, 4);
	g.addEdge(6, 4);
	g.addEdge(6, 5);
  	
  	g.isCyclic()? cout << "YES\n": cout << "NO\n";
	return 0;
}