/*
Problem: Single Number

Approach:
- Use XOR
- a ^ a = 0, a ^ 0 = a

Time: O(n)
Space: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (int val : nums) {
        ans ^= val;
    }
    return ans;
}