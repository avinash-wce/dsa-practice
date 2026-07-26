class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int firstneg = 0, secondneg = 0;
        int firstpos = -1e7, secondpos = -1e7, third = -1e7;
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
        return max(firstpos * secondpos * third, firstneg * secondneg * firstpos);
    }
};