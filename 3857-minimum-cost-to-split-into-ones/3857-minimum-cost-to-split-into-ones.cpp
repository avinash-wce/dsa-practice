class Solution {
public:
    int minCost(int n) {
        if (n == 1){
            return 0;
        }
        int ans = 0;
        int a = 1, b = n-1;
        ans = a*b;
        while(b != 1){
            a = 1;
            b = b-1;
            ans = ans + a*b;
        }
        return ans;
    }
};