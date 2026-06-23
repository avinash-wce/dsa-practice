class Solution {
public:
    bool isPal(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void solve(string s, vector<vector<string>> &result,vector<string> &partition) {
        if (s.size() == 0) {
            result.push_back(partition);
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            string part = s.substr(0, i+1);
            if (isPal(part)) {
                //recursion
                partition.push_back(part);
                solve(s.substr(i+1), result, partition);

                //backtracking
                partition.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> partition;
        solve(s, result, partition);
        return result;
    }
};