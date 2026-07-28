class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        sort(s.begin(), s.end());
        vector<char> ch(n);
        int l = 1, r = n-1;
        int idx = 0;
        while(l <= n){
            if(l < n && s[l] == s[l-1]){
                ch[idx] = s[l];
                ch[r-idx] = s[l];
                l += 2;
                idx++;
            } else{
                ch[n/2] = s[l - 1];
                l++;
            }
        }
        string ans = "";
        for(int i = 0; i < n; i++){
            ans += ch[i];
        }
        return ans;
    }
};