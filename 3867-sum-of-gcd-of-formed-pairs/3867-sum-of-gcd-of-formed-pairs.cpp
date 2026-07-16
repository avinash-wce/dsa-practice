class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGCD(n);
        int mx = 0;
        for(int i = 0; i < nums.size(); ++i) {
            mx = max(mx, nums[i]);
            prefixGCD[i] = gcd(nums[i], mx);
        }
        sort(prefixGCD.begin(), prefixGCD.end());
        int st = 0, end = nums.size() - 1;
        long long ans = 0;
        while(st < end) {
            ans += gcd(prefixGCD[st], prefixGCD[end]);
            st++;
            end--;
        }
        return ans;
    }
};