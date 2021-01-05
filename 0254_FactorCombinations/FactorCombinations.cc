class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        if (n < 2) return res;
        vector<int> t;
        helper(res, t, n, 1L, 2);
        return res;
    }
private:
    void helper(vector<vector<int>>& res, vector<int>& t, int n, long p, int start) {
        if (p == n) {
            res.push_back(t);
            return;
        }
        if (start > n/2 || p>n) return;
        
        for (int k=start;k<=n/2 && k*p <=n;++k) {
            if (n%k==0) {
                t.push_back(k);
                helper(res, t, n, p*k, k);
                t.pop_back();
            }
        }
    }
};