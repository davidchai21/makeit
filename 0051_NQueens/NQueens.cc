class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> t;
        vector<bool> column(n, true);
        vector<bool> diagonal(2*n-1, true);
        vector<bool> anti(2*n-1, true);
        dfs(res, t, n, column, diagonal, anti);
        return res;
    }
private:
    void dfs(vector<vector<string>>& res, vector<string>& t, const int& n, vector<bool>& column, vector<bool>& diagonal, vector<bool>& anti) {
        if (t.size() == n) {
            res.push_back(t);
            return;
        }
        
        string ans(n, '.');
        int row = t.size();
        for (int i=0;i<n;++i) {
            if (column[i] && diagonal[i+n-row-1] && anti[i+row]) {
                ans[i] = 'Q';
                t.push_back(ans);
                column[i] = diagonal[i+n-row-1] = anti[i+row] = false;
                dfs(res, t, n, column, diagonal, anti);
                column[i] = diagonal[i+n-row-1] = anti[i+row] = true;
                t.pop_back();
                ans[i] = '.';
            }
        }
    }
};