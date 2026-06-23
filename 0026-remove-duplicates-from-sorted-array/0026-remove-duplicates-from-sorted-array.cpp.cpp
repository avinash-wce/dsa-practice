/*
Problem: Remove Duplicates from Sorted Array

Approach:
- Use two pointers
- i tracks position of unique elements
- If current element is different, place it at next unique position

Time: O(n)
Space: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {

    int i = 0;

    for(int j = 1; j < nums.size(); j++) {

        // Found new unique element
        if(nums[j] != nums[i]) {

            i++;
            nums[i] = nums[j];
        }
    }

    return i + 1;
}