/*class Solution { //Brute Force wont get submitted : TC : O(n*k)
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i <= n-k; i++){
            int maxy = -1e7;
            for(int j = i; j < i+k; j++){
                maxy = max(nums[j], maxy);
            }
            ans.push_back(maxy);
        }
        return ans;
    }
}; */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int>dq;
        //First Window
        for(int i = 0; i < k; i++){
            while(dq.size() > 0 && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        //Rest windows
        for(int i = k; i < n; i++){
            ans.push_back(nums[dq.front()]);
            //remove indices not from current window
            while(dq.size() > 0 && dq.front() <= i-k){
                dq.pop_front();
            }
            //remove smaller elements indices
            while(dq.size() > 0 && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        return ans;
    }
};