class StockSpanner {
    // Stores pairs of (price) represented by indices
    vector<int> prices;
    stack<int> st; // Stores indices of prices in decreasing order

public:
    StockSpanner() {}
    
    int next(int price) {
        prices.push_back(price);
        int day = prices.size() - 1; // Current 0-based index
        
        // Pop indices where prices are <= current price
        while (!st.empty() && prices[st.top()] <= price) {
            st.pop();
        }
        
        // If stack is empty, all previous prices were <= current price
        int span = st.empty() ? (day + 1) : (day - st.top());
        
        st.push(day);
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */