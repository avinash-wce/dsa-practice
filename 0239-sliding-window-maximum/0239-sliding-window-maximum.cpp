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

/*class Solution { //tutorial + my solution
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
}; */

//cleaner AI Imlementation in one loop though TC and SC are identical
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;

        for (int i = 0; i < n; i++) {
            // 1. Remove indices outside the current window range [i - k + 1, i]
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // 2. Remove indices with values smaller than the current element
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // 3. Add current element's index
            dq.push_back(i);

            // 4. Record maximum once the first window of size k is formed
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
