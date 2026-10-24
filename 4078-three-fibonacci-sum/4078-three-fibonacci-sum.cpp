class Solution {
public:
    bool threeFibonacciSum(int n) {
        long long first = 0;
        long long second = 1;
        while(true){
            long long next = first + second;
            first = second;
            second = next;
            if(next*2 > n){
                return false;
            }
            if(next*2 == n){
                return true;
            }
        }
        return false;
    }
};