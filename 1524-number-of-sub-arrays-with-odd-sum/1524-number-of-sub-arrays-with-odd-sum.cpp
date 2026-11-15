class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> pref(n);
        int curr = 0;
        for(int i = 0; i < n; i++){
            curr = curr + arr[i];
            pref[i] = curr;
        }
        int even = 1;
        int odd = 0;
        long long ans = 0;
        for(int i = 0; i < n; i++){
            if(pref[i] % 2 == 0){
                ans += odd;
                even++;
            }else{
                ans += even;
                odd++;
            }
        }
        return ans % (long long)(1e9 + 7);
    }
};