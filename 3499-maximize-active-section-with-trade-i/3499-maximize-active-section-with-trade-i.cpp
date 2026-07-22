class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int ones = 0;
        for(int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ones++;
            }
        }
        string t = "1" + s + "1";
        vector<pair<char, int>> hs;
        int m = t.size();
        int i = 0;
        while( i < m) {
            char ch = t[i];
            int count = 0;
            while(i < m && t[i] == ch) {
                count++;
                i++;
            }
            hs.push_back({ch, count});
        }
        int max_gain = 0;
        for (int k = 1; k + 1 < hs.size(); k++) {
            if(hs[k].first == '1' && hs[k - 1].first == '0' && hs[k + 1].first == '0') {
                int gain = hs[k-1].second + hs[k + 1].second;
                max_gain = max(max_gain, gain);
            }
        }
        return ones + max_gain;
    }
};