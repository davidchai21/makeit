class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i=0;i<n;++i) {
            for (int j=1;j<m;++j) {
                if (matrix[j-1][i] && matrix[j][i]) matrix[j][i] += matrix[j-1][i];
            }
        }
        
        int res = 0;
        for (int i=0;i<m;++i) {
            sort(matrix[i].begin(), matrix[i].end(), greater<int>());
            for (int j=0;j<n;++j) {
                if (!matrix[i][j]) break;
                res = max(matrix[i][j]*(j+1), res);
            }
        }
        return res;
    }
};