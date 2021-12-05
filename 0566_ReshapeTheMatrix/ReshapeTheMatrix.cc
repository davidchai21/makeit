class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat.front().size();
        if (m*n != r*c) return mat;
        
        vector<vector<int>> res(r, vector<int>(c));
        int x = 0, y = 0;
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                res[x][y] = mat[i][j];
                if (++y == c) {
                    ++x;
                    y = 0;
                }
            }
        }
        return res;
    }
};