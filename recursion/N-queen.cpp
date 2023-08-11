link::-->https://leetcode.com/problems/n-queens/description/

code::-->
class Solution {
public:
    bool issafe(vector<string>& board, int row, int col, int n) {
        // check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        // row check;
        for (int i = 0; i < n; i++) {
            if (board[row][i] == 'Q') return false;
        }
        // upper left diagonal
        for (int r = row, c = col; r >= 0 && c >= 0; r--, c--) {
            if (board[r][c] == 'Q') return false;
        }
        // lower left diagonal
        for (int r = row, c = col; r < n && c >= 0; r++, c--) {
            if (board[r][c] == 'Q') return false;
        }

        return true;
    }

    void solve(vector<vector<string>>& ans, vector<string>& board, int n, int col) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (issafe(board, i, col, n)) {
                board[i][col] = 'Q';
                solve(ans, board, n, col + 1);
                board[i][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(ans, board, n, 0);
        return ans;
    }
};
