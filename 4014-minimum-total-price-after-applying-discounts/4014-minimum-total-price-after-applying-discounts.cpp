class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());
        int p = prices.size(), d = discounts.size();
        int i = 0;
        double ans = 0;
        while(i < p && i < d){
            ans += (prices[i] * (100.0 - discounts[i])) / 100.0;
            i++;
        }
        while(i < p){
            ans += prices[i];
            i++;
        }
        return ans;
    }
};