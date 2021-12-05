class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> table(m, vector<int>(n, 0));
        vector<pair<int,int>> q;
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                if (grid[i][j] == 'W') table[i][j] = -2;
                else if (grid[i][j] == 'E') {
                    table[i][j] = -1;
                    q.push_back(make_pair(i, j));
                }
            }
        }
        
        int res = 0;
        for (pair<int,int>& cur : q) {
            int x = cur.first;
            int y = cur.second;
            while (x>=0) {
                if (grid[x][y] == 'W') break;
                else if (grid[x][y] == '0') {
                    res = max(res, ++table[x][y]);
                }
                --x;
            }
            x = cur.first;
            while (x<m) {
                if (grid[x][y] == 'W') break;
                else if (grid[x][y] == '0') res = max(res, ++table[x][y]);
                ++x;
            }
            x = cur.first;
            while (y>=0) {
                if (grid[x][y] == 'W') break;
                else if (grid[x][y] == '0') res = max(res, ++table[x][y]);
                --y;
            }
            y = cur.second;
            while (y<n) {
                if (grid[x][y] == 'W') break;
                else if (grid[x][y] == '0') res = max(res, ++table[x][y]);
                ++y;
            }
        }
        return res;
    }
};

// DP: O(mn)

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int rowHit = 0;
        vector<int> colHit(n, 0);
        int res = 0;
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                if (!j || grid[i][j-1] == 'W') {
                    rowHit = 0;
                    for (int k=j;k<n && grid[i][k] != 'W';++k) {
                        rowHit += grid[i][k] == 'E';
                    }
                }
                if (!i || grid[i-1][j] == 'W') {
                    colHit[j] = 0;
                    for (int k=i;k<m && grid[k][j] != 'W'; ++k) {
                        colHit[j] += grid[k][j] == 'E';
                    }
                }
                if (grid[i][j] == '0') {
                    res = max(res, rowHit + colHit[j]);
                }
            }
        }
        return res;
    }
};