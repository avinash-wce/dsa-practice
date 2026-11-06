class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int maxi = INT_MIN;
        int second_max = INT_MIN;
        int mini = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            mini = min(nums[i], mini);
            if(nums[i] > maxi){
                second_max = maxi;
                maxi = nums[i];
            }
            else if(nums[i] > second_max){
                second_max = nums[i];
            }
        }
        return maxi + second_max - mini;
    }
};