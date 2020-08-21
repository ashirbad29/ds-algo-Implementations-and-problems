#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <list>
#include <limits.h>
using namespace std;

class Graph{
	int v;
	map<int, list<pair<int, int> > > adj;
	// vertex : (neighbour 1, weight) , (neighbour 2, weight)... So on 
public:
	Graph(int v) {
		this->v = v;
	}
	void addEdge(int x, int y, int weight, bool biDir = false ) {
		adj[x].push_back(make_pair(y, weight));
		if (biDir) adj[y].push_back(make_pair(x, weight));
	}

	void printGraph() {
		for (auto x: adj) {
			cout << x.first << " : ";
			for (auto y: x.second) {
				cout << "( " << y.first << " w-" << y.second << " )"<< " ";
			}
			cout << '\n';
		}
	}

	vector<int> dijikstra(int src) {
		// need a array to store shortest path, initialize it by infinity
		vector<int> dist(v, INT_MAX);

		// need a set ds to store and acces weight and vertex pair
		set<pair<int, int>> setDS; // weight, vertex

		// set the distance of source to 0
		dist[src] = 0;
		setDS.insert(make_pair(0, src)); 

		while (!setDS.empty()) {
			// get the first element of set bcoz it is having lowest distance right now
			auto vertexAtBeginOfSet = *(setDS.begin()); // returns the first element

			// now erase the element as we visited this element and its neighbours
			setDS.erase(setDS.begin());

			// get the value of vetex from the setDS
			int vertexVal = vertexAtBeginOfSet.second;

			// visit all the neighbours of this node
			for (auto x: adj[vertexVal]){
				int v = x.first;
				int weight = x.second;

				 if(dist[v] > dist[vertexVal] + weight) {
				 	// remove the previous shortest value for the vertex if exists!!
				 	if (dist[v] != INT_MAX)
				 		setDS.erase(setDS.find(make_pair(dist[v], v)));

				 	// update the new distance
				 	dist[v] = dist[vertexVal] + weight;

				 	// insert the new updated pair to set
				 	setDS.insert(make_pair(dist[v], v));
				 }
			}
		}
		// return the array of shortest path to all nodes from a source node
		return dist;
	}

};

int main() {
	Graph g(5);

	g.addEdge(0, 1, 4, true);
	g.addEdge(0, 2, 8, true);
	g.addEdge(1, 3, 5, true);
	g.addEdge(1, 2, 2, true);
	g.addEdge(2, 3, 5, true);
	g.addEdge(2, 4, 9, true);
	g.addEdge(4, 3, 4, true);

	g.printGraph();
	cout << '\n';

	vector<int> shortestDistArray = g.dijikstra(0);
	for (auto x: shortestDistArray) {
		cout << x << " ";
	}
	cout << '\n';
	return 0;
}