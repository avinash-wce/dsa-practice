class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        long long MOD = 1000000007;
        
        // Setup our prefix arrays with an extra leading 0 for easier math
        vector<long long> prefSum(n + 1, 0);
        vector<long long> prefNum(n + 1, 0);
        vector<long long> countNZ(n + 1, 0);
        vector<long long> p10(n + 1, 1);
        
        // 1. Precompute everything in a single pass O(N)
        for (int i = 0; i < n; i++) {
            // Precompute powers of 10
            p10[i + 1] = (p10[i] * 10) % MOD;
            
            long long digit = s[i] - '0';
            prefSum[i + 1] = prefSum[i] + digit;
            
            if (digit != 0) {
                prefNum[i + 1] = (prefNum[i] * 10 + digit) % MOD;
                countNZ[i + 1] = countNZ[i] + 1;
            } else {
                prefNum[i + 1] = prefNum[i];
                countNZ[i + 1] = countNZ[i];
            }
        }
        
        vector<int> ans;
        
        // 2. Answer each query instantly in O(1)
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            
            // Get the total sum for the range
            long long sum = prefSum[r + 1] - prefSum[l];
            
            // Get the number of non-zero digits in this range
            long long count = countNZ[r + 1] - countNZ[l];
            
            // Shift the left prefix by the correct power of 10
            long long sub = (prefNum[l] * p10[count]) % MOD;
            
            // Subtract to get the target range value 
            // (+ MOD ensures we don't get a negative number before modulo)
            long long x = (prefNum[r + 1] - sub + MOD) % MOD;
            
            ans.push_back((x * sum) % MOD);
        }
        
        return ans;
    }
};