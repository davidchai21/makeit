class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        record.resize(matrix.size());
        int m = matrix.size(), n = matrix[0].size();
        for (int i=0;i<m;++i) {
            record[i].resize(n, 0);
            record[i][0] = matrix[i][0];
            for (int j=1;j<n;++j) {
                record[i][j] = record[i][j-1] + matrix[i][j];
            }
        }
        for (int j=0;j<n;++j) {
            for (int i=1;i<m;++i) {
                record[i][j] += record[i-1][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return record[row2][col2] - (row1 ? record[row1-1][col2] : 0) - (col1 ? record[row2][col1-1] : 0) + (row1 && col1 ? record[row1-1][col1-1] : 0);
    }
private:
    vector<vector<long>> record;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

// Shorter:

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        record.resize(m+1, vector<long>(n+1, 0L));
        for (int i=1;i<=m;++i) {
            for (int j=1;j<=n;++j) {
                record[i][j] = record[i-1][j]+record[i][j-1]-record[i-1][j-1]+matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return record[row2+1][col2+1] - record[row1][col2+1] - record[row2+1][col1] + record[row1][col1];
    }
    
private:
    vector<vector<long>> record;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */