class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> t;
        helper(candidates, target, res, t, 0);
        return res;
    }
private:
    void helper(vector<int>& can, int target, vector<vector<int>>& res, vector<int>& t, int pos) {
        if (pos >= can.size() || target < 0) return;
        if (target == 0) {
            res.push_back(t);
            return;
        }
        
        for (int i=pos;i<can.size();++i) {
            t.push_back(can[i]);
            helper(can, target-can[i], res, t, i);
            t.pop_back();
        }
    }
};