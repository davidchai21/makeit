class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> t;
        helper(t, res, 1, n, k);
        return res;
    }
private:
    void helper(vector<int>& t, vector<vector<int>>& res, int pos, int n, int k) {
        if (k == t.size()) {
            res.push_back(t);
            return;
        }
        if (pos > n) return;
        
        for (int i = pos; i<=n;++i) {
            t.push_back(i);
            helper(t, res, i+1, n, k);
            t.pop_back();
        }
    }
};