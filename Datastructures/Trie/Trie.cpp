#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
	char data;
	unordered_map<char, Node*> children;
	bool is_leaf;

	Node(char c){
		data = c;
		is_leaf = false;
	}
};

class Trie{
	Node* root;
	int count;
	Trie() {
		root = new Node('\0');
		count = 0;
	}

	void insert(char *word){
		Node* temp = root;

		for(int i = 0; word[i] != '\0'; i++){
			char ch = w[i];
			if(temp->children.count(ch))
				temp = temp->children[ch];

			else {
				Node* n = new Node(ch);
				temp->children[ch] = n;
				temp = n;
			}
		}
		temp->is_leaf = true;
	}

	bool search(char *word){
		Node* temp = root;
		for (int i = 0; word[i] != '\0'; i++){
			char ch = word[i];
			if(!temp->children.count(ch)){
				return false;
			}
			else {
				temp = temp->children[ch];
			}
		}
		return temp->is_leaf;
	}
}

int main() {

	return 0;
}