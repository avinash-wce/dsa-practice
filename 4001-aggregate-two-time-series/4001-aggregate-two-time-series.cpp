class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>>ans;
        int l = 0, r = 0;
        int temp1 = 0, temp2 = 0;
        while (l < series1.size() && r < series2.size()) {
            if (series1[l][0] < series2[r][0]) {
                temp1 = series1[l][0];
                temp2 = series1[l][1] + series2[r][1];
                ans.push_back({temp1, temp2});
                l++;
            } else if (series1[l][0] > series2[r][0]) {
                temp1 = series2[r][0];
                temp2 = series1[l][1] + series2[r][1];
                ans.push_back({temp1, temp2});
                r++;
            } else {
                temp1 = series1[l][0];
                temp2 = series1[l][1] + series2[r][1];
                ans.push_back({temp1, temp2});
                l++;
                r++;
            }
        }

        while (l < series1.size()) {
            ans.push_back(series1[l]);
            l++;
        }
        while (r < series2.size()) {
            ans.push_back(series2[r]);
            r++;
        }
        return ans;
    }
};