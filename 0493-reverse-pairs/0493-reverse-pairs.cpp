class Solution {
public:
    int merge(vector<int>& nums, int st, int mid, int end) {
        vector<int> temp;
        int i = st, j = mid + 1;
        int RevCount = 0;
        
        int r = mid + 1;
        for (int l = st; l <= mid; l++) {
            while (r <= end && (long long)nums[l] > 2LL * nums[r]) {
                r++;
            }
            RevCount += (r - (mid + 1));
        }
        
        while ( i <= mid && j <= end) {
            if (nums[i] > nums[j]) {
                temp.push_back(nums[j]);
                j++;
            } else {
                temp.push_back(nums[i]);
                i++;
            }
        }
        //remaining
        while ( i <= mid ) {
            temp.push_back(nums[i]);
            i++;
        }
        while ( j <= end ) {
            temp.push_back(nums[j]);
            j++;
        }

        //Position of temp in nums
        for (int idx = 0; idx < temp.size(); idx++) {
            nums[st + idx] = temp[idx];
        }
        return RevCount;
    }

    int mergeSort(vector<int>& nums, int st, int end) {
        if (st < end) {
            int mid = st + (end - st) / 2;
            //Divide
            int leftRevCount = mergeSort(nums, st, mid);
            int rightRevCount = mergeSort(nums, mid + 1, end);
            //Merge
            int RevCount = merge(nums, st, mid, end);
            return leftRevCount + rightRevCount + RevCount;
        }
        return 0;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};