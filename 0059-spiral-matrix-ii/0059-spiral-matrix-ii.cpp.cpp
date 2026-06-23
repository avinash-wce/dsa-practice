/*
Problem: Spiral Matrix II

Approach:
- Create n x n matrix
- Maintain four boundaries
- Fill numbers in spiral order
- Shrink boundaries after each layer

Time: O(n*n)
Space: O(1) excluding output matrix
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int stRow = 0;
        int stCol = 0;
        int endCol = n - 1;
        int endRow = n - 1;

        int num = 1;

        while(stRow <= endRow && stCol <= endCol) {

            // Fill top row
            for(int i = stCol; i <= endCol; i++) {
                matrix[stRow][i] = num++;
            }

            // Fill right column
            for(int i = stRow + 1; i <= endRow; i++) {
                matrix[i][endCol] = num++;
            }

            // Fill bottom row
            for(int i = endCol - 1; i >= stCol; i--) {
                matrix[endRow][i] = num++;
            }

            // Fill left column
            for(int i = endRow - 1; i >= stRow + 1; i--) {
                matrix[i][stCol] = num++;
            }

            // Move to inner layer
            stRow++;
            stCol++;
            endRow--;
            endCol--;
        }

        return matrix;
    }
};