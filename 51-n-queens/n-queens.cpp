class Solution {
public:
    vector<vector<string>> ans;


    bool isSafe(int row, int col, vector<string> &board, int n) {
        // check upper column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }

        // check upper-left diagonal
        int i = row, j = col;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q') return false;
            i--; j--;
        }

        i = row; j = col;
        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q') return false;
            i--; j++;
        }

        return true;
    }

    void addSolution(vector<string> &board) {
        ans.push_back(board);
    }

   
    void solve(int row, vector<string> &board, int n) {
        if (row == n) {
            addSolution(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';      // place queen
                solve(row + 1, board, n);   // next row
                board[row][col] = '.';      // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(0, board, n);
        return ans;
    }
};