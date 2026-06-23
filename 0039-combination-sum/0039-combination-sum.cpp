class Solution {
public:
    void solve(vector<int>& ans, int remaining_target, int st, vector<int>& candidates, vector<vector<int>> &result) {
        if (remaining_target == 0) {
            result.push_back(ans);
            return;
        }
        for (int i = st; i < candidates.size(); i++) {
            if (candidates[i] > remaining_target) {
                break;
            }

            //recursion
            ans.push_back(candidates[i]);
            solve(ans, remaining_target - candidates[i], i, candidates, result);

            //backtracking
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        vector<int> ans;
        solve(ans, target, 0, candidates, result);
        return result;
    }
};