class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> hs(password.begin(), password.end());
        int ans = 0;
        for(char c : hs){
            if(c >= 'a' && c <= 'z'){
                ans+=1;
            }
            if(c >= 'A' && c <= 'Z'){
                ans+=2;
            }
            if(c >= '0' && c <= '9'){
                ans+=3;
            }
            if (c == '!' || c == '@' || c == '#' || c == '$'){
                ans+=5;
            }
        }
        return ans;
    }
};