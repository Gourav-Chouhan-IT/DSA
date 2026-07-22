#include <iostream>
#include <stack>
#include <utility>

using namespace std;

class StockSpanner {
private:
    // Stack stores pairs of: {price, span}
    stack<pair<int, int>> st;

public:
    StockSpanner() {
    }
    
    int next(int price) {
        int span = 1; // Start with a span of 1 for the current day
        
        // Pop all previous days with price <= current price and accumulate their spans
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        
        // Push current price along with its accumulated span
        st.push({price, span});
        
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */