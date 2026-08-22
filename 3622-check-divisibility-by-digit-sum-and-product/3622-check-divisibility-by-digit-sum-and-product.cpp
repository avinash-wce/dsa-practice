class Solution {
public:
    bool checkDivisibility(int n) {
        int og = n;
        int sum = 0;
        int product = 1;
        while(n > 0){
            int dig = n % 10;
            sum += dig;
            product *= dig;
            n /= 10;
        }
        return (og % (sum + product)) == 0;
    }
};