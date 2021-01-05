class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> t;
        helper(candidates, target, t, res, 0);
        return res;
    }
private:
    void helper(vector<int>& can, int target, vector<int>& t, vector<vector<int>>& res, int pos) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(t);
            return;
        }
        
        for (int i=pos;i<can.size();++i) {
            if (i>pos && can[i]==can[i-1]) continue;    // avoid duplicated results
            t.push_back(can[i]);
            helper(can, target-can[i], t, res, i+1);
            t.pop_back();
        }
    }
};