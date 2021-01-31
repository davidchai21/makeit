class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i=0;i<n/2;++i) {
            for (int j=0;j<n/2;++j) {
                int cur = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = cur;
            }
        }
        if (n%2) {
            for (int i=0;i<n/2;++i) {
                int cur = matrix[i][n/2];
                matrix[i][n/2] = matrix[n/2][i];
                matrix[n/2][i] = matrix[n-1-i][n/2];
                matrix[n-1-i][n/2] = matrix[n/2][n-1-i];
                matrix[n/2][n-1-i] = cur;
            }
        }
    }
};

// Better -> Reverse on diagonal and reflect left/right

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i=0;i<n;++i) {
            for (int j=i+1;j<n;++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i=0;i<n;++i) {
            for (int j=0;j<n/2;++j) {
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
    }
};