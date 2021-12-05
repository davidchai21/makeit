class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        for (int i=0;i<m;++i) {
            change(grid, i, 0, m, n);
            change(grid, i, n-1, m, n);
        }
        for (int i=1;i<n-1;++i) {
            change(grid, 0, i, m, n);
            change(grid, m-1, i, m, n);
        }
        
        int res = 0;
        for (int i=1;i<m-1;++i) {
            for (int j=1;j<n-1;++j) {
                if (!grid[i][j]) {
                    change(grid, i, j, m, n);
                    ++res;
                }
            }
        }
        return res;
    }
private:
    void change(vector<vector<int>>& grid, int x, int y, const int& m, const int& n) {
        if (x<0 || y<0 || x>=m || y>=n || grid[x][y]) return;
        grid[x][y] = 1;
        
        change(grid, x+1, y, m, n);
        change(grid, x-1, y, m, n);
        change(grid, x, y+1, m, n);
        change(grid, x, y-1, m, n);
    }
};