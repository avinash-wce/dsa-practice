/*
Problem: Spiral Matrix

Approach:
- Maintain four boundaries:
  stRow, endRow, stCol, endCol
- Traverse one layer at a time
- Shrink boundaries after completing a layer

Time: O(m*n)
Space: O(1) excluding answer vector
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        int stRow = 0;
        int stCol = 0;
        int endCol = n - 1;
        int endRow = m - 1;

        vector<int> ans;

        while(stRow <= endRow && stCol <= endCol) {

            // Traverse top row
            for(int i = stCol; i <= endCol; i++) {
                ans.push_back(matrix[stRow][i]);
            }

            // Traverse right column
            for(int i = stRow + 1; i <= endRow; i++) {
                ans.push_back(matrix[i][endCol]);
            }

            // Traverse bottom row
            for(int i = endCol - 1; i >= stCol; i--) {

                // Prevent duplicate traversal
                if(stRow == endRow) {
                    break;
                }

                ans.push_back(matrix[endRow][i]);
            }

            // Traverse left column
            for(int i = endRow - 1; i >= stRow + 1; i--) {

                // Prevent duplicate traversal
                if(stCol == endCol) {
                    break;
                }

                ans.push_back(matrix[i][stCol]);
            }

            // Move to inner layer
            stRow++;
            stCol++;
            endRow--;
            endCol--;
        }

        return ans;
    }
};