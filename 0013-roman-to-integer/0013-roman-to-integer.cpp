class Solution {
public:
    int romanToInt(string s) {
        int n = s.length() - 1;
        unordered_map<char,int> hs;
        hs['I'] = 1 ;
        hs['V'] = 5 ;
        hs['X'] = 10 ; 
        hs['L'] = 50 ; 
        hs['C'] = 100; 
        hs['D'] = 500; 
        hs['M'] = 1000;
        int num = hs[s[n]];
        for (int i = n-1; i >= 0; i--) {
            if (hs[s[i]] < hs[s[i+1]]) {
                num -= hs[s[i]];
            } else {
                num += hs[s[i]];
            }
        }
        return num;
    }
};