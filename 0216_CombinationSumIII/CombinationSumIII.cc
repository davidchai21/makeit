class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if (n>45) return res;
        vector<int> t;
        helper(t, res, n, k, 1);
        return res;
    }
private:
    void helper(vector<int>& t, vector<vector<int>>& res, int num, int count, int pos) {
        if (count < 0 || num < 0) return;
        if (!count && !num) {
            res.push_back(t);
            return;
        }
        
        for (int k=pos;k<10;++k) {
            t.push_back(k);
            helper(t, res, num-k, count-1, k+1);
            t.pop_back();
        }
    }
};