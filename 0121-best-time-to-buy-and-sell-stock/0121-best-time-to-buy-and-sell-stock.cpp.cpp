/*
Problem: Best Time to Buy and Sell Stock
Approach:
- Track minimum price so far
- Calculate profit = current price - min price
- Update max profit

Time: O(n)
Space: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int price : prices) {
        minPrice = min(minPrice, price);
        maxProfit = max(maxProfit, price - minPrice);
    }

    return maxProfit;
}