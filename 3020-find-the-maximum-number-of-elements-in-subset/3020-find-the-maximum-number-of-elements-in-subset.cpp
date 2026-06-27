class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int x : nums) {
            freq[x]++;
        }

        int ans = (freq[1] - 1) | 1;
        freq.erase(1);

        for (auto& [val, count] : freq) {
            long long x = val;
            int current_length = 0;
            
            while (freq.count(x) && freq[x] >= 2) {
                current_length += 2;
                x *= x;
            }

            if (freq.count(x)) {
                current_length += 1;
            } else {
                current_length -= 1;
            }
            ans = max(ans, current_length);
        }
        return ans;
    }
};