class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<string> s;
        int m = grid.size();
        int n = grid[0].size();
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                if (grid[i][j]) {
                    string str = "";
                    helper(grid, str, i, j, m, n, i, j);
                    s.insert(str);
                }
            }
        }
        return s.size();
    }
private:
    vector<int> dir = {1, 0, -1, 0, 1};
    void helper(vector<vector<int>>& grid, string& s, int x, int y, int m, int n, int bx, int by) {
        grid[x][y] = 0;
        s += to_string(x-bx) + "," + to_string(y-by) + "|";
        
        for (int i=1;i<5;++i) {
            int _x = x+dir[i-1];
            int _y = y+dir[i];
            if (_x>=0 && _y>=0 && _x<m && _y<n && grid[_x][_y]) helper(grid, s, _x, _y, m, n, bx, by);
        }
    }
};

// Another:

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        unordered_set<string> s;
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                if (grid[i][j]) {
                    string str = "";
                    helper(grid, str, i, j, m, n, 'S');
                    s.insert(str);
                }
            }
        }
        return s.size();
    }
private:
    void helper(vector<vector<int>>& grid, string& s, int x, int y, int m, int n, char d) {
        if (x<0 || y<0 || x>=m || y>=n || !grid[x][y]) return;
        grid[x][y] = 0;
        s.push_back(d);
        
        helper(grid, s, x+1, y, m, n, 'D');
        helper(grid, s, x-1, y, m, n, 'U');
        helper(grid, s, x, y+1, m, n, 'R');
        helper(grid, s, x, y-1, m, n, 'L');
        s.push_back('*');
    }
};