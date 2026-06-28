class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.rbegin(), nums.rend());
        long long total = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (k > 0) {
                if (mul > 0) {
                    total += (long long)nums[i]*mul;
                    mul -= 1;
                } else {
                    total += nums[i];
                }
            }
            k -= 1;
        }
        return total;
    }
};