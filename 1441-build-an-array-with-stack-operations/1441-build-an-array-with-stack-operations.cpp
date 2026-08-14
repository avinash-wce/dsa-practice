class Solution {
public:
    vector<string> buildArray(vector<int>& nums, int n) {
        vector<string> ans;
        int j = 0;
        for (int i = 1; i <= n; ++i) {
            if (j == nums.size()) {
                break;
            }    
            ans.push_back("Push");
            if (nums[j] == i) {
                j++;
            } else {
                ans.push_back("Pop");
            }
        }  
        return ans;
    }
};