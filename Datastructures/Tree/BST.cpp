//Full implementation of binary tree

#include<bits/stdc++.h>
using namespace std;

struct Node{
public:
	Node(int x): data(x), left(NULL), right(NULL) {}
	int data;
	Node* left;
	Node* right;
};

class BST{
private:
	Node* root;
	//basic operations
	void insert(Node* root, int x);
	//Traversal
	void preorder(Node* root);
	void inorder(Node* root);
	void postorder(Node* root);
	Node* Min(Node* root);
	Node* deleteNode(Node* root, int key);
	bool search(Node* root, int data);
	bool iterativeSearch(Node* root, int value);
	bool validate(Node* root, int max, int min);
	Node* findSuccessor(Node* root, int val);
	Node* findPredecessor(Node* root, int val);
public:
	BST();
	void insert(int x) { insert(root, x);}
	void preorder() { preorder(root);}
	void inorder() { inorder(root);}
	void postorder() { postorder(root);}
	int Min() {
		Node* temp = Min(root);
		return temp->data; 
	}
	void deleteNode(int key) {
		root = deleteNode(root, key);
	}
	bool search(int value){
		bool result = search(root, value);
		return result;
	}
	bool iterativeSearch(int value) {
		return iterativeSearch(root, value);
	}

	bool isBST() {
		return validate(root, NULL, NULL);
	}

	int findSuccessor(int val) {
		Node* result = findSuccessor(root, val);
		return result->data;
	}
	int findPredecessor(int val) {
		Node* result = findPredecessor(root, val);
		return result->data;
	}

};

BST::BST() {
	root = NULL;
}

void BST::insert(Node* rootNode, int x) {
	if(!root) {
		rootNode = new Node(x);
		root = rootNode;
		return;
	}
	if(x < rootNode->data) {
		if(!rootNode->left) {
			Node* treeTemp = new Node(x);
			rootNode->left = treeTemp;
		}
		else insert(rootNode->left, x);
	}
	else 
	{
		if(!rootNode->right) {
			Node* treeTemp = new Node(x);
			rootNode->right = treeTemp;
		}
		else insert(rootNode->right, x);
	}
}

Node* BST::deleteNode(Node* root, int data) {
	if(root == NULL) return root;
    else if(data < root->data) root->left = deleteNode(root->left, data);
    else if(data > root->data) root->right = deleteNode(root->right, data);
    else //element found
    {
        //Case 1: No Child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
            return root;
        }
        //case 2: one child
        else if(root->left == NULL){
            Node* temp = root;
            root = root->right;
            delete temp;
        }
         else if(root->right == NULL){
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        //case 3 2 children
        else{
            Node* temp = Min(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

Node* BST::Min(Node* root) {
	if(root->left == NULL) return root;
	return Min(root->left);
}

void BST::preorder(Node* root) {
	if(!root) return;

	cout << root->data << " ";
	BST::preorder(root->left);
	BST::preorder(root->right);
}

void BST::inorder(Node* root) {
	if(!root) return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void BST::postorder(Node* root) {
	if(!root) return;

	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

bool BST::search(Node* root, int value) {
	if(root == NULL) return false;
	if(root->data == value) return true;
	if(root->data <= value) return search(root->right, value);
	if(root->data >= value) return search(root->left, value);
	return false;
}

bool BST::iterativeSearch(Node* root, int value) {
	//traverse until the end
	while(root != NULL) {
		if(value > root->data) root = root->right;
		else if(value < root->data) root = root->left;
		else return true; //value is found
	}
	return false;
}

bool BST::validate(Node* root, int max, int min) {
	if(root == NULL) return true;
	else if(min != NULL && root->data >= max || max != NULL && root->data <= min) return false;
	else
		return validate(root->left, root->data, min) && validate(root->right, max, root->data);
}

//Successor
//utility function to find the required element
Node* find(Node* root, int val) {
	if(root == NULL) return NULL;
	if(root->data == val) return root;
	if(val > root->data) return find(root->right, val);
	if(val < root->data) return find(root->left, val);
	return NULL;
}
Node* BST::findSuccessor(Node* root, int val) {
	//search the node in the tree
	Node* current = find(root, val);
	if(current == NULL) return NULL;

	//case 1: if the node has right subtree then the min value is the successor
	if(current->right != NULL) {
		Node* temp = current->right;
		while(temp->left != NULL) temp = temp->left;
		return temp;
		//another approach
		//just return min(current->right);
	}
	//Case 2: if the node has no right subtree
	//we have to find the ancestor in which current is on the left
	Node* ancestor = root; //will start checking from the root itself
	Node* successor = NULL;
	while(ancestor != current) {
		//valdate if the current is in the left of the ancestor
		if(ancestor->data > current->data) {
			successor = ancestor;
			ancestor = ancestor->left;
		}
		else {
			ancestor = ancestor->right;
		}
	}
	return successor;
}

Node* getMax(Node* root) {
	while(root->right) root = root->right;
	return root;
}
//Finding Predecessor
Node* BST::findPredecessor(Node* root, int val) {
	Node* current = find(root, val);
	if(current == NULL) return NULL;
	if(current->left) {
		return getMax(current->left);
	}

	Node* Predecessor = NULL;
	while(root != current) {
		if(val < root->data) root = root->left;
		if(val > root->data) {
			Predecessor = root;
			root = root->right;
		}
	}
	return Predecessor;
}

int main() {
	BST tree;
	tree.insert(8);
	tree.insert(6);
	tree.insert(12);
	tree.insert(10);
	tree.insert(7);
	tree.insert(3);
	tree.preorder();
	cout << endl;
	tree.deleteNode(10);
	tree.inorder();
	cout << endl;
	tree.postorder();
	cout << endl;
	cout << tree.Min() << endl;
	cout << tree.search(13) << endl;
	cout << tree.iterativeSearch(13) << endl;
	cout << tree.findSuccessor(6) << endl;
	cout << tree.findPredecessor(7) << endl;
	return 0;
}