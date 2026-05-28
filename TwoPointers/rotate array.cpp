/*
Problem: Rotate Array
/*

/* BRUTE FORCE

Approach:
- Rotate array one step k times
- Store last element
- Shift all elements right
- Put last element at start

Time: O(n*k)
Space: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int>& nums, int k) {

    int n = nums.size();

    k = k % n;

    for(int i = 0; i < k; i++) {

        int last = nums[n - 1];

        for(int j = n - 1; j > 0; j--) {
            nums[j] = nums[j - 1];
        }

        nums[0] = last;
    }
}

/* EXTRA SPACE NEW ARRAY

Approach:
- Create temporary array
- Place each element at rotated position
- Copy back to original array

Time: O(n)
Space: O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int>& nums, int k) {

    int n = nums.size();

    k = k % n;

    vector<int> temp(n);

    for(int i = 0; i < n; i++) {

        temp[(i + k) % n] = nums[i];
    }

    nums = temp;
}

/*

OPTIMAL BY REVERSE ARRAY
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
