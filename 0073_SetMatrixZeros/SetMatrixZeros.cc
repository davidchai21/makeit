class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool f_row = false, f_col = false;
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                if (!matrix[i][j]) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                    if (j == 0) f_col = true;
                    if (i == 0) f_row = true;
                }
            }
        }
        
        for (int i=m-1;i>=1;--i) {
            if (!matrix[i][0]) {
                for (int j=1;j<n;++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i=n-1;i>=1;--i) {
            if (!matrix[0][i]) {
                for (int j=1;j<m;++j) {
                    matrix[j][i] = 0;
                }
            }
        }
        if (f_row) {
            for (int i=0;i<n;++i) matrix[0][i] = 0;
        }
        if (f_col) {
            for (int i=0;i<m;++i) matrix[i][0] = 0;
        }
    }
};