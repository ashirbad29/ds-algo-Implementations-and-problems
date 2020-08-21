#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

void insert(stack<int>& s, int item){
	if(s.empty()){
		s.push(item);
		return;
	}

	int val = s.top();
	s.pop();
	insert(s, item);
	s.push(val);
	return;
}

void reverseStack(stack<int>& s){
	if(s.size() == 1) return;
	int val = s.top();
	s.pop();
	reverseStack(s);
	insert(s, val);
	return;
}

void printStack(stack<int> s){
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
}

int main() {
	stack<int> s;
	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);
	s.push(0);

	cout << s.top() << endl;
	reverseStack(s);
	cout << s.top() << endl;

	printStack(s);
	return 0;
}