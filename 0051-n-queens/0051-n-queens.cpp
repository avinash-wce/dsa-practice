class Solution {
public:
        vector<vector<string>> ans;

    void ps(int row, int n, vector<int> &col, vector<int> &diag1, vector<int> &diag2, vector<string> &board) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int c = 0; c < n; c++){
            if (col[c] || diag1[row + c] || diag2[row - c + n -1]) {
                continue;
            }

            board[row][c] = 'Q';
            col[c] = 1;
            diag1[row + c] = 1;
            diag2[row - c + n - 1] = 1;
            ps(row + 1, n, col, diag1, diag2, board);

            board[row][c] = '.';
            col[c] = 0;
            diag1[row + c] = 0;
            diag2[row - c + n - 1] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<int> col(n, 0);
        vector<int> diag1(2*n - 1, 0);
        vector<int> diag2(2*n - 1, 0);

        ps(0,  n, col, diag1, diag2, board);

        return ans;
    }
};