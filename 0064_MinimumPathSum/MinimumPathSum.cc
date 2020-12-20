class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i=n-2;i>=0;--i) {
            grid[m-1][i] += grid[m-1][i+1];
        }
        for (int i=m-2;i>=0;--i) { 
            for (int j=n-1;j>=0;--j) {
                if (j==n-1) grid[i][j] += grid[i+1][j];
                else {
                    grid[i][j] += min(grid[i+1][j], grid[i][j+1]);
                }
            }
        }
        return grid[0][0];
    }
};

// 1-D vector:

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rec(grid.back());
        for (int i=n-2;i>=0;--i) rec[i] += rec[i+1];
        for (int i=m-2;i>=0;--i) {
            vector<int> t(n);
            for (int j=n-1;j>=0;--j) {
                if (j==n-1) t[j] = rec[j] + grid[i][j];
                else {
                    t[j] = grid[i][j] + min(rec[j], t[j+1]);
                }
            }
            swap(t, rec);
        }
        return rec.front();
    }
};