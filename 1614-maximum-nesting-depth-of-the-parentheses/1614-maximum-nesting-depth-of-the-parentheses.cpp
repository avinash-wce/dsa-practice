class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int curr_ans = 0;
        for(int i = 0; i < s.length(); i++){
            if (s[i] == '('){
                curr_ans++;
            }
            if (s[i] == ')'){
                curr_ans--;
            }
            ans = max(ans, curr_ans);
        }
        return ans;
    }
};