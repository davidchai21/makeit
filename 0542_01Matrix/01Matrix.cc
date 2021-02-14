class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (!m) return matrix;
        int n = matrix[0].size();
        if (!n) return matrix;
        vector<vector<int>> res(m, vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                if (!matrix[i][j]) {
                    res[i][j] = 0;
                    q.emplace(i,j);
                }
            }
        }
        
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i=0;i<4;++i) {
                int _x = x+dir[i];
                int _y = y+dir[i+1];
                if (_x>=0 && _y>=0 && _x<m && _y<n && res[_x][_y] > res[x][y]+1) {
                    res[_x][_y] = res[x][y] + 1;
                    q.emplace(_x, _y);
                }
            }
        }
        return res;
    }
private:
    vector<int> dir = {-1,0,1,0,-1};
};

// Better -- DP solution:

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (!m) return matrix;
        int n = matrix[0].size();
        if (!n) return matrix;
        vector<vector<int>> res(m, vector<int>(n, 100000));
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                if (!matrix[i][j]) {
                    res[i][j] = 0;
                } else {
                    if (i) res[i][j] = min(res[i][j], res[i-1][j]+1);
                    if (j) res[i][j] = min(res[i][j], res[i][j-1]+1);
                }
            }
        }
        for (int i=m-1;i>=0;--i) {
            for (int j=n-1;j>=0;--j) {
                if (matrix[i][j]) {
                    if (i<m-1) res[i][j] = min(res[i][j], res[i+1][j]+1);
                    if (j<n-1) res[i][j] = min(res[i][j], res[i][j+1]+1);
                }
            }
        }
        return res;
    }
};