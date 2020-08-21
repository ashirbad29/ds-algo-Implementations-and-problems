#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isSafe(int board[][10], int i, int j, int n){
	// check for the vertical col
	for(int row = 0; row < i; row++){
		if (board[row][j] == 1){
			// queen spooted
			return false;
		}
	}

	// check for left diagonal
	int x = i;
	int y = j;
	while (x >= 0 && y >= 0){
		if(board[x][y] == 1) return false;
		x--;
		y--;
	}

	// check for the right diagonal
	x = i;
	y = j;
	while (x >= 0 && y < n){
		if(board[x][y] == 1) return false;
		x--;
		y++;
	}

	// the postion is now safe
	return true;
}

bool solveNQueen(int board[][10], int i, int n) {
	// Base case
	if(n == i) {
		// you have successfully placed the queeen
		// print the board
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++) {
				if(board[i][j] == 1) cout << 'Q';
				else cout << '.';
			}
			cout << '\n';
		}
		return true;
	}

	// Recursive case
	// Try to place the queen in the current row and
	// call on the remaining part which can be solved by recursion

	for(int j = 0; i < n; j++){
		// I have to check if i,j pos is safe or not
		if(isSafe(board, i, j, n)){
			// place the queen assuming i, j is right pos
			board[i][j] == 1;

			if(solveNQueen(board, i+1, n)) return true;
			// if we cant place the queen in remaingn rows
			// it means our previous row postion is wrong
			// then we will backtrack
			board[i][j] = 0; // backtraking
		}
	}
	// you have tried for all position in curr row
	return false;
}

int main() {
	// n == no of queens to place 
	int n; cin >> n;

	// chess board
	int board[10][10] = {0};
	solveNQueen(board, 0, n);
	return 0;
}