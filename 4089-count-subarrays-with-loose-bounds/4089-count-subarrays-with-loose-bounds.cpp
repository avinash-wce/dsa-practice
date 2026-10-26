class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        long long count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= minK && nums[i] <= maxK){
                ans++;
                count++;
            }
            if(nums[i] < minK || nums[i] > maxK){
                count = 0;
            }
            if(count > 1){
                ans+= count - 1;
            }
        }
        return ans;
    }
};