class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long resources = k;
        long long cost = 0;
        long long multiplier = 1;
        for(int x : nums) {
            if (resources < x) {
                long long less = x - resources;
                long long gap = (less+k-1)/ k;
                long long start_mult = multiplier;
                long long end_mult = multiplier + gap - 1;
                long long temp1 = gap;
                long long temp2 = start_mult + end_mult;
                if (temp1 % 2 == 0) {
                    temp1 /= 2;
                } else {
                    temp2/=2;
                }
                long long batch_cost = ((temp1 % 1000000007) * (temp2 % 1000000007)) % 1000000007;
                cost = (cost + (batch_cost % 1000000007)) % 1000000007;
                multiplier += gap;
                resources += gap * k;
            }
            resources -= x;
        }
        return cost;
    }
};
