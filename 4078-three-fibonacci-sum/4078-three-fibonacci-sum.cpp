class Solution {
public:
    bool threeFibonacciSum(int n) {
        vector<long long> fib;
        fib.push_back(0);
        fib.push_back(1);
        while(true){
            long long next = fib[fib.size()-1] + fib[fib.size()-2];
            fib.push_back(next);
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