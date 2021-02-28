class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int res = -1e4;
        int sum = 0;
        vector<int> count(toppingCosts.size(), 0);
        for (int& base : baseCosts) {
            sum = base;
            helper(toppingCosts, target, sum, 0, res);
            if (res == target) return res;
        }
        return res;
    }
private:
    void helper(vector<int>& tops, int& target, int& sum, int index, int& res) {
        int diff_res = abs(res-target);
        int diff_sum = abs(sum - target);
        if (diff_res > diff_sum || diff_res == diff_sum && res > sum) res = sum;
        if (index == tops.size() || sum >= target) return;
        
        sum += tops[index];
        helper(tops, target, sum, index+1, res);
        sum += tops[index];
        helper(tops, target, sum, index+1, res);
        sum -= 2*tops[index];
        helper(tops, target, sum, index+1, res);
    }
};