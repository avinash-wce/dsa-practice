class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long n = nums.size();
        long long firstneg = 0, secondneg = 0;
        long long firstpos = -1e7, secondpos = -1e7, third = -1e7;
        for(int i = 0; i < n; ++i) {
            if (nums[i] < 0){
                if (firstneg < -1 * nums[i]){
                    secondneg = firstneg;
                    firstneg = -1 * nums[i];
                } else if (secondneg < -1 * nums[i]){
                    secondneg = -1 * nums[i];
                }
            }
            if (firstpos < nums[i]){
                third = secondpos;
                secondpos = firstpos;
                firstpos = nums[i];
            } else if (secondpos < nums[i]){
                third = secondpos;
                secondpos = nums[i];
            } else if  (third < nums[i]){
                third = nums[i];
            }

        }
        long long neg = max(firstneg * secondneg * 100000ll , firstneg * 100000ll * firstpos);
        return max(firstpos * secondpos * 100000ll, neg);
    }
};