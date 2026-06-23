/*
Problem: Container With Most Water
Approach:
- Two pointers (left, right)
- Area = min(height[l], height[r]) * width
- Move smaller height pointer

Time: O(n)
Space: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int maxWater = 0;

    while (left < right) {
        int h = min(height[left], height[right]);
        int w = right - left;
        maxWater = max(maxWater, h * w);

        if (height[left] < height[right]) left++;
        else right--;
    }

    return maxWater;
}