class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int max_profit = 0; int min_price = prices[0];
        for (int i = 0; i<prices.size() ; i++){
            min_price = min(prices[i],min_price);
            max_profit = max( prices[i] - min_price ,max_profit);
        }
        
        return max_profit;
    }
};