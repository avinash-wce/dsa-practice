/*
Problem: Search a 2D Matrix

Approach:
- Use binary search on rows
- Find row where target can exist
- Then apply binary search on that row

Time: O(log m + log n)
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

        int stRow = 0;
        int endRow = m - 1;

        // Binary search on rows
        while(stRow <= endRow) {

            int midRow = stRow + (endRow - stRow) / 2;

            // Target can exist in this row
            if(matrix[midRow][0] <= target &&
               matrix[midRow][n - 1] >= target) {

                int stCol = 0;
                int endCol = n - 1;

                // Binary search inside row
                while(stCol <= endCol) {

                    int midCol = stCol + (endCol - stCol) / 2;

                    if(matrix[midRow][midCol] == target) {
                        return true;
                    }
                    else if(matrix[midRow][midCol] < target) {
                        stCol = midCol + 1;
                    }
                    else {
                        endCol = midCol - 1;
                    }
                }

                return false;
            }

            // Target is in lower rows
            else if(matrix[midRow][n - 1] < target) {
                stRow = midRow + 1;
            }

            // Target is in upper rows
            else {
                endRow = midRow - 1;
            }
        }

        return false;
    }
};