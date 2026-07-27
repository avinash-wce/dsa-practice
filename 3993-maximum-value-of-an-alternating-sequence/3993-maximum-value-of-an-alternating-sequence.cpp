class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if (n == 1){
            return s;
        }
        long long ans;
        long long l = n/2;
        long long r = m - 1;
        if (n % 2 == 0 || n == 3){
            ans = s + ((l-1) * (m-1)) + m;
        } else {
            ans = s + (l * (m-1)) + 1;
        }
        return ans;
        

    }
};