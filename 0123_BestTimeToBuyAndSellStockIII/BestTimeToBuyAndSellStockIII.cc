class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> left(n, 0), right(n, 0);
        int left_min = prices.front();
        int right_max = prices.back();
        for (int i=1;i<n;++i) {
            left[i] = max(left[i-1], prices[i]-left_min);
            left_min = min(left_min, prices[i]);
            
            right[n-1-i] = max(right[n-i], right_max-prices[n-1-i]);
            right_max = max(right_max, prices[n-1-i]);
        }
        
        int res = right[0];
        for (int i=0;i<n-1;++i) {
            res = max(res, left[i]+right[i+1]);
        }
        return res;
    }
};

// O(1) space:

