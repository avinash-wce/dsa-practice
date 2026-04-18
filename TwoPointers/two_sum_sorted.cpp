/*
Problem: Two Sum II (Input Array is Sorted)

Approach:
- Use two pointers
- One at start, one at end
- Move pointers based on sum

Time: O(n)
Space: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];

        if (sum == target) {
            return {left + 1, right + 1}; // 1-based index
        }
        else if (sum < target) {
            left++;
        }
        else {
            right--;
        }
    }

    return {};
}