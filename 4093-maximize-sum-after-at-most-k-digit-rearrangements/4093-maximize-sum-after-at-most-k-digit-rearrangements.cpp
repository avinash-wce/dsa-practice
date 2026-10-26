class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        vector<pair<long long, long long>> vec; // stores {gain, max_val}
        
        for(int x : nums) {
            string s = to_string(x);
            string orig_s = s;
            sort(s.rbegin(), s.rend());
            long long max_val = stoll(s);
            long long gain = max_val - x;
            vec.push_back({gain, max_val});
        }
        sort(vec.rbegin(), vec.rend());
        long long total_sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i < k) {
                total_sum += vec[i].second;
            } else {
                total_sum += (vec[i].second - vec[i].first); 
            }
        }
        return total_sum;
    }
};