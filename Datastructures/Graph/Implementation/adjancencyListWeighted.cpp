#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
using namespace std;

// Map bashed implementation
class Graph {
	// adjacency list
	unordered_map<string, list<pair<string, int> > > l;
public:
	void addEdge(string x, string y, bool bidir, int weight) {
		l[x].push_back(make_pair(y, weight));
		if (bidir) l[y].push_back(make_pair(x, weight));
	}

	void printGraph() {
		for (auto x: l) {
			cout << x.first << "-->";

			for (auto y: x.second) {
				cout << y.first << " " << y.second << "   ";
			}
			cout << "\n";
		}
	}
};


int main() {
	Graph g;
	g.addEdge("A", "B", true, 20);
	g.addEdge("B", "D", true, 40);
	g.addEdge("A", "C", true, 10);
	g.addEdge("C", "D", true, 30);
	g.addEdge("A", "D", false, 50);

	g.printGraph();
	cout << endl;
	return 0;
}