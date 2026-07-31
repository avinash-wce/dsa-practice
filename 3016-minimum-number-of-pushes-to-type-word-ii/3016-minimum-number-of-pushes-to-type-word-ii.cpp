class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26);
        for(int i = 0; i < word.length(); ++i){
            freq[word[i] - 'a']++;
        }
        sort(freq.rbegin(), freq.rend());
        int ans = 0;
        for(int i = 0; i < 26; ++i){
            if(freq[i] == 0) break;
            ans += (i/8 + 1) * freq[i];
        }
        return ans;
    }
};