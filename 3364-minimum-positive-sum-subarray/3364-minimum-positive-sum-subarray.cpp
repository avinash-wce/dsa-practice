class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            int size = 1;
            int curr_sum = nums[i];
            if(size <= r && size>=l && curr_sum > 0){
                    ans = min(ans, curr_sum);
            }
            for(int j = i + 1; j < n; j++){
                size++;
                curr_sum = curr_sum + nums[j];
                if(size <= r && size>=l && curr_sum > 0){
                    ans = min(ans, curr_sum);
                }
                if(size > r){
                    break;
                }
            }
        }
        if (ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};