class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> sum(amount+1, -1);
        sum[0] = 0;
        for (int i=1;i<=amount;++i) {
            for (int j=0;j<coins.size();++j) {
                int change = i-coins[j];
                if (change < 0 || sum[change] == -1) continue;
                if (sum[i] == -1) sum[i] = 1+sum[change];
                else sum[i] = min(1+sum[i-coins[j]], sum[i]);
            }
        }
        return sum[amount];
    }
};