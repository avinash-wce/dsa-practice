class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        vector<int>ans;
        unordered_map<long long,long long> freq;
        for(int i = 1; pow(i, 3) <= n; i++){
            for(int j = i; pow(i, 3) + pow(j, 3) <= n; j++){
                freq[pow(i, 3) + pow(j, 3)]++;
            }
        }
        for(auto const& [sum, count] : freq) {
            if(count >= 2) {
                ans.push_back(sum);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};