class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = gas.size();
        int st = 0;
        int totalGas = 0, totalCost = 0;
        int currGas = 0;
        for(int i = 0; i < n; ++i){
            currGas = currGas + gas[i] - cost[i];
            totalGas+=gas[i];
            totalCost+=cost[i];
            if (currGas < 0){
                st = i+1;
                currGas = 0;
            } 
        }
        if (totalGas < totalCost) return -1;
        else return st;
    }
};