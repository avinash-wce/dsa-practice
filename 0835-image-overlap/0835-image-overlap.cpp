class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img2.size();
        vector<pair<int,int>> a,b;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j] == 1) a.push_back({i, j});
                if(img2[i][j] == 1) b.push_back({i, j});
            }
        }
        map<pair<int,int>, int>count;
        int ans = 0;
        for(auto& p1 : a){
            for(auto& p2 : b){
                pair<int, int> vector = {p2.first - p1.first, p2.second - p1.second};
                count[vector]++;
                ans = max(ans, count[vector]);
            }
        }
        return ans;
    }
};