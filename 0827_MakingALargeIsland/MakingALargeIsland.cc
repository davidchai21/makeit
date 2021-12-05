class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        const int n = grid.size();
        
        int target = 2;
        int res = 0;
        for (int i=0;i<n;++i) {
            for (int j=0;j<n;++j) {
                if (grid[i][j] == 1) {
                    bfs(grid, target, i, j, n, res);
                    ++target;
                }
            }
        }
        
        for (int i=0;i<n;++i) {
            for (int j=0;j<n;++j) {
                if (!grid[i][j]) {
                    unordered_set<int> nb;
                    for (int k=0;k<4;++k) {
                        int x = i+dir[k];
                        int y = j+dir[k+1];
                        if (x<0 || y<0 || x>=n || y>=n || !grid[x][y]) continue;
                        nb.insert(grid[x][y]);
                    }
                    
                    int ans = 1;
                    for (auto it = nb.begin(); it != nb.end(); ++it) {
                        ans += m[*it];
                    }
                    res = max(ans, res);
                }
            }
        }
        return res;
    }
private:
    unordered_map<int, int> m;
    
    vector<int> dir = {0, -1, 0, 1, 0};
    
    void bfs(vector<vector<int>>& grid, int target, int x, int y, const int& n, int& res) {
        queue<pair<int,int>> q;
        q.push({x, y});
        int count = 1;
        grid[x][y] = target;
        while (!q.empty()) {
            int _x = q.front().first;
            int _y = q.front().second;
            q.pop();
            
            for (int i=0;i<4;++i) {
                int a = _x + dir[i];
                int b = _y +dir[i+1];
                if (a<0 || b<0 || a>=n || b>=n || grid[a][b] != 1) continue;
                
                ++count;
                grid[a][b] = target;
                q.push({a, b});
            }
        }
        m[target] = count;
        res = max(count, res);
    }
};