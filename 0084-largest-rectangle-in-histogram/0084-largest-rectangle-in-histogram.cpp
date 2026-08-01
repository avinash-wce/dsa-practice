class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        vector<int> pre(n);
        vector<int> suf(n);
        for(int i = n-1; i >= 0; i--){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            suf[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        for(int i = 0; i < n; i++){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            pre[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        long long ans = 0;
        for(int i = 0; i < n; i++){
            int width = suf[i] - pre[i] - 1;
            long long currArea = heights[i] * width;
            ans = max(ans, currArea);
        }
        return ans;
    }
};