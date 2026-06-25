class Solution {
public:
    void merge(vector<int>& nums, vector<int>& temp, int st, int mid, int end) {
        int i = st, j = mid + 1, k = st;

        while ( i <= mid && j <= end) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }

        while ( i <= mid) {
            temp[k++] = nums[i++];
        }
        while ( j <= end) {
            temp[k++] = nums[j++];
        }

        for (int idx = st; idx <= end; idx++) {
            nums[idx] = temp[idx];
        }

    }

    void solve(vector<int>& nums, vector<int>& temp, int st, int end){
        if (st >= end) {
            return;
        }

        int mid = st + (end - st) / 2;
        //divide
        solve(nums, temp, st, mid);
        solve(nums, temp, mid + 1, end);
        //merge
        merge(nums, temp, st, mid, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());
        solve(nums, temp, 0, nums.size() - 1);
        return nums;
    }
};