class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (!m) return {};
        int n = matrix[0].size();
        if (!n) return {};
        vector<int> res(m*n);
        vector<vector<int>> t(m+n-1,vector<int>());
        for (int k=0;k<m+n-1;++k) {
            int x = min(m-1,k);
            for (int y = k-x;x>=0 && y<n;--x, ++y) {
                t[k].push_back(matrix[x][y]);
            }
        }
        int index = 0;
        for (int i=0;i<m+n-1;++i) {
            if (i%2) {
                for (auto it = t[i].rbegin(); it != t[i].rend();++it) res[index++] = *it;
            } else {
                for (auto it = t[i].begin(); it != t[i].end();++it) res[index++] = *it;
            }
        }
        return res;
    }
};

// Better:

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (!m) return {};
        int n = matrix[0].size();
        if (!n) return {};
        vector<int> res(m*n);
        int index = 0;
        for (int k=0;k<m+n-1;++k) {
            if (k%2) {
                int y = min(k,n-1);
                for (int x = k-y;y>=0&&x<m;--y,++x) res[index++] = matrix[x][y];
            } else {
                int x = min(m-1, k);
                for (int y = k-x;x>=0&&y<n;--x,++y) res[index++] = matrix[x][y];
            }
        }
        return res;
    }
};