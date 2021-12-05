class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        unordered_map<int, unordered_map<int, int>> row, col;
        int m = mat1.size(), k = mat1[0].size(), n = mat2[0].size();
        for (int i=0;i<m;++i) {
            for (int j=0;j<k;++j) {
                if (mat1[i][j]) {
                    row[i][j] = mat1[i][j];
                }
            }
        }
        for (int i=0;i<k;++i) {
            for (int j=0;j<n;++j) {
                if (mat2[i][j]) {
                    col[j][i] = mat2[i][j];
                }
            }
        }
        
        vector<vector<int>> res(m, vector<int>(n,0));
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                int t = 0;
                for (auto it = row[i].begin(); it!=row[i].end(); ++it) {
                    if (col[j].find(it->first) != col[j].end()) {
                        t += it->second*col[j][it->first];
                    }
                }
                res[i][j] = t;
            }
        }
        return res;
    }
};