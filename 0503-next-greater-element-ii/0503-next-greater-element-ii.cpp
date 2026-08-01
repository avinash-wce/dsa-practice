class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int k = nums.size();
        stack<int> s;
        vector<int> NG(2*nums.size());
        for(int i = 0; i < k - 1; i++){
            nums.push_back(nums[i]);
        }
        int n = nums.size();
        for(int i = n-1; i >= 0; i--){
            while(!s.empty() && s.top() <= nums[i]){
                s.pop();
            }
            NG[i] = s.empty() ? -1 : s.top();
            s.push(nums[i]);
        }
        for(int i = k; i < n + 1; i++){
            NG.pop_back();
        }
        return NG;
    }
};