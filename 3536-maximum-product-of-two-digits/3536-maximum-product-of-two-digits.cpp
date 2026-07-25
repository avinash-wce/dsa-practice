class Solution {
public:
    int maxProduct(int n) {
        int first = 0;
        int second = 0;
        while(n != 0){
            int dig = n % 10;
            if (dig >=  first){
                second = first;
                first = dig;
            }
            if (dig > second && dig < first){
                second = dig;
            }
            n = n/10;
        }
        return first*second;
    }
};