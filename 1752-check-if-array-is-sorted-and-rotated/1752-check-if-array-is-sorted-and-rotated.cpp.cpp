/*
Problem: Check if Array Is Sorted and Rotated

Approach:
- Count decreasing pairs
- Also check last and first element
- Rotated sorted array can have at most one break point

Time: O(n)
Space: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int>& nums) {

    int n = nums.size();
    int count = 0;

    for(int i = 0; i < n - 1; i++) {

        if(nums[i] > nums[i + 1]) {
            count++;
        }
    }

    if(nums[n - 1] > nums[0]) {
        count++;
    }

    return count < 2;
}