class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int>arr;
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] >= 0){
                arr.push_back(nums[i]);
            }else{
                arr.push_back(-nums[i]);
            }
        }
        sort(arr.rbegin(), arr.rend());
        int x = (nums.size()-1) / 2;
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if (i <= x){
                ans+= ((long long)arr[i] * arr[i]);
            }else{
                ans-= ((long long)arr[i] * arr[i]);
            }
        }
        return ans;
    }
};