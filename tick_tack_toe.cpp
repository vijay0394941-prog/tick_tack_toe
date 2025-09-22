#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<vector<char>>& board) {
	cout << "Current board:\n";
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cout << board[i][j];
			if (j < 2) cout << " | ";
		}
		cout << "\n";
		if (i < 2) cout << "--+---+--\n";
	}
}

bool checkWin(const vector<vector<char>>& board, char player) {
	// Check rows and columns
	for (int i = 0; i < 3; ++i) {
		if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
			(board[0][i] == player && board[1][i] == player && board[2][i] == player))
			return true;
	}
	// Check diagonals
	if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
		(board[0][2] == player && board[1][1] == player && board[2][0] == player))
		return true;
	return false;
}

bool checkDraw(const vector<vector<char>>& board) {
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (board[i][j] == ' ')
				return false;
	return true;
}

int main() {
	vector<vector<char>> board(3, vector<char>(3, ' '));
	char currentPlayer = 'X';
	int row, col;

	while (true) {
		printBoard(board);
		cout << "Player " << currentPlayer << ", enter row and column (0-based): ";
		cin >> row >> col;
		if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
			cout << "Invalid move. Try again.\n";
			continue;
		}
		board[row][col] = currentPlayer;
		if (checkWin(board, currentPlayer)) {
			printBoard(board);
			cout << "Player " << currentPlayer << " wins!\n";
			break;
		}
		if (checkDraw(board)) {
			printBoard(board);
			cout << "It's a draw!\n";
			break;
		}
		currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
	}
	return 0;
}
