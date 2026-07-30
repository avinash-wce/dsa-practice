class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int rem = (n-1)/8 + 1;
        return rem * (rem - 1) * 4 + (n - (rem - 1) * 8) * rem;
    }
};