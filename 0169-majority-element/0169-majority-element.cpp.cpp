/*
Problem: Majority Element

Approach:
- Use Boyer-Moore Voting Algorithm
- Keep a candidate and count
- If count becomes 0 → change candidate
- Increase/decrease count based on match

Time: O(n)
Space: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int count = 0;
    int candidate = 0;

    for (int val : nums) {
        if (count == 0) {
            candidate = val;
        }

        if (val == candidate) {
            count++;
        } else {
            count--;
        }
    }

    return candidate;
}