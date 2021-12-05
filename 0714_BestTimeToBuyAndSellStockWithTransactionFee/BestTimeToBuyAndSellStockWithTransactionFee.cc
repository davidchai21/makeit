class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0, hold = -prices[0];
        for (int i=1;i<prices.size();++i) {
            int newCash = prices[i]+hold-fee;
            int newHold = cash-prices[i];
            cash = max(cash, newCash);
            hold = max(newHold, hold);
        }
        return cash;
    }
};