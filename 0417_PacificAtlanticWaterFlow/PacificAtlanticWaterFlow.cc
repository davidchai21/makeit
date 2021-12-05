class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        int m = matrix.size();
        if (!m) return res;
        int n = matrix[0].size();
        if (!n) return res;
        
        vector<vector<bool>> p(m, vector<bool>(n, false));
        vector<vector<bool>> a(m, vector<bool>(n, false));
        queue<pair<int,int>> qp, qa;
        for (int i=0;i<m;++i) {
            p[i][0] = true;
            qp.push(make_pair(i,0));
            a[i][n-1] = true;
            qa.push(make_pair(i, n-1));
        }
        for (int i=0;i<n;++i) {
            p[0][i] = true;
            qp.push(make_pair(0, i));
            a[m-1][i] = true;
            qa.push(make_pair(m-1, i));
        }
        while (!qp.empty()) {
            int x = qp.front().first;
            int y = qp.front().second;
            qp.pop();
            for (int i=0;i<4;++i) {
                int _x = x+dir[i];
                int _y = y+dir[i+1];
                if (_x >= 0 && _y>=0 && _x<m && _y<n && !p[_x][_y] && matrix[_x][_y]>=matrix[x][y]) {
                    qp.push(make_pair(_x, _y));
                    p[_x][_y] = true;
                }
            }
        }
        while (!qa.empty()) {
            int x = qa.front().first;
            int y = qa.front().second;
            qa.pop();
            for (int i=0;i<4;++i) {
                int _x = x+dir[i];
                int _y = y+dir[i+1];
                if (_x >= 0 && _y>=0 && _x<m && _y<n && !a[_x][_y] && matrix[_x][_y]>=matrix[x][y]) {
                    qa.push(make_pair(_x, _y));
                    a[_x][_y] = true;
                }
            }
        }
        
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                if (p[i][j] && a[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }
private:
    vector<int> dir = {-1,0,1,0,-1};
};