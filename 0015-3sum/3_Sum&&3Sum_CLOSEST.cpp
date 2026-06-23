/*
Problem: 3 Sum

Approach:
- Sort the array
- Fix one element nums[i]
- Use two pointers to find remaining two elements
- Skip duplicates to avoid repeated triplets

Time: O(n²)
Space: O(1) excluding answer vector
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {

    vector<vector<int>> anss;

    sort(nums.begin(), nums.end());

    int n = nums.size();

    for(int i = 0; i < n; i++) {

        // Skip duplicate fixed elements
        if(i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int target = -nums[i];

        int left = i + 1;
        int right = n - 1;

        while(left < right) {

            int sum = nums[left] + nums[right];

            if(sum < target) {

                left++;
            }

            else if(sum > target) {

                right--;
            }

            else {

                vector<int> ans;

                ans.push_back(nums[i]);
                ans.push_back(nums[left]);
                ans.push_back(nums[right]);

                anss.push_back(ans);

                left++;
                right--;

                // Skip duplicate left values
                while(left < right &&
                      nums[left] == nums[left - 1]) {

                    left++;
                }

                // Skip duplicate right values
                while(left < right &&
                      nums[right] == nums[right + 1]) {

                    right--;
                }
            }
        }
    }

    return anss;
}

/*
Problem: 3 Sum Closest

Approach:
- Sort the array
- Fix one element nums[i]
- Use two pointers to find closest pair
- Maintain best answer seen so far

Time: O(n²)
Space: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {

    sort(nums.begin(), nums.end());

    int ans = nums[0] + nums[1] + nums[2];

    for(int i = 0; i < nums.size(); i++) {

        int targetto = target - nums[i];

        int l = i + 1;
        int j = nums.size() - 1;

        while(l < j) {

            int two_sum = nums[l] + nums[j];
            int current_sum = nums[i] + nums[l] + nums[j];

            // Update closest answer
            if(abs(current_sum - target) <
               abs(ans - target)) {

                ans = current_sum;
            }

            if(two_sum < targetto) {

                l++;
            }
            else {

                j--;
            }
        }
    }

    return ans;
}