class Solution {
public:
    int mirrorFrequency(string s) {
        int n = s.length();
        unordered_map<char,int> freq;
        for(int i = 0; i < n; i++){
            freq[s[i]]++;
        }
        int total_sum = 0;
        for (char c = 'a'; c <= 'm'; c++) {
            char m = 'a' + ('z' - c);
            total_sum += abs(freq[c] - freq[m]);
        }
        for (char c = '0'; c <= '4'; c++) {
            char m = '0' + ('9' - c);
            total_sum += abs(freq[c] - freq[m]);
        }

        return total_sum;
    }
};