/*
Problem: Next Permutation

Approach:
- Find first decreasing element from right
- Find next greater element from right
- Swap both elements
- Reverse remaining right part

Time: O(n)
Space: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {

    int n = nums.size();

    int index = -1;

    // Find breakpoint
    for(int i = n - 2; i >= 0; i--) {

        if(nums[i] < nums[i + 1]) {
            index = i;
            break;
        }
    }

    // If no breakpoint, reverse whole array
    if(index == -1) {

        reverse(nums.begin(), nums.end());
        return;
    }

    // Find next greater element
    for(int i = n - 1; i > index; i--) {

        if(nums[i] > nums[index]) {

            swap(nums[i], nums[index]);
            break;
        }
    }

    // Reverse right half
    reverse(nums.begin() + index + 1, nums.end());
}