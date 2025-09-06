#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &board, int row, int col, int n) {
    // check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) return false;
    }

    // check upper-left diagonal
    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }

    // check upper-right diagonal
    for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) return false;
    }

    return true;
}

bool solveNQueens(vector<vector<int>> &board, int row, int n) {
    if (row == n) { // all queens placed
        // print solution
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << (board[i][j] ? "Q " : ". ");
            }
            cout << "\n";
        }
        cout << "\n";
        return true; // for one solution
    }

    bool found = false;
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1; // place queen
            found = solveNQueens(board, row+1, n) || found;
            board[row][col] = 0; // backtrack
        }
    }
    return found;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));
    if (!solveNQueens(board, 0, n)) {
        cout << "No solution exists\n";
    }
}
