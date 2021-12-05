class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<int> res(3, 0), t(3, 0);
        for (vector<int>& cost : costs) {
            t[0] = min(res[1], res[2])+cost[0];
            t[1] = min(res[0], res[2])+cost[1];
            t[2] = min(res[0], res[1])+cost[2];
            
            res.swap(t);
        }
        return min(res[0], min(res[1], res[2]));
    }
};