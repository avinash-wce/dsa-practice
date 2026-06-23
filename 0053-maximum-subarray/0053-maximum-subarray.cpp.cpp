/*
Problem: Maximum Subarray

Approach:
- Use Kadane's Algorithm
- Keep running sum
- Reset sum if it becomes negative
- Track maximum

Time: O(n)
Space: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int currentSum = 0;
    int maxi = INT_MIN;

    for (int val : nums) {
        currentSum += val;
        maxi = max(maxi, currentSum);

        if (currentSum < 0) {
            currentSum = 0;
        }
    }

    return maxi;
}