class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n-2, vector<int>(n-2));
        for (int i=1;i<n-1;++i) {
            for (int j=1;j<n-1;++j) {
                res[i-1][j-1] = helper(grid, i, j);
            }
        }
        return res;
    }
private:
    int helper(vector<vector<int>>& m, int i, int j) {
        int res = max(m[i-1][j-1], max(m[i-1][j], m[i-1][j+1]));
        res = max(res, max(m[i][j-1], max(m[i][j], m[i][j+1])));
        res = max(res, max(m[i+1][j-1], max(m[i+1][j], m[i+1][j+1])));
        return res;
    }
};