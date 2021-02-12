class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                if (grid[i][j] == '1') {
                    ++res;
                    helper(grid, i, j, m, n);
                }
            }
        }
        return res;
    }
private:
    void helper(vector<vector<char>>& grid, int x, int y, int& m, int& n) {
        if (x<0 || y<0 || x>=m || y>=n || grid[x][y]=='0') return;
        grid[x][y] = '0';
        helper(grid, x+1, y, m, n);
        helper(grid, x-1, y, m, n);
        helper(grid, x, y+1, m, n);
        helper(grid, x, y-1, m, n);
    }
};