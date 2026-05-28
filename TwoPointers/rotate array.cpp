/*
Problem: Rotate Array

Approach:
- First reverse entire array
- Then reverse first k elements
- Then reverse remaining elements
- This rotates array to the right by k steps

Time: O(n)
Space: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<int>& nums, int k) {

    int n = nums.size();

    // Handle cases where k > n
    k = k % n;

    // Reverse whole array
    reverse(nums.begin(), nums.end());

    // Reverse first k elements
    reverse(nums.begin(), nums.end() - (n - k));

    // Reverse remaining elements
    reverse(nums.begin() + k, nums.end());
}