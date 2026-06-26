class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int r, int c, int n, int expValue) {
        //base case
        if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != expValue) return false;
        if (expValue == n*n - 1) return true;
        //check
        bool ans1 = isValid(grid, r - 2, c + 1, n, expValue + 1);
        bool ans2 = isValid(grid, r - 1, c + 2, n, expValue + 1);
        bool ans3 = isValid(grid, r + 1, c + 2, n, expValue + 1);
        bool ans4 = isValid(grid, r + 2, c + 1, n, expValue + 1);
        bool ans5 = isValid(grid, r + 2, c - 1, n, expValue + 1);
        bool ans6 = isValid(grid, r + 1, c - 2, n, expValue + 1);
        bool ans7 = isValid(grid, r - 1, c - 2, n, expValue + 1);
        bool ans8 = isValid(grid, r - 2, c - 1, n, expValue + 1);
        //ans
        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8 ;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        return isValid(grid, 0, 0, n, 0);
    }
};