class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans1 = 0;
        int ans2 = 0;
        int curr_inc = 1;
        int curr_dec = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1]){
                curr_dec++;
            }
            else if(nums[i] >= nums[i-1]){
                ans2 = max(ans2, curr_dec);
                curr_dec = 1;
            }
            if(nums[i] > nums[i-1]){
                curr_inc++;
            }
            else if(nums[i] <= nums[i-1]){
                ans1 = max(ans1, curr_inc);
                curr_inc = 1;
            }
        }
        ans1 = max(ans1, curr_inc);
        ans2 = max(ans2, curr_dec);
        return max(ans1, ans2);
    }
};