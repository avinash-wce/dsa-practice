class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xoor = 0;
        bool zeroes = true;
        for(int i = 0; i < n; i++){
            xoor ^= nums[i];
            if (nums[i] > 0){
                zeroes = false;
            }
        }
        if (xoor > 0){
            return n;
        }
        if (zeroes){
            return 0;
        } else{
            return n-1;
        }
    }
};