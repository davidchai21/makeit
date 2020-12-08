class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n,0));
        int i=1;
        int di = 0;
        int x=0,y=0;
        while (i<=n*n) {
            res[x][y] = i++;
            if (!isValid(res, x+dir[di].first, y+dir[di].second, n)) di = (di+1)%4;
            x += dir[di].first;
            y += dir[di].second;
        }
        return res;
    }
private:
    vector<pair<int,int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    bool isValid(vector<vector<int>>& res, int x, int y, int n) {
        if (x<0 || y<0 || x>=n || y>=n || res[x][y]) return false;
        return true;
    }
};

// Another way:

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n,0));
        int i=1;
        int k=0;
        while (i<=n*n) {
            int j=k;
            for (;j<n-k;++j) {
                res[k][j] = i++;
            }
            j=k+1;
            for (;j<n-1-k;++j) {
                res[j][n-1-k] = i++;
            }
            j=n-1-k;
            for (;j>k;--j) {
                res[n-1-k][j] = i++;
            }
            j=n-1-k;
            for (;j>k;--j) {
                res[j][k] = i++;
            }
            ++k;
        }
        return res;
    }
};