class Solution {
public:
    int sumOfPrimesInRange(int n) {
        int dig = n;
        int r = 0;
        while(n!=0){
            r = n % 10 + r * 10;
            n = n/10;
        }
        int miny = min(dig, r);
        int maxy = max(dig, r);
        int ans = 0;
        for(int i = miny; i <= maxy; i++){
            if (i <= 1) continue;
            bool check = true;
            for(int j = 2; j*j <= i; j++){
                if (i % j == 0){
                    check = false;
                }
            }
            if (check){
                ans+=i;
            }
        }
        return ans;
    }
};