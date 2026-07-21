class Solution {
public:
    bool isValid(string s) {
        stack<char> ps;
        for(int i = 0; i < s.length(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
                ps.push(s[i]);
            } else {
                if (ps.empty()) return false;
                if (s[i] == ')' && ps.top() != '('){
                    return false;
                }else if (s[i] == ']' && ps.top() != '['){
                    return false;
                }else if(s[i] == '}' && ps.top() != '{'){
                    return false;
                }else {
                    ps.pop();
                }
            }
        }
        return ps.size() == 0 ;
    }
};