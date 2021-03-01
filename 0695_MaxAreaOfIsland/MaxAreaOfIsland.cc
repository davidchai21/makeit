// BFS:

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size();
        if (!m) return res;
        int n = grid[0].size();
        if (!n) return res;
        
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                if (grid[i][j]) {
                    helper(grid, i, j, m, n, res);
                }
            }
        }
        return res;
    }
private:
    vector<int> dir = {1,0,-1,0,1};
    
    void helper(vector<vector<int>>& grid, int& x0, int& y0, int& m, int& n, int& res) {
        queue<pair<int,int>> q;
        q.push(make_pair(x0, y0));
        int count = 1;
        grid[x0][y0] = 0;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i=0;i<4;++i) {
                int _x = x+dir[i];
                int _y = y+dir[i+1];
                if (_x>=0 && _y>=0 && _x<m && _y<n && grid[_x][_y]) {
                    grid[_x][_y] = 0;
                    ++count;
                    q.push(make_pair(_x, _y));
                }
            }
        }
        res = max(res, count);
    }
};

// DFS:

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size();
        if (!m) return res;
        int n = grid[0].size();
        if (!n) return res;
        
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                if (grid[i][j]) {
                    int count = 0;
                    dfs(grid, i, j, count, m, n);
                    res = max(res, count);
                }
            }
        }
        return res;
    }
private:
    vector<int> dir = {1,0,-1,0,1};
    
    void dfs(vector<vector<int>>& grid, const int& x, const int& y, int& count, const int& m, const int& n) {
        if (x<0 || y<0 || x>=m || y>=n || !grid[x][y]) return;
        ++count;
        grid[x][y] = 0;
        
        dfs(grid, x+1, y, count, m, n);
        dfs(grid, x-1, y, count, m, n);
        dfs(grid, x, y+1, count, m, n);
        dfs(grid, x, y-1, count, m, n);
    }
};