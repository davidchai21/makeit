class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int m = M.size();
        if (!m) return 0;
        int n = M[0].size();
        if (!n) return 0;
        vector<int> diagonal(n, 0), anti(n, 0);
        vector<int> row(n, 0);
        int res = 0;
        for (int i=0;i<m;++i) {
            int r = 0;
            for (int j=0;j<n;++j) {
                if (M[i][j]) {
                    ++row[j];
                    ++r;
                } else {
                    row[j] = 0;
                    r = 0;
                }
                res = max(res, max(r, row[j]));
                
                // anti:
                if (j < n-1) {
                    if (M[i][j]) {
                        anti[j] = anti[j+1]+1;
                    } else {
                        anti[j] = 0;
                    }
                } else {
                    anti[j] = M[i][j];
                }
                
                // diagonal:
                if (j < n-1) {
                    if (M[i][n-1-j]) {
                        diagonal[n-1-j] = diagonal[n-j-2]+1;
                    } else {
                        diagonal[n-1-j] = 0;
                    }
                } else {
                    diagonal[0] = M[i][0];
                }
                res = max(res, max(diagonal[j], anti[j]));
            }
        }
        return res;
    }
};