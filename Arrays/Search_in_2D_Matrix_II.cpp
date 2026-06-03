/*
Problem: Search a 2D Matrix II

Approach:
- Start from top-right corner
- Move left if current element is greater
- Move down if current element is smaller
- Eliminate one row or column in each step

Time: O(m + n)
Space: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int row = 0;
        int col = n - 1;

        while(row < m && col >= 0) {

            if(matrix[row][col] == target) {
                return true;
            }

            else if(matrix[row][col] > target) {
                col--;
            }

            else {
                row++;
            }
        }

        return false;
    }
};