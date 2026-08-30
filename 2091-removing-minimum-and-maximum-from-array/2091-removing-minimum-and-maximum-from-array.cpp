class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int max_idx = -1;
        int min_idx = -1;
        int maxy = -1e7;
        int miny = 1e7;
        for (int i = 0; i < n; i++) {
            if (maxy < nums[i]) {
                maxy = nums[i];
                max_idx = i;
            }
            if (nums[i] < miny) {
                miny = nums[i];
                min_idx = i;
            }
        }
        if (min_idx == max_idx) {
            return min(min_idx + 1, n - min_idx);
        }
        int from_front = 0;
        int from_back = 0;
        int from_both = 0;
        if(min_idx > max_idx){
            from_front = min_idx + 1;
            from_back = n - max_idx;
            from_both = n - min_idx + max_idx + 1;
        }else{
            from_front = max_idx + 1;
            from_back = n - min_idx;
            from_both = n - max_idx + min_idx + 1;
        }
        return min({from_front, from_back, from_both});
    }
};